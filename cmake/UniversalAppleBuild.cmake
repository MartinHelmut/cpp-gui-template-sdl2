# Generate universal executable for Apple hardware for Release builds.
# This file needs to be included before calling `project`.
if (APPLE AND "${CMAKE_GENERATOR}" STREQUAL "Xcode")
  set(CMAKE_OSX_ARCHITECTURES "$(ARCHS_STANDARD)")
endif ()
