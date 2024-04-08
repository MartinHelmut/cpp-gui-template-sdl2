# Define apple architecture for Release builds, use default. For an explicit
# universal executable use `x86_64;arm64`.
# This file needs to be included before calling `project`.
if (APPLE AND "${CMAKE_GENERATOR}" STREQUAL "Xcode")
  set(CMAKE_OSX_ARCHITECTURES "$(ARCHS_STANDARD)" CACHE INTERNAL "")
endif ()
