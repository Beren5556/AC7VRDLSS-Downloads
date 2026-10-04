# Corresponding OFXR source

The modified OFXR provider is supplied under LGPL-3.0-or-later. Its source, API headers, CMake files, LGPL/GPL texts and dependency notices are in `third_party/ofxr`. Khronos headers and notices are in `third_party/openxr`. This public repository distributes the complete profile and the required OFXR corresponding source, not the original integration C++ project.

Build on Windows x64 with Visual Studio C++ Build Tools, CMake 3.24 or newer, the AMD FidelityFX SDK v1.1.4 and NVIDIA Optical Flow SDK 5.0.7 identified in the provider notices. These SDKs are separate inputs under their original terms.

```powershell
cmake -S third_party/ofxr -B build-ofxr -A x64 -DXRFG_BUILD_TESTS=OFF -DXRFG_BUILD_STANDALONE=OFF -DXRFG_OPENXR_SDK_ROOT="D:/Sources/AC7VRDLSS-Downloads/third_party/openxr" -DXRFG_FIDELITYFX_SDK_ROOT="D:/SDKs/FidelityFX-SDK-v1.1.4/sdk" -DXRFG_NVIDIA_OPTICAL_FLOW_SDK_ROOT="D:/SDKs/Optical_Flow_SDK_5.0.7"
cmake --build build-ofxr --config Release --target XR_APILAYER_XRFrameBridge_diagnostic
```

The provider is a separate dynamically loaded DLL. Its layer/bridge API headers are included with the source. Preserve all component licenses when replacing or redistributing it.


## Fork Djules750.2.10.1/V412

Sources: third_party/ofxr-djules75, pinned provenance in AC7_INTEGRATION.json. Follow its docs/BUILDING.md for FidelityFX1.1.4 libraries and SDK inputs. Use the analogous command with -S third_party/ofxr-djules75 -B build-ofxr-djules75, setting XRFG_FIDELITYFX_SDK_ROOT and XRFG_NVIDIA_OPTICAL_FLOW_SDK_ROOT to your SDK locations. The source includes the required OpenXR/Vulkan headers; obtain the pinned OpenVR header if your checkout omits it. Build target XR_APILAYER_XRFrameBridge_diagnostic produces NVIDIA_DLSS_OFXR_DJULES75.dll. Do not use the standalone tray to integrate with this mod. The CMake wrapper only guards the optional private AC7 host-chain fixture when absent; provider source is identical to the release build. SDK paths/toolchain are not embedded into source requirements.
