# AC7VRDLSS — VR and optional HF8 haptics

**Release 0.8:** choose the complete VR profile with or without HF8. Both include the Pande base profile and the unchanged R37 renderer. No separate base-profile installation is needed.

| Download | Purpose |
| --- | --- |
| [Ace7Game.zip](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v0.1-r37/Ace7Game.zip) | Complete UEVR profile without haptics; no SimHub required. Byte-identical to R37. |
| [Ace7Game.zip](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v0.8/Ace7Game.zip) | Complete UEVR profile with AC7 Haptics 0.8. |
| [AC7-HF8-SimHub.zip](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v0.8/AC7-HF8-SimHub.zip) | Required companion for HF8: game definition, importable effects profile, guides and terms. |

**[English installation guide](docs/HF8-INSTALL-EN.md) · [Guía detallada en español](docs/HF8-INSTALL-ES.md) · [Terms and credits](docs/DISTRIBUTION.md) · [Checksums](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v0.8/SHA256SUMS.txt)**

Manual installation, no installer. Import one of the two VR ZIPs through UEVR **Import Config**. For HF8, also follow the guide to copy `AC7.simdef` and import `AC7-HF8.siprofile` in SimHub. Initial SimHub output is disabled and overall volume is 35%; enable and adjust it during setup. Installation is not repeated for each flight.

HF8 features include progressive throttle feedback, directional turns, roll sweeps, missiles, machine gun, alternating cloud rattle and available flare/damage/lightning/warning cues. The **HF8 Haptics** panel in UEVR controls each effect; SimHub controls overall volume and physical motor assignment. The standard HF8 was physically tested with SimHub 9.12.9 (licensed edition) and the exact UEVR build below. HF8 Pro is not yet validated. See the guide for input fallback and telemetry limitations.

The [previous R37 release](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/tag/v0.1-r37) remains available. This is a binary-distribution repository: our buildable mod source is not published. Required runtime Lua and the corresponding modified OFXR source remain included under their applicable terms.

DLSS, DLAA and Neural rendering for ACE COMBAT 7 through the NVIDIA_DLSS UEVR plug-in, with optional OFXR frame generation.

The project uses game-specific adapters with shared rendering controls. **ACE COMBAT 7: SKIES UNKNOWN — Direct3D 11** is the first supported game.

The download is a **complete ACE COMBAT 7 profile**, including the Pande base profile and its existing scripts, controls and companion-mod integrations. No separate Pande profile installation is required.

## Features

- DLSS Super Resolution with Quality, Balanced and Performance presets.
- Custom DLSS render scale from 50% to 99%.
- DLAA at native resolution.
- Neural rendering controls for scale, processing order, style and appearance.
- DLSS model/preset selection and sharpness adjustment.
- Optional OFXR frame generation with DLSS, DLAA or Neural.
- Automatic switching: game TAA outside controlled flight, selected rendering mode during controlled VR flight.
- An English-language NVIDIA_DLSS panel inside UEVR.
- Optional render-mode indicator.

## Compatibility

| Component | Supported configuration |
| --- | --- |
| Game | ACE COMBAT 7: SKIES UNKNOWN |
| Graphics API | Direct3D 11 |
| UEVR | Nightly 01143 |
| UEVR revision | `4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d` |
| Profile | Complete AC7 profile included in the release |

Use the specified UEVR build. Compatibility with other games or UEVR builds must be established separately.

