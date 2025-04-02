if(PROJECT_IS_TOP_LEVEL)
  set(
      CMAKE_INSTALL_INCLUDEDIR "include/screen-capture-${PROJECT_VERSION}"
      CACHE STRING ""
  )
  set_property(CACHE CMAKE_INSTALL_INCLUDEDIR PROPERTY TYPE PATH)
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package screen-capture)

install(
    DIRECTORY
    include/
    "${PROJECT_BINARY_DIR}/export/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT screen-capture_Development
)

install(
    TARGETS screen-capture_screen-capture
    EXPORT screen-captureTargets
    RUNTIME #
    COMPONENT screen-capture_Runtime
    LIBRARY #
    COMPONENT screen-capture_Runtime
    NAMELINK_COMPONENT screen-capture_Development
    ARCHIVE #
    COMPONENT screen-capture_Development
    INCLUDES #
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    screen-capture_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/${package}"
    CACHE STRING "CMake package config location relative to the install prefix"
)
set_property(CACHE screen-capture_INSTALL_CMAKEDIR PROPERTY TYPE PATH)
mark_as_advanced(screen-capture_INSTALL_CMAKEDIR)

install(
    FILES cmake/install-config.cmake
    DESTINATION "${screen-capture_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT screen-capture_Development
)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${screen-capture_INSTALL_CMAKEDIR}"
    COMPONENT screen-capture_Development
)

install(
    EXPORT screen-captureTargets
    NAMESPACE screen-capture::
    DESTINATION "${screen-capture_INSTALL_CMAKEDIR}"
    COMPONENT screen-capture_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
