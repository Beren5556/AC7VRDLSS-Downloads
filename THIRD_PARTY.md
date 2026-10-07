# Third-party components and credits

The root MIT license covers original AC7VRDLSS code and documentation only. It does not replace the licenses or notices of the components below, inherited code, profile scripts, SDKs, or binary runtimes.

## Other components

- UEVR by praydog and contributors; API header and license under `third_party/uevr`.
- Pande's ACE COMBAT 7 profile and its existing scripts and companion-mod integrations; included profile sources retain their original attribution.
- MinHook by Tsuda Kageyu and contributors; license under `third_party/minhook`.
- JSON for Modern C++ by Niels Lohmann and contributors; license included in the vendored header.
- Khronos OpenXR headers; license texts under `third_party/openxr/LICENSES`.
- DLSSNR Cost Scaler and the Neural feeder; licenses included alongside their source and runtime payload.
- NVIDIA DLSS runtime and SDK components retain NVIDIA's applicable terms. No general project license replaces third-party terms.

MinHook uses its included BSD-style license; nlohmann/json, the Neural feeder and DLSSNR Cost Scaler retain their included MIT notices. The UEVR API carries its own upstream notice; the root MIT license does not grant additional rights to it. Pande's profile and companion scripts retain their authorship and original terms; no MIT relicensing of those files is asserted.

This repository is a community integration and is not endorsed by NVIDIA. The release contains plug-in-local runtime components; their notices are extracted with the plug-in. Vendor binaries are not made MIT-licensed by inclusion in this project.

## Notices in the installed profile

`NVIDIA_DLSS/LICENSE` contains the MIT license for the original integration, copyright (c) 2026 Beren5556. `NVIDIA_DLSS/THIRD_PARTY.md` contains these credits. The release also includes full license texts in `NVIDIA_DLSS/licenses`; the private runtime extracts its component notices alongside the corresponding files.


## AC7 Haptics 0.8

The optional AC7 telemetry DLL and its HF8 panel, effects and documentation are original integration additions under the root MIT license. The UEVR API notice is included at `AC7_Haptics/licenses/UEVR-API-LICENSE.txt` in the HF8 profile. SimHub and Next Level Racing hardware are external products, not bundled or relicensed. See [distribution terms](docs/DISTRIBUTION.md) for scope, source-distribution policy and complete credits.


## ExternalOverlayXR 0.1.1 / AC7 0.8.5

The public profile includes the original executable Python host as CPython 3.12 bytecode, required HTML/JavaScript/Lua runtime assets, CPython 3.12.14, Pillow 12.3.0, Node 24.19.0 and Playwright/Core 1.62.1. Original buildable C++ and Python host source remain in the private repositories. Third-party runtime source/bytecode retains its own license. Full Python, Pillow and Node/Playwright notices are included under ExternalOverlay/runtime and ExternalOverlay/THIRD_PARTY.md in Ace7Game.zip. Microsoft Edge must already be installed and is not redistributed. The complete profile keeps HF8 disabled by default.
