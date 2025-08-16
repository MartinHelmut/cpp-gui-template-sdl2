include(FetchContent)

# Dependencies

FetchContent_Declare(
  doctest
  GIT_REPOSITORY "https://github.com/onqtam/doctest.git"
  GIT_TAG v2.4.12
)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
  GIT_TAG 11.2.0
)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY "https://github.com/ocornut/imgui.git"
  GIT_TAG b4311141947de17763d88f680c84c14379538388 # Branch: docking, date: 08.08.2024, 06:37 GMT+3
)

FetchContent_Declare(
  SDL2
  GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
  GIT_TAG release-2.32.8
)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG v1.15.3
)

# Settings

# For SDL2 to be able to override options
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

set(DOCTEST_NO_INSTALL ON)
set(FMT_INSTALL OFF)
set(SDL2_DISABLE_SDL2MAIN ON)
set(SPDLOG_FMT_EXTERNAL ON)

add_subdirectory(imgui-setup)

# Populate

FetchContent_MakeAvailable(doctest fmt imgui SDL2 spdlog)
