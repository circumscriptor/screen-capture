/*
 * Copyright 2025 circumscriptor
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include "screen-capture/screen-capture.hpp"

#include <pipewire/main-loop.h>
#include <pipewire/properties.h>
#include <pipewire/stream.h>

namespace cs {

class screen_capture_pipewire : public screen_capture {
public:
    screen_capture_pipewire()                                                  = default;
    screen_capture_pipewire(const screen_capture_pipewire&)                    = delete;
    screen_capture_pipewire(screen_capture_pipewire&&)                         = delete;
    auto operator=(const screen_capture_pipewire&) -> screen_capture_pipewire& = delete;
    auto operator=(screen_capture_pipewire&&) -> screen_capture_pipewire&      = delete;
    ~screen_capture_pipewire() override                                        = default;

    void set_frame_callback(frame_callback_type callback) override;

protected:
    auto initialize_stream() -> bool;
    void shutdown_stream();

private:
    pw_main_loop*       m_loop {};
    pw_properties*      m_properties {};
    pw_stream_events    m_events {};
    pw_stream*          m_stream {};
    frame_callback_type m_callback;
};

} // namespace cs
