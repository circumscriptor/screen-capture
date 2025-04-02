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

#include "screen-capture/screen-capture.hpp"

// #include <pipewire/pipewire.h>

namespace sc {

screen_capture::~screen_capture() = default;

// Implementation derived class
class screen_capture_impl : public screen_capture {
public:
    screen_capture_impl(const screen_capture_impl&)                    = delete;
    screen_capture_impl(screen_capture_impl&&)                         = delete;
    auto operator=(const screen_capture_impl&) -> screen_capture_impl& = delete;
    auto operator=(screen_capture_impl&&) -> screen_capture_impl&      = delete;
    ~screen_capture_impl() override                                    = default;

    void set_frame_callback(frame_callback_type callback) override;

private:
    frame_callback_type m_callback;
};

//
// Implementation
//

void screen_capture_impl::set_frame_callback(frame_callback_type callback) {
    m_callback = callback;
}

} // namespace sc
