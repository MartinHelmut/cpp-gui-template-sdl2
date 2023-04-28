# Dependencies

Dependencies are located in `vendor/`. The `vendor/CMakeLists.txt` uses CMake's [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) to load dependencies on configure time. Every dependency also has an associated folder containing a `CMakeLists.txt` for configuration.

## Already included

The following set of dependencies is already included:

- [Doctest](https://github.com/doctest/doctest) - Testing framework
- [fmtlib](https://fmt.dev/latest/index.html) - Formatting library
- [Dear ImGUI](https://github.com/ocornut/imgui) - Immediate mode GUI library
- [SDL2](https://www.libsdl.org) - Media layer library for rendering and input abstraction
- [spdlog](https://github.com/gabime/spdlog) - Logging library

## Add new dependency with CMake support

If a package to be included already supports CMake the process of adding it is rather straight forward. It needs a new entry in `vendor/CMakeLists.txt` to fetch the actual contents. Via `FetchContent_Declare` a name, repo URL and tag, branch, or commit name is given.

```cmake
# vendor/CMakeLists.txt

# Example inclusion of spdlog
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG v1.11.0
)
add_subdirectory(spdlog)
```

After adding this to the `vendor` CMake file, a new `CMakeLists.txt` needs to be created in a new folder for the dependency. Again with the spdlog example:

```cmake
# vendor/spdlog/CMakeLists.txt

message(STATUS "Fetching spdlog ...")

# Any package build settings here
set(SPDLOG_FMT_EXTERNAL "ON")

FetchContent_MakeAvailable(spdlog)
```

This dependency specific CMake file will contain a message for fetching the library, any package configuration, and a call to `FetchContent_MakeAvailable` with the given name to add them to the build.

## New dependency without CMake support

Adding a package that does not support CMake works almost the same as with support above. The difference is that the new library needs to be declared. Taking Dear ImGui as an example, that does not support CMake, this is how the setup is done:

```cmake
message(STATUS "Fetching imgui ...")

# Define build options.
set(CMAKE_CXX_STANDARD 20)

# Populate scope with library variables to get access to source and build directories.
FetchContent_GetProperties(imgui)
if (NOT imgui_POPULATED)
  FetchContent_Populate(imgui)
endif ()

# Add Dear ImGUI as library with needed source files.
add_library(imgui
  ${imgui_SOURCE_DIR}/imgui.cpp ${imgui_SOURCE_DIR}/imgui.h
  ${imgui_SOURCE_DIR}/imconfig.h ${imgui_SOURCE_DIR}/imgui_demo.cpp
  ${imgui_SOURCE_DIR}/imgui_draw.cpp ${imgui_SOURCE_DIR}/imgui_internal.h
  ${imgui_SOURCE_DIR}/imgui_tables.cpp ${imgui_SOURCE_DIR}/imgui_widgets.cpp
  ${imgui_SOURCE_DIR}/imstb_rectpack.h ${imgui_SOURCE_DIR}/imstb_textedit.h
  ${imgui_SOURCE_DIR}/imstb_truetype.h
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.h ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer.h ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer.cpp)

# Set include directory based in populated variable `imgui_SOURCE_DIR`.
target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})

# Link external library SDL2, part of the dependencies as well.
target_link_libraries(imgui PUBLIC SDL2::SDL2)

# Add to main build
FetchContent_MakeAvailable(imgui)
```

## Link dependency

After adding a new dependency, to actually use it, it needs to be added to a target via `target_link_libraries`. For example adding ImGUI to Core:

```cmake
# other CMake ...

target_link_libraries(Core PUBLIC imgui)
```

***

Next up: [Packaging](Packaging.md)
