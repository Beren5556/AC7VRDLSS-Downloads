#pragma once
#include <cstdint>
namespace nvidia_dlss {
struct OfxrFrame {
 std::uint32_t size{sizeof(OfxrFrame)},version{77};
 std::uint64_t epoch{};
 std::int64_t display_time{};
 std::uint64_t serial{},neural_generation{},game_frame{};
 std::uint32_t flags{},reserved{};
};
static_assert(sizeof(OfxrFrame)==56);
struct OfxrStatus {
 std::uint32_t size{sizeof(OfxrStatus)},version{77},state{},reason{};
 std::uint64_t epoch{},submitted_pairs{};
};
}
