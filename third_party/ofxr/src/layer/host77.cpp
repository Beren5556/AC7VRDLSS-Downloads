#include "xrfg/host77.hpp"
#include "xrfg/bridge_flight_logger.hpp"
#include <windows.h>
#include <mutex>
namespace xrfg::host77 {
namespace {
std::mutex mutex;
Frame current;
Status status;
bool initialized{};
std::uint64_t consumed{};
using Read=int(__cdecl*)(Frame*);
Read reader{};
}
Frame snapshot() noexcept {
 std::scoped_lock lock(mutex);
 Frame value;
 if(!initialized)return value;
 if(reader){if(!reader(&value))return Frame{};current=value;}
 return current;
}
Frame consume(std::int64_t display_time) noexcept {
 auto value=snapshot();std::scoped_lock lock(mutex);
 if(!value.serial||value.serial<=consumed||display_time<=0)return Frame{};
 consumed=value.serial;value.display_time=display_time;return value;
}
bool eligible(const Frame& frame,std::int64_t display_time) noexcept {
 return frame.size==sizeof(Frame)&&frame.version==abi&&frame.epoch&&frame.serial&&frame.display_time>0&&frame.display_time==display_time&&(frame.flags&1)!=0&&(frame.flags&~3u)==0;
}
bool neural_compatible(const Frame& frame) noexcept {
 // Both eyes must have been published by DirectTemporal in one generation.
 // AC7 already verifies SR/NR results, including its two private Neural hosts.
 return (frame.flags&2)&&frame.neural_generation&&frame.game_frame;
}
void report(std::uint32_t state,std::uint32_t reason) noexcept {
 std::scoped_lock lock(mutex);status.state=state;status.reason=reason;status.epoch=current.epoch;if(state==3)++status.submitted_pairs;
}
}
extern "C" int RTW77_Initialize(std::uint32_t version) noexcept {
 if(version!=xrfg::host77::abi)return 0;
 xrfg::initialize_bridge_flight_logger();std::scoped_lock lock(xrfg::host77::mutex);
 xrfg::host77::initialized=true;xrfg::host77::status.state=1;return 1;
}
extern "C" int RTW77_PublishFrame(const xrfg::host77::Frame* frame) noexcept {
 std::scoped_lock lock(xrfg::host77::mutex);
 if(!xrfg::host77::initialized||!frame||frame->size!=sizeof(*frame)||frame->version!=xrfg::host77::abi||(frame->flags&~3u)!=0){xrfg::host77::current={};return 0;}
 xrfg::host77::current=*frame;return 1;
}
extern "C" int RTW77_GetStatus(xrfg::host77::Status* output) noexcept {
 if(!output||output->size!=sizeof(*output)||output->version!=xrfg::host77::abi)return 0;
 std::scoped_lock lock(xrfg::host77::mutex);*output=xrfg::host77::status;return 1;
}
extern "C" void RTW77_SetDiagnostics(int enabled) noexcept {xrfg::initialize_bridge_flight_logger();xrfg::bridge_flight_logger().set_enabled(enabled!=0);}
extern "C" __declspec(dllexport) int NVIDIA_DLSS_OFXR_SetReader(int(__cdecl*read)(xrfg::host77::Frame*)) noexcept {
 if(!read)return 0;std::scoped_lock lock(xrfg::host77::mutex);xrfg::host77::reader=read;return 1;
}
