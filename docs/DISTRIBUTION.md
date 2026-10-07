# Distribution, licenses and credits — 0.8.5

This repository distributes ready-to-use AC7 VR profiles, the optional HF8 runtime, SimHub definitions/effects and documentation. The original mod's buildable source, development project, tests and private configuration are not published. Lua scripts needed to execute the UEVR profile are necessarily included.

## Original work

The original AC7VRDLSS integration, AC7 Haptics additions and original documentation are covered by the existing [MIT License](../LICENSE), copyright 2026 Beren5556. Binary distribution does not remove that grant or relicense third-party work. Preserve applicable copyright and permission notices when redistributing. Software is supplied **as is, without warranty**, on the terms stated in that license.

## Third-party work

- **Pande and the original script/companion-mod authors:** the complete base AC7 UEVR profile. Their attribution and applicable terms are preserved; no new MIT grant is asserted over their work.
- **praydog and UEVR contributors:** UEVR and its plug-in API. The API's separate MIT notice accompanies the HF8 package. Obtain the exact required injector from the official release; it is not bundled here.
- **NVIDIA, Khronos, MinHook, nlohmann/json, Neural feeder and DLSSNR Cost Scaler contributors:** their runtimes/dependencies retain their own licenses. See [THIRD_PARTY.md](../THIRD_PARTY.md) and the complete notices inside the profile and extracted runtime. NVIDIA binaries are not made MIT-licensed by inclusion.
- **SimHub and Next Level Racing:** external software/hardware used by the optional haptic integration, not bundled or relicensed. The supplied `.simdef` and `.siprofile` describe this mod's telemetry and effects; acquire SimHub separately under its own terms.


This is an independent community project. ACE COMBAT, UEVR, NVIDIA, SimHub and HF8 names identify compatibility or credit; they do not imply affiliation, sponsorship or endorsement by their respective owners. The game, headset software, injector, SimHub license and hardware are not supplied by this release.

Physical acceptance covers the tested standard HF8 configuration with UEVR Nightly 01143 and SimHub 9.12.9. Other hardware/builds need separate validation. See the installation guide for supported effects, known limitations, backups and manual removal.



## External overlay 0.8.3

The public profile includes the original executable Python host as CPython 3.12 bytecode, required HTML/JavaScript/Lua runtime assets, CPython 3.12.14, Pillow 12.3.0, Node 24.19.0 and Playwright/Core 1.62.1. Original buildable C++ and Python host source remain in the private repositories. Third-party runtime source/bytecode retains its own license. Full Python, Pillow and Node/Playwright notices are included under ExternalOverlay/runtime and ExternalOverlay/THIRD_PARTY.md in Ace7Game.zip. Microsoft Edge must already be installed and is not redistributed. The complete profile keeps HF8 disabled by default.