**Download the required build:** [UEVR Nightly 01143 — official release](https://github.com/praydog/UEVR-nightly/releases/tag/nightly-01143-4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d). Download `UEVR.zip` from the release's **Assets** section. This link points to the exact required release, not a changing latest-version page.

UEVR, a working headset connection and an NVIDIA GPU compatible with the selected rendering features are required.

## Installation

1. Close ACE COMBAT 7 and UEVR.
2. Download and extract the exact **UEVR Nightly 01143** build linked above (revision `4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d`). Use its injector for this profile.
3. Move your existing `Ace7Game` folder from `%APPDATA%\UnrealVRMod` to a backup location outside that folder. This clean import prevents old plug-ins remaining active.
4. Download **Ace7Game.zip** or **Ace7Game.zip** from the table above.
5. Open the specified UEVR injector, select **Import Config**, and choose the downloaded VR ZIP. For HF8, also complete the linked SimHub installation guide.
6. Start AC7 and inject with that same UEVR build as usual.

The ZIP contains the complete profile. It belongs in UEVR's profile storage, not in the UEVR installation directory or the game directory.

Each VR ZIP contains the `Ace7Game` folder with the complete profile inside. Import our ZIP directly; no separate Pande profile is needed. Remove the previous AC7 profile before importing rather than merging the two profiles.

The plug-in extracts its private runtime files automatically. No manual temporal-AA changes to `Engine.ini` are required.

## Known issue and suggested workaround

Crashes have been reported on some systems when DLSS is activated. The integration may reject a rendering pass whose shader identity cannot be verified and request game closure. The cause is under investigation.

If you encounter a crash, try starting with **TAA**, **Neural disabled** and **OFXR disabled**. Once you are in controlled flight, select **DLSS** in the NVIDIA_DLSS panel and click **Apply**. Save TAA as the startup mode beforehand; changing OFXR requires a game restart. This workaround has not been verified for every system and may not resolve shader-identification failures. Automatic DLSS activation already waits for controlled flight.

## Default settings

| Setting | Default |
| --- | --- |
| VR rendering mode | DLSS |
| DLSS quality | Quality |
| Custom DLSS scale | Disabled; follows the quality preset |
| OFXR | Off |
| Neural before DLSS | On, when Neural is selected |
| Red render-mode indicator | Off |

## In-game controls

Open the **NVIDIA_DLSS** panel in UEVR. Depending on the interface view, it appears under **LuaLoader / Script UI**.

Choose your rendering mode and settings, then apply them. Use **Save startup settings** to keep your selection for the next session.

Changing OFXR on or off requires a **game restart**. Once enabled, generation is suspended outside controlled flight and can resume with compatible stereo frames during controlled VR flight.

Keep the included profile's **Menu Window Mode** enabled for automatic screen/VR switching.

## Configuration

The configuration file is `Ace7Game/NVIDIA_DLSS/settings.ini` within UEVR's profile storage.

```ini
[NVIDIA_DLSS]
StartupMode=DLSS
DLSSQuality=Quality
DLSSScaleBps=0
OFXREnabled=false
NeuralBeforeDLSS=true
TestLabel=false
```

`DLSSScaleBps=0` follows the selected quality preset. Values from `5000` to `9900` select a custom scale from 50.00% to 99.00%. DLAA uses native resolution.

## Performance

Frame-generation gains depend on the game, GPU, headset refresh rate and runtime. OFXR does not guarantee doubled FPS.

When comparing OFXR on and off, use the same scene and rendering settings. Keep other frame-generation systems, such as Virtual Desktop SSW, disabled for both comparison runs to isolate OFXR's effect.

## License

Original AC7VRDLSS integration and AC7 Haptics components retain the [MIT License](LICENSE). This download repository does not publish the buildable source of our mod. This grant does not relicense third-party code, the community profile, or vendor binaries.

The included modified OFXR provider retains **LGPL-3.0-or-later**. See its [source and build files](third_party/ofxr), [LGPL text](third_party/ofxr/LICENSE), [GPL text incorporated by the LGPL](third_party/ofxr/licenses/GPL-3.0-or-later.txt), and [dependency notices](third_party/ofxr/THIRD_PARTY.md). Upstream: [OFXR Bridge by tig3rmast3r and contributors](https://github.com/tig3rmast3r/OFXR-Bridge).

See [THIRD_PARTY.md](THIRD_PARTY.md) for component-specific terms and attribution. NVIDIA runtimes remain subject to NVIDIA's terms.

## Credits and third-party components

This is a community integration for UEVR. It is not an official NVIDIA product and does not imply NVIDIA endorsement.

Credit to **Pande** for the base ACE COMBAT 7 profile, and to the authors of its existing scripts and companion mods. UEVR and the included third-party components retain their original authorship and applicable licenses. Neural rendering uses a community integration; its availability and hardware requirements depend on the included runtime.

**Required ZIP name:** both profile downloads are named `Ace7Game.zip` and contain the complete `Ace7Game/` folder. Keep that exact name when importing; use separate download folders for the two variants and remove browser-added `(1)` suffixes. The table links to R37 without HF8 and 0.8 with HF8.
