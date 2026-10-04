# AC7 VR + HF8 0.8.1 — installation and use

This is a complete UEVR profile plus optional HF8 haptics. Installation is manual, once per PC; there is no installer. SimHub receives local telemetry from the included UEVR plug-in and drives the pad. You do not need to create a custom game or choose a fixed joystick button.

## Downloads and requirements

Get the assets from [release 0.8.1](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/tag/v 0.8.1).

| Your setup | Files to download |
| --- | --- |
| VR without haptics | [Ace7Game.zip — without HF8](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v 0.8.1-no-haptics/Ace7Game.zip) only |
| VR with HF8 | [Ace7Game.zip — with HF8](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/download/v 0.8.1/Ace7Game.zip) and `AC7-HF8-SimHub.zip` |

Both UEVR ZIPs are complete profiles including the Pande base profile. Choose one. Both variants include renderer 0.8.1; the version without HF8 does not require SimHub. The previous R37 release remains available.

- Windows, ACE COMBAT 7: SKIES UNKNOWN, Direct3D 11, and a working VR headset connection.
- **UEVR Nightly 01143**, revision `4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d`: [exact official release](https://github.com/praydog/UEVR-nightly/releases/tag/nightly-01143-4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d). Download its `UEVR.zip`. Other nightly versions are not validated.
- An NVIDIA GPU compatible with the rendering features you select. See the repository's rendering instructions and known issue below.
- For haptics: an HF8 connected by USB with its power supply, and [SimHub](https://www.simhubdash.com/). Validation used **SimHub 9.12.9, licensed edition, and the standard HF8**. HF8 Pro and other SimHub editions/versions have not been physically validated for this release.

## 1. Import the UEVR profile

1. Close AC7 and UEVR. Close SimHub while copying its definition later.
2. In File Explorer, paste `%APPDATA%\UnrealVRMod` into the address bar. If `Ace7Game` exists, move that whole folder to a backup location outside `UnrealVRMod`. This preserves your previous settings and avoids merging old plug-ins into the new profile.
3. Extract the specified UEVR build into its own folder. Run that build's injector.
4. Select **Import Config** and choose `Ace7Game.zip` (or `Ace7Game.zip` for the non-haptic version). Import the ZIP directly; do not extract it into the game or injector directory.
5. For the HF8 variant, check that `%APPDATA%\UnrealVRMod\Ace7Game` now contains `plugins\AC7_Telemetry.dll`, `scripts\HF8_Haptics.lua`, and `AC7_Haptics`.

The haptic package enables its local telemetry output. The SimHub profile initially disables the pad output, so you explicitly enable it in step 3. Both variants use the same renderer 0.8.1. Do not replace other games' profiles or modify global graphics settings.

## 2. Register AC7 in SimHub — one-time copy

1. Extract `AC7-HF8-SimHub.zip` to a folder you can find again.
2. With SimHub closed, paste `%LOCALAPPDATA%\SimHub` into File Explorer's address bar.
3. Inside it, create folders `ExternalSims`, then `Definitions`, then `AC7-HF8` if they do not already exist.
4. Copy `AC7.simdef` from the extracted download into that final folder. The exact final path is `%LOCALAPPDATA%\SimHub\ExternalSims\Definitions\AC7-HF8\AC7.simdef`. Avoid an extra nested ZIP folder or a hidden `.txt` suffix.
5. Start SimHub. Find/select **Ace Combat 7 - UEVR Telemetry** in its game list. This is the game definition supplied by the mod; you do not need Settings → Custom games.

This uses SimHub's supported [external-sim definition drop-in directory](https://manual.simhubdash.com/external-sim-integration). No registry editing, administrator command or account registration is involved. A copy of the definition is also included in the installed UEVR profile under `AC7_Haptics\SimHub`.

**Upgrading an earlier test installation:** registered `.simlink` definitions take priority over drop-in definitions with the same game ID. If the game is missing or still uses an old definition, close SimHub and inspect `%LOCALAPPDATA%\SimHub\ExternalSims\Registrations`. Back up and move only `b3a7c5b0-73ea-4e8e-8c1c-3877daf875b3.simlink` outside that folder, then restart SimHub with the drop-in definition in place. Leave other games' registrations alone.

## 3. Import the effects profile and enable HF8

1. Open **ShakeIt Motors** in SimHub, then **Profiles manager**.
2. Choose **Import profile** and select `AC7-HF8.siprofile` from the extracted SimHub download. Load **AC7 HF8 0.8**.
3. Keep the included output settings with this profile. If asked about common versus profile-specific output settings, keep them profile-specific so other games retain their settings.
4. Open **Motors Output** and locate **ForceFeel Pad / Next Level Racing HF8 Haptic Gaming Pad**. Connect and power the HF8; close any other application currently controlling the pad. Enable that output.
5. The profile starts at **35% overall volume**. Start there and adjust to your pad and preference. The reference physical test used 80%; this is a tuning reference, not a required setting. Do not set all effect sliders to the overall-volume value: they control a different level.
6. With AC7 selected, use SimHub's profile selection/association controls to retain this profile for **Ace Combat 7 - UEVR Telemetry**. Do not make it the profile for every game. If automatic selection does not retain it, load it manually before flying.

The profile contains 14 effects and eight motor channels. Its gains and motor assignments follow the accepted test configuration; only initial overall volume and output activation are reduced for first use. Channel indices 1/3/5/7 are left and 0/2/4/6 right. Use SimHub's individual output tests at a comfortable level to check your physical pad. If tests are silent, resolve power/USB/output selection before testing the game.

## 4. Fly and tune

Open SimHub, power the HF8, launch AC7 and inject with the specified UEVR build. Enter a mission in immersive VR and take control of the aircraft. Silence in the menu, pause and cinematics is expected. Desktop/2D-screen mode is not a supported haptic test.

Open **HF8 Haptics** in UEVR (under LuaLoader / Script UI where applicable). **Apply** changes the current session; **Apply and save** also saves the controls for the next session. Wait for the panel's confirmation. Setting an effect's intensity to zero disables it. **HF8 enabled** switches the haptic effects globally.

| Control/effect | Behavior |
| --- | --- |
| Engine minimum / maximum / curve / smoothing | Progressive response to throttle input; defaults 18 / 32 / 80 / 250 ms. Engine vibration yields to other events. It is not measured engine thrust. |
| Turns | Vibration on the turning side, derived from movement; default 70. |
| Roll | Side-to-side sweep following roll direction; default 70, sweep 900 ms. |
| General maneuver | Symmetric motion cue, default 35; not measured aircraft G-force. |
| Missiles | Launch/ammunition-change pulse, default 90 for 400 ms. |
| Machine gun | Ammunition first, then automatic input fallback when ammunition data is unavailable; default 95. |
| Clouds | Alternating left/right rattle while inside a cloud; default intensity 150, producing pulses of 75. This is a designed texture, not measured turbulence. |
| Flares, damage, lightning | Event cues when their game data is available. Damage has no measured incoming-hit direction. |
| Missile warnings | Directional only with a valid threat direction; otherwise symmetric. |
| Reverse sides | Reverses directional effect interpretation. |

Use UEVR to change the response and strength of each cue. Use SimHub for overall volume, per-effect enable/gain and physical motor assignment. Adjust one layer at a time. You can disable individual effects in either interface without editing formulas. Avoid altering formulas unless you understand their stale-data and menu/pause guards.

The gun fallback reads your game's DirectInput joystick configuration automatically, matching the joystick product GUID and `Flight_Gun`. It supports Button1–32 and one button modifier. It does not cover keyboard-only mappings, XInput without the game's Joystick section, axes/POV or compound expressions. A held button is an approximation and cannot prove a shot occurred.

## Troubleshooting

| Symptom | Check |
| --- | --- |
| AC7 missing from SimHub | Exact definition path, restart SimHub, and old `.simlink` priority described above. |
| Output test silent | Power, USB, correct HF8 output enabled, output volume, and another pad-control application. |
| Output test works, flight silent | Correct game and profile selected; exact UEVR build; immersive controlled flight; HF8 enabled in UEVR; matching 0.8 DLL, `.simdef` and profile. |
| Still silent | In `%APPDATA%\UnrealVRMod\Ace7Game\AC7_Haptics\AC7_Haptics.ini`, both `Enabled` and `OutputEnabled` must be `1`. Restart the game after changing this file. Local telemetry uses UDP port 29777; check for a conflicting receiver or local security blocking it. Do not expose the port to the internet. |
| Very weak output | Raise the SimHub profile's overall volume gradually. If only one effect is weak, adjust that effect in UEVR or SimHub. The engine deliberately has a lower ceiling. |
| Gun alone is silent | Check whether the configured controller falls within the fallback limits above; no fixed personal button is required. |
| Cloud effect has no left/right motion | Reimport the matching 0.8 profile/definition and check the cloud effect's separate left/right assignments. Do not use an earlier alpha profile. |
| Vibration stops on pause or a lost signal | Expected: menu/pause and stale-data guards silence the output. |
| DLSS crash | The renderer has a known shader/pass-identification issue on some systems. Try startup TAA with Neural and OFXR off; select DLSS after entering controlled flight. This is a suggested workaround, not a confirmed fix for every system. Changing OFXR requires a restart. |

For support, use this repository's [Issues](https://github.com/Beren5556/AC7VRDLSS-Downloads/issues). Include the mod version, UEVR revision, SimHub version, HF8 model, controller type and steps to reproduce. Remove personal paths or identifying information from any log you choose to share.

## Updates, removal and terms

You do **not** repeat installation for each flight. Back up UEVR settings and export your tuned SimHub profile before an update. Update the probe, definition and effects profile together; protocol revisions can make old profiles silent. Reapply only the personal settings you need after comparing versions.

To return to the non-haptic variant, close the applications, back up/move the whole AC7 UEVR profile outside its storage folder, then import `Ace7Game.zip`. A clean switch prevents an old haptic DLL remaining loaded. You may also remove just the AC7-HF8 definition folder and its SimHub effects profile. Leave other games' profiles intact. Restoring your previous full backup is another rollback option.

The original integration is supplied under the MIT license, as-is without warranty. The public distribution excludes the buildable source of our mod. Necessary runtime Lua scripts remain included; modified OFXR source/build materials are supplied under its LGPL terms in the repository. Existing third-party notices and licenses remain applicable. This is an independent community mod, not an official product of Bandai Namco, NVIDIA, SimHub or Next Level Racing. See the release's [terms and credits](https://github.com/Beren5556/AC7VRDLSS-Downloads/blob/v 0.8.1/docs/DISTRIBUTION.md).

HF8 Pro, other games/nightly builds, proximity to scenery, wakes and directional incoming gunfire are not claimed as implemented/validated features. No FPS gain is promised.

**ZIP naming:** both variants must remain named `Ace7Game.zip`, containing one `Ace7Game/` folder with the entire profile. UEVR uses the ZIP filename to identify the game. Download each variant to a separate folder; remove browser-added suffixes such as `(1)` before importing. Both downloads are version 0.8.1; the non-HF8 asset is in the no-haptics companion release.


## Update 0.8.1

Both VR downloads now use renderer 0.8.1; the SimHub/HF8 components remain 0.8. See README for the two corrected download links. Both OFXR providers default to Off. One shared Apply / Apply and save action bar controls rendering and OFXR; all OFXR changes require restarting. See README Known limitations for the isolated first-pair abort and focus/counter issue, retained for follow-up.
