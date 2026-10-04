#include "xrfg/provider_api.hpp"

#include <openxr/openxr.h>
#include <openxr/openxr_loader_negotiation.h>

#include <windows.h>

#include <atomic>
#include <cstring>

namespace {

std::atomic_bool g_active{};

bool mode_is(const char* expected) noexcept {
    char value[32]{};
    const DWORD length = GetEnvironmentVariableA(
        "OFXR_BOOTSTRAP_STUB_MODE", value, static_cast<DWORD>(sizeof(value)));
    return length > 0 && length < sizeof(value) &&
           std::strcmp(value, expected) == 0;
}

XRAPI_ATTR XrResult XRAPI_CALL stub_get_instance_proc_addr(
    XrInstance, const char*, PFN_xrVoidFunction*) {
    return XR_ERROR_FUNCTION_UNSUPPORTED;
}

XRAPI_ATTR XrResult XRAPI_CALL stub_create_api_layer_instance(
    const XrInstanceCreateInfo*,
    const XrApiLayerCreateInfo*,
    XrInstance*) {
    return XR_ERROR_RUNTIME_FAILURE;
}

}  // namespace

extern "C" __declspec(dllexport) int OFXR_OptiScalerProviderV2(
    OFXR_OptiScalerProviderIdentityV2* identity) {
    if (identity == nullptr) return 0;
    *identity = {};
    identity->capabilities = OFXR_OPTISCALER_CAP_DLSS_GUIDES_V2;
    if (mode_is("incompatible")) {
        identity->magic = 0;
    }
    return 1;
}

extern "C" __declspec(dllexport) int OFXR_SetEmbeddedLayerActiveV1(int active) {
    g_active.store(active != 0, std::memory_order_release);
    return 1;
}

extern "C" __declspec(dllexport) int OFXR_BootstrapStubActiveV1() {
    return g_active.load(std::memory_order_acquire) ? 1 : 0;
}

extern "C" __declspec(dllexport) XRAPI_ATTR XrResult XRAPI_CALL
xrNegotiateLoaderApiLayerInterface(
    const XrNegotiateLoaderInfo*,
    const char*,
    XrNegotiateApiLayerRequest* request) {
    if (mode_is("failure")) {
        return XR_ERROR_INITIALIZATION_FAILED;
    }
    if (mode_is("seh")) {
        RaiseException(0xE0421001, 0, 0, nullptr);
        return XR_ERROR_RUNTIME_FAILURE;
    }
    request->layerInterfaceVersion = XR_CURRENT_LOADER_API_LAYER_VERSION;
    request->layerApiVersion = XR_MAKE_VERSION(1, 0, 0);
    request->getInstanceProcAddr = stub_get_instance_proc_addr;
    request->createApiLayerInstance = stub_create_api_layer_instance;
    return XR_SUCCESS;
}
