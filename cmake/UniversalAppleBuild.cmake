# Generate universal executable for Apple hardware
# This file needs to be included before calling `project`.
if (APPLE)
  # Universal build with "arm64;x86_64"
  # Currently deactivated due to an issue with CMake and clang-tidy.
  # @see: https://gitlab.kitware.com/cmake/cmake/-/issues/24323
  set(CMAKE_OSX_ARCHITECTURES "${ARCHS_STANDARD}" CACHE STRING "")
endif ()
