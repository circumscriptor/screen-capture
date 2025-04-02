cmake_minimum_required(VERSION 3.14)

project(screen-captureTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(screen-capture REQUIRED)
  enable_testing()
endif()

# ---- Tests ----

add_executable(screen-capture_test source/screen-capture_test.cpp)
target_link_libraries(screen-capture_test PRIVATE screen-capture::screen-capture)
target_compile_features(screen-capture_test PRIVATE cxx_std_20)

add_test(NAME screen-capture_test COMMAND screen-capture_test)

# ---- End-of-file commands ----

add_folders(Test)
