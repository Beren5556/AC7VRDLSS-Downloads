# V068: SteamVR presenter integration

Based on [PR #3 by djules75](https://github.com/tig3rmast3r/OFXR-Bridge/pull/3),
head `8ab03c0fb221d1ed0aecefb50a821ffa1f168a1a`, on V066.

The presenter now paces runtime frame cycles with a high-resolution timer using
the minimum credible reported display period. A pipelined application may
continue while one pair remains outstanding. SteamVR promotion requires a
blocking wait and occurs at the next frame boundary. The D3D11 interop context
enables multithread protection; virtual OpenXR wait/begin accept null optional
frame-info pointers. The recorder adds `presenter_pace` events.

Integration found two resource-lifetime defects in the original PR:

- Destroying a swapchain immediately after a pipelined end could invalidate a
  queued submission's application/private handles. The V066 control passed;
  the original PR submitted once after destruction and failed.
- Destroying an XrSpace drained queued requests but left the autonomous repeat
  referencing that space. The original PR failed with a stale-space submission.

V068 holds the frame-call lock, drains pending requests, then holds the content
lock and retires the retained repeat through destruction. Draining happens
before taking the content lock so the presenter can finish its work. Normal
frame pacing and the PR's queue capacity are retained.

DLL logger, tray cache and About derive the build number from the same CMake
version. The V066 FPS counter size/position and all optical-flow shaders remain
unchanged; all eight generated shader headers compare byte-identically.

Validation: optimized VS2022 x64 Release; 22/22 CTest tests, including both new
lifetime regressions. The five presenter/SteamVR tests also pass five repeats
each. These verify call ordering, resource lifetime and liveness, not physical
headset scanout or the author's reported performance gains. Hardware gains and
crash fixes described in the PR are the contributor's observations; V068 still
needs headset testing. D3D11 protection adds locking to the application context;
its CPU cost is workload-dependent. The PR's D3D12 UEVR crash report remains
unresolved. Multiple simultaneous OpenXR instances were not tested; the PR's
space-destruction interception still settles all active sessions.

For testing, close the previous tray, extract the whole V068 package, start its
tray, enable **Bridge flight recorder**, arm it and start a fresh game/OpenXR
session. Check sustained generation, recenter, menus/loading and leaving VR.
The overlay counts accepted submissions rather than physical scanout.
