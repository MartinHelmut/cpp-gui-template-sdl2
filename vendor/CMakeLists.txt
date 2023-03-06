include(FetchContent)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY "https://github.com/onqtam/doctest.git"
  GIT_TAG v2.4.10
)
add_subdirectory(doctest)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
  GIT_TAG 9.1.0
)
add_subdirectory(fmt)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY "https://github.com/ocornut/imgui.git"
  GIT_TAG f5c5a710aa38b91be39b1c219f3bb90e2e15df80 # Branch: docking, date: 06.03.2023
)
add_subdirectory(imgui)

FetchContent_Declare(
  SDL2
  GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
  GIT_TAG release-2.26.3
)
add_subdirectory(sdl)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG v1.11.0
)
add_subdirectory(spdlog)
