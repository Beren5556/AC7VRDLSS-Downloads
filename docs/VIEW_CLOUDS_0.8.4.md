# AC7 VR 0.8.4

Complete ACE COMBAT 7 profile for UEVR Nightly 01143, exact revision
4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d. Builds on 0.8.3 without changing
the NVIDIA_DLSS renderer or the external overlay binaries.

- Cloud mode **A** is selected by default. This workaround removes a specific cloud material contribution that caused a visible discontinuity in the tested scene. It does not reconstruct that material's stereo projection.
- The **AC7 View & Clouds** UEVR panel keeps the Original / A / B selector and active-mode indicator. B remains a diagnostic alternative.
- **F5** toggles local aircraft geometry during active flight. Aircraft visibility starts enabled each session; the flight HUD remains available.
- Optional **Camera 1** has a forward offset of +1500. Camera 0 retains the original position. Camera selection and F5 visibility are independent.
- The new helper interface is in English. Existing DLSS/DLAA, external overlay and optional haptics remain available. HF8 and both OFXR providers remain off by default.

## Installation and use

Back up your current profile and close the game before importing **Ace7Game.zip**.
Keep the exact filename and single Ace7Game root. Use the exact Nightly 01143,
not an arbitrary latest build. After import, run
`ExternalOverlay/Setup-Overlay.cmd` once to configure the bundled host for your PC.
Then start and inject as usual. Microsoft Edge is required for the overlay.

In the UEVR menu, open **AC7 View & Clouds** for aircraft visibility and cloud
selection. **Restore original view** restores the aircraft and selects Original
cloud rendering for the session. F5 does not modify controller bindings.

The cloud helper targets D3D11 Native Stereo and the exact supported UEVR build.
The observed cloud result is user-validated in the tested scene; this is not an
FPS benchmark or certification of every mission, weather, aircraft or headset.
The optional camera position depends on aircraft geometry and is adjustable in UEVR.

## Recovery

With AC7 closed, restoring the backed-up profile returns to your prior setup.
To remove only this helper, remove `plugins/AC7_ResearchTools.dll` and
`scripts/AC7_Research.lua`; restore Camera 1 from your backup if desired.
Keep other plugins, preferences and shader files. The profile does not contain
the earlier capture probes or personal logs. Existing third-party licenses apply;
the helper uses the included MinHook license and is part of the MIT-licensed project.
