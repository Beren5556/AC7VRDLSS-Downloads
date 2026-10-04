# Third-party components and credits

The root MIT license covers original AC7VRDLSS code and documentation only. It does not replace the licenses or notices of the components below, inherited code, profile scripts, SDKs, or binary runtimes.

## OFXR Bridge

Upstream: [tig3rmast3r/OFXR-Bridge](https://github.com/tig3rmast3r/OFXR-Bridge), by tig3rmast3r and contributors. The modified provider in `third_party/ofxr` remains under **LGPL-3.0-or-later**; AC7-specific provider modifications are covered by those same terms, not by the root MIT grant. Source and CMake build files are provided in that directory. Preserve its `LICENSE`, `licenses/GPL-3.0-or-later.txt`, and dependency notices when redistributing it.

OFXR dependencies include AMD FidelityFX (MIT), Khronos OpenXR headers (Apache-2.0 OR MIT), and NVIDIA Optical Flow interface headers (their included NVIDIA permission notice). See [the provider notices](third_party/ofxr/THIRD_PARTY.md) for versions and individual license files. NVIDIA's display-driver library is loaded from the installed driver and is not redistributed here.

## Other components

- UEVR by praydog and contributors; API header and license under `third_party/uevr`.
- Pande's ACE COMBAT 7 profile and its existing scripts and companion-mod integrations; included profile sources retain their original attribution.
- MinHook by Tsuda Kageyu and contributors; license under `third_party/minhook`.
- JSON for Modern C++ by Niels Lohmann and contributors; license included in the vendored header.
- Khronos OpenXR headers; license texts under `third_party/openxr/LICENSES`.
- OFXR and its dependencies; see `third_party/ofxr/THIRD_PARTY.md` and accompanying licenses.
- DLSSNR Cost Scaler and the Neural feeder; licenses included alongside their source and runtime payload.
- NVIDIA DLSS runtime and SDK components retain NVIDIA's applicable terms. No general project license replaces third-party terms.

MinHook uses its included BSD-style license; nlohmann/json, the Neural feeder and DLSSNR Cost Scaler retain their included MIT notices. The UEVR API carries its own upstream notice; the root MIT license does not grant additional rights to it. Pande's profile and companion scripts retain their authorship and original terms; no MIT relicensing of those files is asserted.

This repository is a community integration and is not endorsed by NVIDIA. The release contains plug-in-local runtime components; their notices are extracted with the plug-in. Vendor binaries are not made MIT-licensed by inclusion in this project.

## Notices in the installed profile

`NVIDIA_DLSS/LICENSE` contains the MIT license for the original integration, copyright (c) 2026 Beren5556. `NVIDIA_DLSS/THIRD_PARTY.md` contains these credits. The release also includes full license texts in `NVIDIA_DLSS/licenses`; the private runtime extracts its component notices alongside the corresponding files.

The corresponding modified OFXR source and build instructions for this release are available at https://github.com/Beren5556/AC7VRDLSS-Downloads/tree/v0.1-r37/third_party/ofxr . OFXR is a separate dynamically loaded library and retains LGPL-3.0-or-later. Its LGPL and incorporated GPL texts are supplied together.

## AC7 Haptics 0.8

The optional AC7 telemetry DLL and its HF8 panel, effects and documentation are original integration additions under the root MIT license. The UEVR API notice is included at `AC7_Haptics/licenses/UEVR-API-LICENSE.txt` in the HF8 profile. SimHub and Next Level Racing hardware are external products, not bundled or relicensed. See [distribution terms](docs/DISTRIBUTION.md) for scope, source-distribution policy and complete credits.


## OFXR Fork Djules75

The second provider is based on djules75/OFXR-Bridge 0.2.10.1 (V412), commit a1a4a2bf7b3307b7f4329c49870b158e5faaa45e, retaining LGPL-3.0-or-later. Its modified source is in [third_party/ofxr-djules75](third_party/ofxr-djules75), including notices for AMD, NVIDIA, Khronos and Valve headers. AC7 adaptations add private selection and host77 validity checks; no global tray installation is required.
