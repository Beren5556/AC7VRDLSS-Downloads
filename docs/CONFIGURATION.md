# NVIDIA_DLSS configuration

Required host: UEVR Nightly 01143, revision `4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d`. Use this exact host build; compatibility does not carry over automatically to other builds.

Edit `<UEVR profile>/NVIDIA_DLSS/settings.ini` while the game is closed. Values are read at startup. Rendering settings use `[NVIDIA_DLSS]`; OFXR uses the separate `[OFXR_Classic]` and `[OFXR_Fork_Djules75]` sections below. One shared action bar at the bottom of the UEVR panel controls all three groups: **Apply** applies changed rendering settings and stages changed OFXR settings; **Apply and save** also writes all settings for the next launch. **Discard** discards unsent edits in both groups. OFXR always requires restarting the game; applying does not change the active provider. Keep your game Engine.ini unchanged.

## Neural appearance

These keys affect **DLSS5 / Neural**. Percentages are integer values: **100 means runtime strength 1.0**, not a percentage of GPU usage. Style is separate from the DLSS SR preset.

| Key | Allowed values | Default |
| --- | --- | --- |
| `NeuralStyle` | `0` Balanced, `1` Sharp, `2` Cinematic | `2` |
| `NeuralIntensity` | `0`–`200` % | `100` |
| `NeuralStructure` | Local structure strength, `0`–`200` % | `100` |
| `NeuralTone` | Local tone strength, `0`–`200` % | `100` |
| `NeuralSkinAuto` | `1` automatic skin strength, `0` manual | `1` |
| `NeuralSkin` | Manual skin structure, `0`–`200` %; ignored when Auto is enabled | `100` |
| `NeuralAutoMask` | `1` automatic Neural mask, `0` disabled | `0` |
| `NeuralTransfer` | Resolved Neural detail strength, `0`–`200` % | `100` |
| `NeuralColor` | Resolved Neural color strength, `0`–`100` % | `100` |
| `NeuralSharpness` | Neural resolve sharpness, `0`–`100` % | `0` |
| `NeuralPercent` | Neural processing resolution, `50`–`100` % | `85` |
| `NeuralBeforeDLSS` | `true` before DLSS, `false` after DLSS | `true` |

The scale is relative to the DLSS input when Before is enabled, otherwise to the DLSS output. At **100% Neural resolution**, there is no reduced-resolution resolve: `NeuralTransfer`, `NeuralColor` and `NeuralSharpness` are inactive. Style/intensity/structure/tone/skin remain connected at 100%. With automatic skin enabled, the runtime chooses the skin strength; the plug-in does not claim a numeric effective value.

