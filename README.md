# AC7VRDLSS 0.8.1 — two OFXR providers, optional HF8

Choose one complete Pande-based UEVR profile. Both variants contain the same NVIDIA_DLSS 0.8.1 renderer and both OFXR providers. HF8 components remain at their accepted 0.8 version.

| Download | Variant |
| --- | --- |
| [Ace7Game.zip — with HF8](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v 0.8.1/Ace7Game.zip) | Complete VR profile with HF8 haptics |
| [Ace7Game.zip — without haptics](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v 0.8.1-no-haptics/Ace7Game.zip) | Complete VR profile without HF8; no SimHub required |
| [AC7-HF8-SimHub.zip](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v 0.8.1/AC7-HF8-SimHub.zip) | Companion definition/effects for HF8 |

**Keep the exact filename Ace7Game.zip.** Each archive has one root folder, Ace7Game/. Use separate download folders for the variants and remove browser-added `(1)` suffixes. Do not import GitHub's automatically generated Source code ZIP. The companion release tag separates the two same-name assets; both are version 0.8.1.

## Install

1. Close AC7 and UEVR. Back up/move your existing Ace7Game profile outside `%APPDATA%/UnrealVRMod`; do not merge variants, because old haptics plug-ins would remain.
2. Use [UEVR Nightly 01143, exact revision 4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d](https://github.com/praydog/UEVR-nightly/releases/tag/nightly-01143-4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d).
3. Use UEVR **Import Config** on the selected Ace7Game.zip. No separate Pande profile, mod installer or global OFXR tray/layer installation is needed.
4. HF8 only: follow the [English](docs/HF8-INSTALL-EN.md) or [Spanish](docs/HF8-INSTALL-ES.md) guide for the SimHub definition/profile. Existing matching HF8 setups need no change. Public SimHub output starts disabled at 35% volume; enable and tune it during setup.
5. Start AC7 and inject normally. Keep Menu Window Mode enabled for the profile's automatic screen/VR switching.

## Controls and defaults

The NVIDIA_DLSS panel provides NONE/TAA/DLAA/DLSS/DLSS5-Neural, DLSS resolution 50–99%, presets, sharpness and separate Neural controls. OFXR Classic 0.2.1/V116 and OFXR Fork Djules75 0.2.10.1/V412 have separate settings and mutually exclusive enable checkboxes. Both unchecked means Off.

One action bar at the bottom: **Apply** applies changed render settings and stages OFXR; **Apply and save** also saves all groups for the next launch; **Discard** restores unsent edits. Every OFXR change requires a restart; it does not switch the loaded provider live. Generation is suspended outside controlled VR flight and requires valid stereo history when resuming. The red render label retains its immediate checkbox.

Defaults: DLSS Quality, scale0 (follow quality), both OFXR disabled, Neural-before-DLSS enabled, red label and diagnostic tracing disabled. The configuration file is `Ace7Game/NVIDIA_DLSS/settings.ini`, with named [OFXR_Classic] and [OFXR_Fork_Djules75] sections. See [all parameters](docs/CONFIGURATION.md). Fork3X requires PreferFPS; no multiplier guarantees the resulting FPS.

## Known limitations

The release was accepted after a coordinated AC7/HF8 test, with issues retained for follow-up. An isolated game abort occurred on the first right-eye DLSS5 pair after increasing Virtual Desktop resolution; a repeat at the same resolution succeeded. Switching between the game and desktop was reported to hide the OFXR counter and reduce perceived smoothness. Logs showed resumed generation and about seven seconds of Neural warm-up on returning to flight. These issues are not claimed fixed. No guaranteed FPS multiplier, performance benchmark, other-game validation or HF8 Pro validation is implied.

Earlier DLSS shader/pass-identification limitations remain. Starting in TAA with Neural and OFXR off, then selecting DLSS during controlled flight, is a suggested workaround, not a guaranteed fix. All OFXR setting changes require restarting the game.

## Terms, sources and credits

Original components retain [MIT](LICENSE). [Distribution terms](docs/DISTRIBUTION.md) and [third-party notices](THIRD_PARTY.md) apply. Public assets contain binaries and necessary runtime Lua, not our buildable integration source. Corresponding modified OFXR sources and build materials are available for [Classic](third_party/ofxr) and [Fork Djules75](third_party/ofxr-djules75), under LGPL-3.0-or-later. See [provider build instructions](docs/BUILDING_OFXR.md). Credit Pande, praydog/UEVR, tig3rmast3r, djules75 and the authors named in component notices. Independent community mod; no vendor endorsement.

[Previous 0.8 release](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/tag/v 0.8) remains unchanged. Checksums are attached separately to each variant release. Standard HF8 was tested with SimHub 9.12.9; other games, runtimes and UEVR versions require their own validation.
