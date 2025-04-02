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

#include "screen-capture-pipewire.hpp"

#include "screen-capture/screen-capture.hpp"

#include <memory>

namespace cs {

screen_capture::~screen_capture() = default;

//
// Implementation
//

auto screen_capture::create_instance() -> std::unique_ptr<screen_capture> {
    return std::make_unique<screen_capture_pipewire>();
}

} // namespace cs
