# AC7VRDLSS 0.8.1

One complete UEVR profile including the Pande base profile, NVIDIA_DLSS, both OFXR providers and HF8 support. **HF8 haptics and both OFXR providers are disabled by default.**

**[Download Ace7Game.zip](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v0.8.1/Ace7Game.zip)** — includes the HF8 SimHub definition and effects profile in `Ace7Game/AC7_Haptics/SimHub/`.

Keep the exact filename `Ace7Game.zip`, with one root folder `Ace7Game/`. Remove browser-added `(1)` suffixes before importing. Do not import GitHub's automatic Source code archives.

## What's new in 0.8.1

- Added OFXR Fork Djules75 0.2.10.1 / V412 alongside OFXR Classic 0.2.1 / V116.
- Separate UEVR controls and named INI parameters for each provider, with mutually exclusive activation. Both default to Off.
- One shared Apply / Apply and save / Discard action bar for rendering and OFXR. OFXR changes require restarting the game.

## Install

1. Close AC7 and UEVR. Back up your existing Ace7Game profile outside `%APPDATA%/UnrealVRMod` before replacing it.
2. Use [UEVR Nightly 01143, revision 4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d](https://github.com/praydog/UEVR-nightly/releases/tag/nightly-01143-4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d).
3. Import `Ace7Game.zip` using UEVR **Import Config**. The full base profile is included.
4. Start AC7 and inject normally. Keep Menu Window Mode enabled for automatic screen/VR switching.
5. To use HF8, follow the [English](docs/HF8-INSTALL-EN.md) or [Spanish](docs/HF8-INSTALL-ES.md) guide, then check **HF8 enabled** in the UEVR HF8 Haptics panel and press **Apply and save**. SimHub is only needed when using haptics.

## Controls and defaults

The NVIDIA_DLSS panel provides NONE/TAA/DLAA/DLSS/DLSS5-Neural, DLSS resolution 50–99%, presets, sharpness and separate Neural controls. OFXR Classic 0.2.1/V116 and OFXR Fork Djules75 0.2.10.1/V412 have separate settings and mutually exclusive enable checkboxes. Both unchecked means Off.

One action bar at the bottom: **Apply** applies changed render settings and stages OFXR; **Apply and save** also saves all groups for the next launch; **Discard** restores unsent edits. Every OFXR change requires a restart; it does not switch the loaded provider live. Generation is suspended outside controlled VR flight and requires valid stereo history when resuming. The red render label retains its immediate checkbox.

Defaults: DLSS Quality, scale 0 (follow quality), both OFXR disabled, Neural-before-DLSS enabled, red label and diagnostic tracing disabled. The configuration file is `Ace7Game/NVIDIA_DLSS/settings.ini`, with named [OFXR_Classic] and [OFXR_Fork_Djules75] sections. See [all parameters](docs/CONFIGURATION.md). Fork 3X requires PreferFPS; no multiplier guarantees the resulting FPS.

## Terms, sources and credits

Original components retain [MIT](LICENSE). [Distribution terms](docs/DISTRIBUTION.md) and [third-party notices](THIRD_PARTY.md) apply. Public assets contain binaries and necessary runtime Lua, not our buildable integration source. Corresponding modified OFXR sources and build materials are available for [Classic](third_party/ofxr) and [Fork Djules75](third_party/ofxr-djules75), under LGPL-3.0-or-later. See [provider build instructions](docs/BUILDING_OFXR.md). Credit Pande, praydog/UEVR, tig3rmast3r, djules75 and the authors named in component notices. Independent community mod; no vendor endorsement.

[Previous 0.8 release](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/tag/v0.8) remains unchanged. Checksums are attached to the release. Standard HF8 was tested with SimHub 9.12.9; other games, runtimes and UEVR versions require their own validation.
