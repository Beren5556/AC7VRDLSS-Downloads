# AC7VRDLSS 0.8.5

Complete ACE COMBAT 7 UEVR profile with NVIDIA DLSS/DLAA/Neural, the external overlay, View & Clouds and optional HF8.

**[Download Ace7Game.zip](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v0.8.5/Ace7Game.zip)**

Keep the exact filename `Ace7Game.zip`. The archive contains the profile files and subdirectories directly, without an `Ace7Game/` wrapper. GitHub's automatic Source code archives are not installable profiles.

## Release note

Internal OFXR dependencies have been removed. From now on, OFXR must be used externally.

## Installation

1. Close AC7 and UEVR normally. Keep any recovery copy outside the active profile.
2. **Manually delete the previous Ace7Game profile before importing. Do not merge folders or restore old configuration files.**
3. Use [UEVR Nightly 01143, exact revision 4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d](https://github.com/praydog/UEVR-nightly/releases/tag/nightly-01143-4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d).
4. Import `Ace7Game.zip` with UEVR Import Config, then start AC7 and inject normally. No setup script, host.ini or separate launcher is required. Python/Pillow and Node/Playwright are included; Microsoft Edge must already be installed.
5. Keep Menu Window Mode enabled. Optional HF8 instructions: [English](docs/HF8-INSTALL-EN.md) / [Spanish](docs/HF8-INSTALL-ES.md). SimHub is only required for haptics; HF8 is off by default.

## Controls

F10 toggles the overlay. Hold both index triggers and both grips for two seconds to open it with compatible controller actions; release to rearm. Right aim/trigger/stick or supported trackpad operates the panel. Close hides it; Log shows system/runtime information.

Apply submits the draft; Apply and save also requests persistence. Resolution selection and actual presented dimensions are separate. External changes synchronize with a clean draft; conflicting drafts must be reviewed or discarded. The original NVIDIA_DLSS UEVR panel remains available. Overlay startup preference takes effect next session.

[Parameters](docs/CONFIGURATION.md), [overlay troubleshooting](docs/OVERLAY_0.8.5.md), [View & Clouds controls](docs/VIEW_CLOUDS_0.8.4.md).

## Scope and licenses

The corrected complete profile was accepted in a local integration test on 2026-10-07. This is not an FPS benchmark or certification of every headset, mission, aircraft or UEVR nightly. Cloud mode A remains the default workaround; Original/A/B and optional F5 aircraft visibility remain available.

[MIT](LICENSE), [third-party notices](THIRD_PARTY.md) and [distribution terms](docs/DISTRIBUTION.md) apply. Bundled runtimes retain their licenses. Required Lua/HTML/JavaScript and third-party runtime components are included; original native and Python development sources remain private. No vendor endorsement. Previous releases remain unchanged.
