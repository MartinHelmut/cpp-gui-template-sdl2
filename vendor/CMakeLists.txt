include(FetchContent)

# Dependencies

FetchContent_Declare(
  doctest
  GIT_REPOSITORY "https://github.com/onqtam/doctest.git"
  GIT_TAG v2.4.11
)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
  GIT_TAG 10.2.1
)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY "https://github.com/ocornut/imgui.git"
  GIT_TAG 085781f5ca5372d5fc804d7e44b5bf27a8994af7 # Branch: docking, date: 19.03.2024, 06:52 GMT+1
)

FetchContent_Declare(
  SDL2
  GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
  GIT_TAG release-2.30.1
)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG v1.13.0
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
