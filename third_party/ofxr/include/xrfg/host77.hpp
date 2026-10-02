#pragma once
#include <cstdint>
#include "../../../../src/OfxrContract.h"

namespace xrfg::host77 {
constexpr std::uint32_t abi = 77;
using Frame=nvidia_dlss::OfxrFrame;
struct Status {
    std::uint32_t size{sizeof(Status)}, version{abi}, state{}, reason{};
    std::uint64_t epoch{}, submitted_pairs{};
};
Frame snapshot() noexcept;
bool eligible(const Frame& frame, std::int64_t display_time) noexcept;
Frame consume(std::int64_t display_time) noexcept;
bool neural_compatible(const Frame& frame) noexcept;
void report(std::uint32_t state,std::uint32_t reason=0) noexcept;
}
extern "C" __declspec(dllexport) int RTW77_Initialize(std::uint32_t version) noexcept;
extern "C" __declspec(dllexport) int RTW77_PublishFrame(const xrfg::host77::Frame* frame) noexcept;
extern "C" __declspec(dllexport) int RTW77_GetStatus(xrfg::host77::Status* status) noexcept;
extern "C" __declspec(dllexport) void RTW77_SetDiagnostics(int enabled) noexcept;
