# AC7VRDLSS

DLSS, DLAA and Neural rendering for ACE COMBAT 7 through the NVIDIA_DLSS UEVR plug-in, with optional OFXR frame generation.

The project uses game-specific adapters with shared rendering controls. **ACE COMBAT 7: SKIES UNKNOWN â€” Direct3D 11** is the first supported game.

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

**Download the required build:** [UEVR Nightly 01143 â€” official release](https://github.com/praydog/UEVR-nightly/releases/tag/nightly-01143-4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d). Download `UEVR.zip` from the release's **Assets** section. This link points to the exact required release, not a changing latest-version page.

UEVR, a working headset connection and an NVIDIA GPU compatible with the selected rendering features are required.

## Installation

1. Close ACE COMBAT 7 and UEVR.
2. Download and extract the exact **UEVR Nightly 01143** build linked above (revision `4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d`). Use its injector for this profile.
3. Back up your existing AC7 profile if needed, then **delete the entire `Ace7Game` folder** from `%APPDATA%\UnrealVRMod`. This clean import is required when replacing an existing profile.
4. Download [Ace7Game.zip](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v0.1-r37/Ace7Game.zip).
5. Open the specified UEVR injector, select **Import Config**, and choose `Ace7Game.zip`.
6. Start AC7 and inject with that same UEVR build as usual.

The ZIP contains the complete profile. It belongs in UEVR's profile storage, not in the UEVR installation directory or the game directory.

`Ace7Game.zip` contains the `Ace7Game` folder with the complete profile inside. Import our ZIP directly; no separate Pande profile is needed. Remove the previous AC7 profile before importing rather than merging the two profiles.

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

Original AC7VRDLSS integration code is available under the [MIT License](LICENSE). This grant does not relicense third-party code, the community profile, or vendor binaries.

The included modified OFXR provider retains **LGPL-3.0-or-later**. See its [source and build files](third_party/ofxr), [LGPL text](third_party/ofxr/LICENSE), [GPL text incorporated by the LGPL](third_party/ofxr/licenses/GPL-3.0-or-later.txt), and [dependency notices](third_party/ofxr/THIRD_PARTY.md). Upstream: [OFXR Bridge by tig3rmast3r and contributors](https://github.com/tig3rmast3r/OFXR-Bridge).

See [THIRD_PARTY.md](THIRD_PARTY.md) for component-specific terms and attribution. NVIDIA runtimes remain subject to NVIDIA's terms.

## Credits and third-party components

This is a community integration for UEVR. It is not an official NVIDIA product and does not imply NVIDIA endorsement.

Credit to **Pande** for the base ACE COMBAT 7 profile, and to the authors of its existing scripts and companion mods. UEVR and the included third-party components retain their original authorship and applicable licenses. Neural rendering uses a community integration; its availability and hardware requirements depend on the included runtime.
