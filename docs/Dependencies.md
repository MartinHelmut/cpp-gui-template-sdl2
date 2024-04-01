# Dependencies

Dependencies are located in `vendor/`. The `vendor/CMakeLists.txt` uses
CMake's [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) to load dependencies on configure
time. Some dependencies also have an associated folder containing a `CMakeLists.txt` for configuration or setup purpose.

## Already included

The following set of dependencies are already included:

- [Doctest](https://github.com/doctest/doctest) - Testing framework
- [fmtlib](https://fmt.dev/latest/index.html) - Formatting library
- [Dear ImGUI](https://github.com/ocornut/imgui) - Immediate mode GUI library
- [SDL2](https://www.libsdl.org) - Media layer library for rendering and input abstraction
- [spdlog](https://github.com/gabime/spdlog) - Logging library

## Add new dependency with CMake support

If a package to be included already supports CMake the process of adding it is rather straight forward. It needs a new
entry in `vendor/CMakeLists.txt` to fetch the actual contents. Via `FetchContent_Declare` a name, repo URL and tag,
branch, or commit name is given.

```cmake
# vendor/CMakeLists.txt

# Example inclusion of spdlog
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG v1.11.0
)
```

Further down the same file is a section for dependency settings. Again using spdlog as an example:

```cmake
# vendor/CMakeLists.txt

# Settings

# Any package build settings here
set(SPDLOG_FMT_EXTERNAL "ON")

# Populate

FetchContent_MakeAvailable(
  # Other dependencies ...
  spdlog)
```

At the end the call to `FetchContent_MakeAvailable` gets the new dependency added as well.

## New dependency without CMake support

Adding a package that does not support CMake is also not a problem. The difference is that the new library needs to be
setup separately. Taking Dear ImGui as an example, that does not support CMake, this is how the setup is
done:

```cmake
# vendor/imgui-setup/CMakeLists.txt

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
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer2.h ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer2.cpp)

# Set include directory based in populated variable `imgui_SOURCE_DIR`.
target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})

# Define compile options.
target_compile_features(imgui PRIVATE cxx_std_20)

# Link external library SDL2, part of the dependencies as well.
target_link_libraries(imgui PUBLIC SDL2::SDL2)
```

After setting up the library it needs to be made available in the vendor `CMakeLists.txt`:

```cmake
# vendor/CMakeLists.txt

# Settings

# Adding the setup directory
add_subdirectory(imgui-setup)

# Populate

FetchContent_MakeAvailable(
  # Other dependencies ...
  imgui)
```

## Link dependency

After adding a new dependency, to actually use it, it needs to be added to a target via `target_link_libraries`. For
example adding ImGUI to Core:

```cmake
# other CMake ...

target_link_libraries(Core PUBLIC imgui)
```

***

Next up: [Packaging](Packaging.md)
