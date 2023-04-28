# Platform dependent code

Platform dependent code is implemented via [CMake's target_sources](https://cmake.org/cmake/help/latest/command/target_sources.html) function, adding files conditionally to a target.

## Example

Currently, the _Core_ library has platform dependent code. Let's take the `Resources` class as example. A common interface is defined in `src/core/Core/Resources.hpp`, looking as follows.

```c++
// src/core/Core/Resources.hpp
#pragma once

#include <filesystem>
#include <string_view>

namespace App {

class Resources {
 public:
  [[nodiscard]] static std::filesystem::path resource_path(const std::filesystem::path& file_path);
  [[nodiscard]] static std::filesystem::path font_path(const std::string_view& font_file);
};

}  // namespace App
```

The platform specific implementations are then defined in `src/core/Platform`, e.g. for macOS.

```c++
// src/core/Platform/Mac/Resources.cpp
#include "Core/Resources.hpp"

namespace App {

std::filesystem::path Resources::resource_path(const std::filesystem::path& file_path) {
  // ...
}

std::filesystem::path Resources::font_path(const std::string_view& font_file) {
  // ...
}

}  // namespace App
```

In Core's CMake file `src/core/CMakeLists.txt` the function `target_sources` is used to conditionally include those implementations.

```cmake
# src/core/CMakeLists.txt

# other CMake code ...

# Define the set of OS specific target files.
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_sources(Core PRIVATE Platform/Windows/Resources.cpp)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  target_sources(Core PRIVATE Platform/Mac/Resources.cpp)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  target_sources(Core PRIVATE Platform/Linux/Resources.cpp)
endif ()
```

The same approach can be extended to include other platforms, too.

***

Next up: [Application icons](ApplicationIcons.md)
