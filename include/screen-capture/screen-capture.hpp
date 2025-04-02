#pragma once

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

#include "screen-capture/screen-capture_export.hpp"

#include <functional>
#include <memory>

namespace cs {

/**
 * @brief Main interface
 */
class SCREEN_CAPTURE_EXPORT screen_capture {
public:
    using frame_callback_type = std::function<void()>;

    screen_capture()                                         = default;
    screen_capture(const screen_capture&)                    = delete;
    screen_capture(screen_capture&&)                         = delete;
    auto operator=(const screen_capture&) -> screen_capture& = delete;
    auto operator=(screen_capture&&) -> screen_capture&      = delete;
    virtual ~screen_capture();

    virtual void set_frame_callback(frame_callback_type callback) = 0;

    /**
     * @brief Create screen capture instance for pipewire backend
     * @note This call does not initialize pipewire library
     * @return Unique pointer to screen capture instance
     */
    [[nodiscard]] static auto create_instance() -> std::unique_ptr<screen_capture>;

private:
    // SCREEN_CAPTURE_SUPPRESS_C4251
    // std::string m_name;
};

} // namespace cs
