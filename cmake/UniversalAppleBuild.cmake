# Generate universal executable for Apple hardware for Release builds.
# This file needs to be included before calling `project`.
if (APPLE AND CMAKE_BUILD_TYPE STREQUAL "Release")
  # Universal build with "arm64;x86_64" are currently not possible for Debug builds.
  # @see: https://gitlab.kitware.com/cmake/cmake/-/issues/24323
  set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "")
endif ()
