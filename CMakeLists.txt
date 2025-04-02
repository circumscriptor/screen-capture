cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    screen-capture
    VERSION 0.1.0
    DESCRIPTION "Screen Capture with PipeWire"
    HOMEPAGE_URL "https://github.com/circumscriptor/screen-capture"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Find dependencies ----

find_package(PkgConfig REQUIRED)

pkg_search_module(PipeWire REQUIRED IMPORTED_TARGET libpipewire-0.3)

# ---- Declare library ----

add_library(
    screen-capture_screen-capture
    source/screen-capture.cpp
)
add_library(screen-capture::screen-capture ALIAS screen-capture_screen-capture)

include(GenerateExportHeader)
generate_export_header(
    screen-capture_screen-capture
    BASE_NAME screen-capture
    EXPORT_FILE_NAME export/screen-capture/screen-capture_export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(screen-capture_screen-capture PUBLIC SCREEN_CAPTURE_STATIC_DEFINE)
endif()

set_target_properties(
    screen-capture_screen-capture PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME screen-capture
    OUTPUT_NAME screen-capture
)

target_include_directories(
    screen-capture_screen-capture ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_include_directories(
    screen-capture_screen-capture SYSTEM
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features(screen-capture_screen-capture PUBLIC cxx_std_20)

target_link_libraries(screen-capture_screen-capture
    PRIVATE
        PkgConfig::PipeWire
)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT screen-capture_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of screen-capture"
  )
endif()

include(cmake/dev-mode.cmake)
