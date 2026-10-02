# NVIDIA_DLSS configuration

Required host: UEVR Nightly 01143, revision `4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d`. Use this exact host build; compatibility does not carry over automatically to other builds.

Edit `<UEVR profile>/NVIDIA_DLSS/settings.ini` while the game is closed. Values are read at startup. The section name is `[NVIDIA_DLSS]`. The UEVR panel applies changes during the session with **Apply**; **Save startup settings** writes the settings for the next launch. OFXR always requires restarting the game. Keep your game Engine.ini unchanged.

## Neural appearance

These keys affect **DLSS5 / Neural**. Percentages are integer values: **100 means runtime strength 1.0**, not a percentage of GPU usage. Style is separate from the DLSS SR preset.

| Key | Allowed values | Default |
| --- | --- | --- |
| `NeuralStyle` | `0` Balanced, `1` Sharp, `2` Cinematic | `2` |
| `NeuralIntensity` | `0`â€“`200` % | `100` |
| `NeuralStructure` | Local structure strength, `0`â€“`200` % | `100` |
| `NeuralTone` | Local tone strength, `0`â€“`200` % | `100` |
| `NeuralSkinAuto` | `1` automatic skin strength, `0` manual | `1` |
| `NeuralSkin` | Manual skin structure, `0`â€“`200` %; ignored when Auto is enabled | `100` |
| `NeuralAutoMask` | `1` automatic Neural mask, `0` disabled | `0` |
| `NeuralTransfer` | Resolved Neural detail strength, `0`â€“`200` % | `100` |
| `NeuralColor` | Resolved Neural color strength, `0`â€“`100` % | `100` |
| `NeuralSharpness` | Neural resolve sharpness, `0`â€“`100` % | `0` |
| `NeuralPercent` | Neural processing resolution, `50`â€“`100` % | `85` |
| `NeuralBeforeDLSS` | `true` before DLSS, `false` after DLSS | `true` |

The scale is relative to the DLSS input when Before is enabled, otherwise to the DLSS output. At **100% Neural resolution**, there is no reduced-resolution resolve: `NeuralTransfer`, `NeuralColor` and `NeuralSharpness` are inactive. Style/intensity/structure/tone/skin remain connected at 100%. With automatic skin enabled, the runtime chooses the skin strength; the plug-in does not claim a numeric effective value.

Model controls map to the Cost-Scaler `[DLSSNR_Settings]` parameters `Style`, `Intensity`, `LocalStructureStrength`, `LocalToneStrength`, `SkinStructureStrength` and `UseAutoMask`. Resolve controls map to `[DLSSNR_Proxy]` `TransferStrength`, `ColorStrength` and `Sharpness`. See the [pinned upstream configuration](https://github.com/xenmods/DLSSNR-Cost-Scaler/blob/efe2ed6a2536c64b74ffa431df42d223a58e9761/README.md). The plug-in writes these private per-eye files; use settings.ini or the UEVR panel instead of editing generated runtime INIs.

## Other controls

| Key | Allowed values | Default |
| --- | --- | --- |
| `StartupMode` | `NONE`, `TAA`, `DLAA`, `DLSS`, `DLSS5` | `DLSS` |
| `Preset` | `Auto`, `J`, `K`, `L`, `M`; requested SR preset | `K` |
| `DLSSQuality` | `Quality`, `Balanced`, `Performance` | `Quality` |
| `DLSSScaleBps` | `0` follows quality; `5000`â€“`9900` means 50.00%â€“99.00% | `0` |
| `SharpnessPercent` | DLSS/DLAA output sharpness, `0`â€“`100` % | `0` |
| `OFXREnabled` | `true` or `false`; OpenXR required, restart required | `false` |
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
OFXREnabled=false
```

## Custom DLSS resolution

In DLSS or DLSS5 / Neural mode, the **Internal resolution (%)** slider accepts 50.00â€“99.00%. Drag it or Ctrl+click it to type an exact percentage. Quality (66.7%), Balanced (58%) and Performance (50%) remain quick reference buttons. Click **Apply** to use the change, and **Save startup settings** to retain it for the next launch.

For a direct INI edit with the game closed, use `DLSSScaleBps=8000` for 80%, `7537` for 75.37%, or `9900` for 99%. `0` follows `DLSSQuality`. DLAA always uses native 100% input and disables this control. Neural resolution remains a separate 50â€“100% setting.

## Automatic flight routing

Your saved rendering selection applies during controlled VR flight, in cockpit and external flight cameras. Menus, runway sequences, cinematics, pauses, replays and unavailable flight controls retain original rendering and suspend OFXR. The included profile must retain **Menu Window Mode** for screen/VR detection. No manual changes to `Engine.ini` are required.

The panel shows a waiting state until flight permission and valid temporal inputs are available. Initial Neural startup can pause rendering while its resources initialize. Missing flight signals suspend processing; an initialization stall does not repeatedly restart Neural.

Changing `OFXREnabled` requires a game restart. Once loaded, OFXR pauses and resumes automatically with controlled flight. Transitions invalidate previous frame history.
