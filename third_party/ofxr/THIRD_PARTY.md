# OFXR third-party components

## Khronos OpenXR
Generated headers from OpenXR-SDK revision 5267613edf3d937e3d77556a106a65c2f82b25c6 (release-1.1.61), licensed under Apache-2.0 OR MIT. This repository provides the headers and license texts in ../openxr. Configure XRFG_OPENXR_SDK_ROOT when building the provider separately.

## AMD FidelityFX
Optical Flow uses FidelityFX SDK v1.1.4, commit c6efa6bf7f2027b3ec94f28578bb5965eabb9e55. Its DX12 backend and optical-flow components are linked statically. The AMD MIT notice is preserved in licenses/AMD-FidelityFX-MIT.txt. The SDK is a separate build input.

## NVIDIA Optical Flow
The provider uses the public D3D12 interface headers from NVIDIA Optical Flow SDK 5.0.7. The permission notice is preserved in licenses/NVIDIA-Optical-Flow-Headers.txt. The provider loads nvofapi64.dll from the installed display driver; it does not distribute that driver library. The SDK is a separate build input.

## License texts
The provider's LICENSE and licenses directory retain the applicable upstream terms. SDK tools and vendor runtimes retain their separate terms.
