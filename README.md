# AC7VRDLSS 0.8.3

Complete ACE COMBAT 7 UEVR profile with the accepted 0.8.3-r2 external overlay,
NVIDIA_DLSS, both OFXR providers and optional HF8. HF8 and both OFXR providers
are disabled by default. The native rendering DLL is unchanged from 0.8.2.

**[Download Ace7Game.zip](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v0.8.3/Ace7Game.zip)**

Keep that exact filename and the single `Ace7Game/` root when importing.
GitHub's automatic Source code archives are not installable profiles.

## What's new

- Automatic OpenXR overlay startup with controller gesture and F10 opening.
- Common controller profiles and headset/runtime information; priority Quest 2/Quest 3S and Pimax, Pico secondary.
- Log page separates information/diagnostics from controls.
- First output-resolution control with slider and +/-50 pixels per-eye width, shared Apply/save and external-edit synchronization.
- Hot output selection uses the same setting as UEVR 01143; selected dimensions and submitted views are shown separately.
- Bundled Python/Pillow and Node/Playwright host, independent of the developer's PC paths.

## Installation

1. Close AC7 and UEVR. Back up your existing Ace7Game profile outside `%APPDATA%/UnrealVRMod`; do not merge blindly with old installations.
2. Use [UEVR Nightly 01143, exact revision 4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d](https://github.com/praydog/UEVR-nightly/releases/tag/nightly-01143-4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d).
3. Import `Ace7Game.zip` using UEVR Import Config. The full base profile is included.
4. Run `%APPDATA%/UnrealVRMod/Ace7Game/ExternalOverlay/Setup-Overlay.cmd` **once after importing**. It checks the bundled host and installed Microsoft Edge, then creates local paths. Run it again if the profile moves. No separate Python/Node installation is needed.
5. Start AC7 and inject normally. The overlay starts automatically; there is no separate overlay launcher for later sessions. Keep Menu Window Mode enabled for the profile's screen/VR switching.
6. Optional HF8 setup: [English](docs/HF8-INSTALL-EN.md) / [Spanish](docs/HF8-INSTALL-ES.md). SimHub files are included under `AC7_Haptics/SimHub`; SimHub is only needed for haptics.

## Controls

F10 toggles the overlay. With compatible controller actions, hold both index
triggers and both grips for two seconds to open it, then release to rearm.
Right aim/trigger/stick or supported trackpad controls pointer/click/scroll.
Close hides the panel. Log shows headset/runtime/profiles and diagnostics.

Resolution +/- changes the draft by 50 pixels in per-eye width; height follows
the aspect ratio. Apply submits changes; Apply and save also requests startup
persistence. Actual presented dimensions remain separate from the selection.
Edits from the native UEVR menu synchronize when there is no unsaved draft.
Conflicting drafts must be reviewed/discarded; uncertain requests are not replayed.

The original NVIDIA_DLSS UEVR panel remains available. DLSS/DLAA/Neural and
Classic/Fork OFXR remain managed by their native implementation. All OFXR
changes still require restarting the game. The output-resolution option
does not itself require restarting. Change overlay startup in UEVR's External
overlay panel; that preference takes effect on the next game session.

## Validation and scope

30 offline cases passed on the exact layer/bridge artifacts, and the user
accepted a flight test on 2026-10-05. Portable-host UI/lifecycle tests also
passed. This is not an FPS benchmark or universal certification of every
headset, connection, UEVR nightly or game. The hot-resolution accessor is
strictly limited to the recorded 01143 backend identity.

Existing rendering/performance investigations remain separate. Cloud/horizon
artifacts reported with the basic UEVR profile are being researched separately;
this release does not claim to fix them. For setup and troubleshooting see
[overlay guide](docs/OVERLAY_0.8.3.md) and [parameters](docs/CONFIGURATION.md).

## Credits, licenses and source policy

Original components retain [MIT](LICENSE). Existing [third-party notices](THIRD_PARTY.md),
[distribution terms](docs/DISTRIBUTION.md), [Classic sources](third_party/ofxr),
[Fork sources](third_party/ofxr-djules75) and [provider build guide](docs/BUILDING_OFXR.md)
remain available. Bundled host runtimes carry their licenses under ExternalOverlay/runtime.
Microsoft Edge is required but not redistributed. Runtime HTML/JS/Lua are included
to execute the panel; native integration and Python development sources stay private.
Credit Pande, praydog, the OFXR authors and all component authors. No vendor endorsement.

[Previous public 0.8.1](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/tag/v0.8.1) remains unchanged. There was no public 0.8.2 release.
