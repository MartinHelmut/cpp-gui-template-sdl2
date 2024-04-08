# This file needs to be included before calling `project`.
if (APPLE AND "${CMAKE_GENERATOR}" STREQUAL "Xcode")
  # Define apple architecture for Release builds, use default. For an explicit
  # universal executable use `x86_64;arm64`.
  set(CMAKE_OSX_ARCHITECTURES "$(ARCHS_STANDARD)" CACHE INTERNAL "OS X architecture")

  # Support older macOS versions.
  set(CMAKE_OSX_DEPLOYMENT_TARGET 10.15 CACHE STRING "Minimum OS X deployment version")
endif ()
