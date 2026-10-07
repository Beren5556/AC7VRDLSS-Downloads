# Historical overlay 0.8.3 instructions

For the current profile use [the current guide](OVERLAY_0.8.5.md); the setup below applies only to the historical release.

# Overlay 0.8.3 — installation and troubleshooting

Import the complete Ace7Game.zip, then run ExternalOverlay/Setup-Overlay.cmd
once in the imported profile. This writes only the overlay host configuration,
with a backup if replacing its previous paths. It does not alter game settings,
drivers, the runtime registry or other mods. Game must be closed. Microsoft Edge
must already be installed; Python/Pillow and Node/Playwright are bundled.

After setup, start and inject normally. UEVR External overlay controls whether
the host loads on the next session. F10 toggles; both triggers+grips held for two
seconds open the panel. Right controller operates it. Use Log for diagnostic
details and system/runtime names; profile emulation is not physical model detection.

If the panel does not appear: inspect the startup status in UEVR and the local
ExternalOverlay/host/logs folder; check setup paths if the profile moved. Do not
start another host manually. Close the game normally before reconfiguring.
If resolution is unavailable: confirm exact Nightly 01143 and immersive OpenXR,
with fresh stereo projection views; 2D screen/extreme compatibility are excluded.
UEVR's original controls remain available. No automatic runtime switch occurs.

Apply changes only the draft groups. Output dimensions shown as selection can
temporarily differ from submitted views. A saved request is separate from actual
persistence. If another UI changes a value, review/discard the old draft. Do not
repeat an uncertain request to find out whether it applied. OFXR options still
require restart. Resolution uses UEVR's live authority.

To recover, close game/injector and restore your pre-import profile backup.
Keep preferences and unrelated mods. Source-workspace rollback tools are not
part of this public package and must not be run on your installation.