Model controls map to the Cost-Scaler `[DLSSNR_Settings]` parameters `Style`, `Intensity`, `LocalStructureStrength`, `LocalToneStrength`, `SkinStructureStrength` and `UseAutoMask`. Resolve controls map to `[DLSSNR_Proxy]` `TransferStrength`, `ColorStrength` and `Sharpness`. See the [pinned upstream configuration](https://github.com/xenmods/DLSSNR-Cost-Scaler/blob/efe2ed6a2536c64b74ffa431df42d223a58e9761/README.md). The plug-in writes these private per-eye files; use settings.ini or the UEVR panel instead of editing generated runtime INIs.

## Other controls

| Key | Allowed values | Default |
| --- | --- | --- |
| `StartupMode` | `NONE`, `TAA`, `DLAA`, `DLSS`, `DLSS5` | `DLSS` |
| `Preset` | `Auto`, `J`, `K`, `L`, `M`; requested SR preset | `K` |
| `DLSSQuality` | `Quality`, `Balanced`, `Performance` | `Quality` |
| `DLSSScaleBps` | `0` follows quality; `5000`–`9900` means 50.00%–99.00% | `0` |
| `SharpnessPercent` | DLSS/DLAA output sharpness, `0`–`100` % | `0` |
| `TestLabel` | `true` shows the red render-mode label | `false` |
| `TestHotkeys` | `true` enables F8 mode / F9 quality | `true` |
| `Diagnostics` | `true` enables extra diagnostic work | `false` |
| `TraceDlssOnce` | `true` records bounded transition diagnostics | `false` |

DLAA uses native input resolution. The driver/runtime can choose an effective SR model different from the requested preset; the panel reports the request. Invalid values produce an explicit error rather than silently selecting a different render mode. Existing diagnostic preferences are preserved on upgrade.

```ini
[NVIDIA_DLSS]
StartupMode=DLSS
Preset=K
DLSSQuality=Quality
DLSSScaleBps=0
SharpnessPercent=0
NeuralPercent=85
NeuralBeforeDLSS=true
NeuralStyle=2
NeuralIntensity=100
NeuralStructure=100
NeuralTone=100
NeuralSkinAuto=1
NeuralSkin=100
NeuralAutoMask=0
NeuralTransfer=100
NeuralColor=100
NeuralSharpness=0
```

## Custom DLSS resolution

In DLSS or DLSS5 / Neural mode, the **Internal resolution (%)** slider accepts 50.00–99.00%. Drag it or Ctrl+click it to type an exact percentage. Quality (66.7%), Balanced (58%) and Performance (50%) remain quick reference buttons. Click **Apply** to use the change, and **Save startup settings** to retain it for the next launch.

For a direct INI edit with the game closed, use `DLSSScaleBps=8000` for 80%, `7537` for 75.37%, or `9900` for 99%. `0` follows `DLSSQuality`. DLAA always uses native 100% input and disables this control. Neural resolution remains a separate 50–100% setting.

## Automatic flight routing

Your saved rendering selection applies during controlled VR flight, in cockpit and external flight cameras. Menus, runway sequences, cinematics, pauses, replays and unavailable flight controls retain original rendering and suspend OFXR. The included profile must retain **Menu Window Mode** for screen/VR detection. No manual changes to `Engine.ini` are required.

The panel shows a waiting state until flight permission and valid temporal inputs are available. Initial Neural startup can pause rendering while its resources initialize. Missing flight signals suspend processing; an initialization stall does not repeatedly restart Neural.

Changing either OFXR block requires a game restart. Once loaded, OFXR pauses and resumes automatically with controlled flight. Transitions invalidate previous frame history.

## Separate OFXR provider controls

The UEVR NVIDIA_DLSS panel has two separate blocks: **OFXR Classic** (0.2.1 / V116) and **OFXR Fork Djules75** (0.2.10.1 / V412, commit a1a4a2bf7b3307b7f4329c49870b158e5faaa45e). Each block has its own enable checkbox and parameters. Checking one automatically unchecks the other. Leave both unchecked for Off. Each provider keeps its own values when switching between them.

Use **Apply and save**, then restart the game. **Apply** stages the settings without saving or switching the loaded DLL. All OFXR changes require a game restart, including 2X/3X. The status shows the provider actually selected at startup. The standalone fork's live 3X switch is not exposed.

### Two separate INI sections

File: `%APPDATA%/UnrealVRMod/Ace7Game/NVIDIA_DLSS/settings.ini`.

Both providers are disabled in the default configuration:

```ini
[OFXR_Classic]
; Classic 0.2.1 / V116 (2X). Enable only one OFXR. Restart after any OFXR change.
Enabled=false
; Backend: NVIDIA or FidelityFX (AMD).
Backend=NVIDIA
; NVIDIA optical flow quality: Fast (experimental), Medium, Slow.
NvidiaPreset=Medium
; NVIDIA optical flow resolution: 50, 75, 100. Independent of DLSS and Neural.
FlowScalePercent=50
; NVIDIA forward and backward flow: true or false. Normally false.
BidirectionalFlow=false
; FPS counter: Off, UpperLeft, UpperRight, LowerLeft, LowerRight.
FPSOverlay=Off
; Classic provider diagnostic log: true or false. Normally false.
DiagnosticLogging=false

[OFXR_Fork_Djules75]
; Fork djules75 0.2.10.1 / V412. Enable only one OFXR. Restart after any OFXR change.
Enabled=false
; Backend: NVIDIA or FidelityFX (AMD).
Backend=NVIDIA
; NVIDIA optical flow quality: Fast (experimental), Medium, Slow.
NvidiaPreset=Medium
; NVIDIA optical flow resolution: 50, 75, 100. Independent of DLSS and Neural.
FlowScalePercent=50
; Frame generation multiplier: 2 or 3. 3 requires PreferFPS=true.
FrameMultiplier=2
; true: prioritize FPS. false: prioritize latency (2X only).
PreferFPS=true
; FPS counter: Off, UpperLeft, UpperRight, LowerLeft, LowerRight.
FPSOverlay=Off
; Fork provider diagnostic log: true or false. Normally false.
DiagnosticLogging=false
```

For the first fork test, change only `Enabled=false` to `Enabled=true` under `[OFXR_Fork_Djules75]`. Keep `[OFXR_Classic]` disabled. Its other defaults already select NVIDIA Medium, 50% flow resolution, 2X, FPS priority, no counter and no diagnostic log.

To use Classic, enable only `[OFXR_Classic]`. To turn OFXR off, set both `Enabled` values to false. If both are true, the plugin reports a configuration error and loads neither provider.

Classic has its own backend, NVIDIA preset/resolution, bidirectional flow, FPS overlay and diagnostics. Classic always uses 2X. The fork has separate backend, NVIDIA preset/resolution, 2X/3X, FPS priority, FPS overlay and diagnostics. Its 3X mode requires `PreferFPS=true` and may show more artifacts. NVIDIA preset/resolution and Classic bidirectional flow are inactive with FidelityFX. Optical flow resolution is independent of DLSS and Neural scales.

The new sections replace the old `OFXREnabled` flag and compact `OFXRConfig` record. Old files remain readable for migration; saving from UEVR writes named parameters in both sections and removes the obsolete keys. Other rendering settings, comments and HF8 settings are preserved. No numeric record needs to be edited by the user. Do not edit the generated provider INIs inside the versioned runtime.

### Operation and validation

Both providers require a validated stereo pair and controlled VR flight. Generation is suspended for menus, 2D mode, pause, cinematics, invalid or stale flight state, and incompatible stereo history. A new history is required on reentry. HF8 retains its existing independent controls and rules. Only one private OFXR DLL is loaded. No tray application or global layer registration is installed.

UEVR reference: Nightly 01143, revision 4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d. The fork's D3D11 bridge and single swapchain rings are managed internally.

Offline checks and installation receipts are listed in the release report. They do not establish physical headset image quality or FPS improvement. The coordinated HF8/VR test was accepted with known limitations documented in the release README. No physical validation of other games or HF8 Pro is implied.
