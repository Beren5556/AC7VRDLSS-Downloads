#define XRFG_VERTICAL_FOV_NO_MAIN
#include "vertical_fov_tests.cpp"

int main(int argc, char** argv) {
    try {
        const bool nvidia = argc > 1;
        xrfg::D3D12NvidiaOpticalFlowOptions options;
        if (nvidia) {
            const std::string_view preset(argv[1]);
            require(preset == "medium" || preset == "fast" || preset == "slow", "invalid marker-test preset");
            options.preset = preset == "fast" ? xrfg::D3D12NvidiaPerformancePreset::fast :
                preset == "slow" ? xrfg::D3D12NvidiaPerformancePreset::slow : xrfg::D3D12NvidiaPerformancePreset::medium;
            options.bidirectional = argc > 2 && std::string_view(argv[2]) == "backward";
        }
        D3D12WarpFixture fixture(nvidia);
        const auto backend = nvidia ? xrfg::D3D12OpticalFlowBackend::nvidia : xrfg::D3D12OpticalFlowBackend::fidelity_fx;
        for (bool cropped : {false, true}) for (unsigned mask : {0U, 3U}) {
            const auto views = fov_views(mask, cropped, true);
            const auto clean = run_fov_pair(fixture, backend, options, mask, cropped, true);
            for (auto corner : {xrfg::FpsOverlayPosition::upper_left, xrfg::FpsOverlayPosition::upper_right,
                                xrfg::FpsOverlayPosition::lower_left, xrfg::FpsOverlayPosition::lower_right}) {
                const auto marker = xrfg::overlay_placement(corner, -1, 1, -0.65F, 0.65F);
                const auto marked = run_fov_pair(fixture, backend, options, mask, cropped, true, marker);
                for (UINT eye = 0; eye < kEyeCount; ++eye) {
                    std::size_t count = 0;
                    const auto& view = views[eye];
                    const auto& rect = view.image_rect;
                    for (UINT y = 0; y < kFovHeight; ++y) for (UINT x = 0; x < kFovWidth; ++x) {
                        const auto i = (static_cast<std::size_t>(y) * kFovWidth + x) * 4;
                        const bool purple = marked[eye][i] >= 190 && marked[eye][i] <= 192 &&
                            marked[eye][i + 1] == 0 && marked[eye][i + 2] == 255 && marked[eye][i + 3] == 255;
                        if (!purple) {
                            for (UINT c = 0; c < 4; ++c)
                                require(std::abs(int(marked[eye][i + c]) - int(clean[eye][i + c])) <= 1,
                                    "diagnostic altered pixels outside the marker");
                            continue;
                        }
                        ++count;
                        require(x >= rect.offset_x && x < rect.offset_x + rect.width &&
                            y >= rect.offset_y && y < rect.offset_y + rect.height, "marker escaped its view rectangle");
                        const float u = (float(x - rect.offset_x) + 0.5F) / rect.width;
                        const float v = (float(y - rect.offset_y) + 0.5F) / rect.height;
                        const float left = std::tan(view.fov.angle_left), right = std::tan(view.fov.angle_right);
                        const float up = std::tan(view.fov.angle_up), down = std::tan(view.fov.angle_down);
                        const float tx = left + (right - left) * u, ty = up + (down - up) * v;
                        require(std::abs(tx - marker.x / -marker.z) <= marker.width / (-2 * marker.z) + (right - left) / rect.width &&
                                std::abs(ty - marker.y / -marker.z) <= marker.height / (-2 * marker.z) + std::abs(down - up) / rect.height,
                                "marker does not map to the counter's angular bounds");
                    }
                    require(count != 0, "synthetic has no purple marker");
                }
            }
        }
        fixture.require_no_debug_errors();
        std::cout << "Synthetic-only marker readback, corners, inversion, cropping and history isolation passed: "
                  << (nvidia ? argv[1] : "FidelityFX/WARP") << '\n';
        return 0;
    } catch (const std::exception& error) { std::cerr << error.what() << '\n'; return 1; }
}
