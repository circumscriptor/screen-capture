#include "screen-capture-pipewire.hpp"

#include <pipewire/keys.h>
#include <pipewire/main-loop.h>
#include <pipewire/properties.h>
#include <pipewire/stream.h>

namespace cs {

void screen_capture_pipewire::set_frame_callback(frame_callback_type callback) {
    m_callback = callback;
}

// NOLINTBEGIN(cppcoreguidelines-pro-type-vararg,hicpp-vararg)

auto screen_capture_pipewire::initialize_stream() -> bool {
    m_loop = pw_main_loop_new(nullptr);
    if (m_loop == nullptr) {
        return false;
    }

    m_properties = pw_properties_new(PW_KEY_MEDIA_TYPE, "Video", PW_KEY_MEDIA_CATEGORY, "Capture", PW_KEY_MEDIA_ROLE, "Screen", nullptr);
    if (m_properties == nullptr) {
        return false;
    }

    m_events               = {};
    m_events.version       = PW_VERSION_STREAM_EVENTS;
    m_events.state_changed = nullptr; // TODO
    m_events.process       = nullptr; // TODO
    m_stream               = pw_stream_new_simple(pw_main_loop_get_loop(m_loop), "Screen Capture", m_properties, &m_events, this);
    return m_stream != nullptr;
}

void screen_capture_pipewire::shutdown_stream() {
    if (m_stream != nullptr) {
        pw_stream_destroy(m_stream);
    }
    if (m_loop != nullptr) {
        pw_main_loop_destroy(m_loop);
    }
    if (m_properties != nullptr) {
        pw_properties_free(m_properties);
    }
}

// NOLINTEND(cppcoreguidelines-pro-type-vararg,hicpp-vararg)

} // namespace cs
