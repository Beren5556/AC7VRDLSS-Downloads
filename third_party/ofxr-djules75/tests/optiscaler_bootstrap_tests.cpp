#include <openxr/openxr.h>
#include <openxr/openxr_loader_negotiation.h>

#include <windows.h>

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace {

using IsActive = int (*)();

HMODULE owner_of(FARPROC address) {
    HMODULE owner = nullptr;
    if (address == nullptr ||
        !GetModuleHandleExW(
            GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
            reinterpret_cast<LPCWSTR>(address), &owner)) {
        return nullptr;
    }
    return owner;
}

}  // namespace

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "usage: xrfg_optiscaler_bootstrap_tests "
                     "<layer-dll> <stub-dll> <mode>\n";
        return EXIT_FAILURE;
    }

    const std::string mode = argv[3];
    if (!SetEnvironmentVariableA("OFXR_BOOTSTRAP_STUB_MODE", mode.c_str())) {
        return EXIT_FAILURE;
    }

    const std::filesystem::path directory =
        std::filesystem::temp_directory_path() /
        (L"ofxr-bootstrap-" + std::to_wstring(GetCurrentProcessId()));
    std::filesystem::create_directories(directory);
    const auto private_layer = directory /
        L"XR_APILAYER_XRFrameBridge_diagnostic.dll";
    std::filesystem::copy_file(
        argv[1], private_layer, std::filesystem::copy_options::overwrite_existing);

    const HMODULE stub = LoadLibraryA(argv[2]);
    const HMODULE layer = LoadLibraryW(private_layer.c_str());
    if (stub == nullptr || layer == nullptr) {
        std::cerr << "test module load failed\n";
        return EXIT_FAILURE;
    }

    const auto negotiate =
        reinterpret_cast<PFN_xrNegotiateLoaderApiLayerInterface>(
            GetProcAddress(layer, "xrNegotiateLoaderApiLayerInterface"));
    const auto is_active = reinterpret_cast<IsActive>(
        GetProcAddress(stub, "OFXR_BootstrapStubActiveV1"));
    if (negotiate == nullptr || is_active == nullptr) return EXIT_FAILURE;

    XrNegotiateLoaderInfo loader_info{};
    loader_info.structType = XR_LOADER_INTERFACE_STRUCT_LOADER_INFO;
    loader_info.structVersion = XR_LOADER_INFO_STRUCT_VERSION;
    loader_info.structSize = sizeof(loader_info);
    loader_info.minInterfaceVersion = 1;
    loader_info.maxInterfaceVersion = XR_CURRENT_LOADER_API_LAYER_VERSION;
    loader_info.minApiVersion = XR_MAKE_VERSION(1, 0, 0);
    loader_info.maxApiVersion = XR_CURRENT_API_VERSION;

    XrNegotiateApiLayerRequest request{};
    request.structType = XR_LOADER_INTERFACE_STRUCT_API_LAYER_REQUEST;
    request.structVersion = XR_API_LAYER_INFO_STRUCT_VERSION;
    request.structSize = sizeof(request);

    const XrResult result = negotiate(
        &loader_info, "XR_APILAYER_XRFrameBridge_diagnostic", &request);
    const bool expects_delegation = mode == "success";
    const HMODULE owner = owner_of(
        reinterpret_cast<FARPROC>(request.createApiLayerInstance));
    const HMODULE expected_owner = expects_delegation ? stub : layer;
    const bool correct_owner = owner == expected_owner;
    const bool correct_activation =
        is_active() == (expects_delegation ? 1 : 0);
    const bool passed = XR_SUCCEEDED(result) && correct_owner && correct_activation;

    FreeLibrary(layer);
    FreeLibrary(stub);
    std::error_code ignored;
    std::filesystem::remove_all(directory, ignored);
    if (!passed) {
        std::cerr << "bootstrap mode failed: " << mode
                  << " result=" << result
                  << " owner=" << correct_owner
                  << " actual_owner=" << owner
                  << " expected_owner=" << expected_owner
                  << " active=" << correct_activation << '\n';
        return EXIT_FAILURE;
    }
    std::cout << "bootstrap mode passed: " << mode << '\n';
    return EXIT_SUCCESS;
}
