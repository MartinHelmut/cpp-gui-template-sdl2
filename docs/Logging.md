# Logging

The library [spdlog](https://github.com/gabime/spdlog) is used for logging. The logger is set up in `src/core/Core/Log.{cpp,hpp}` that will define a default logger writing to stdout and into a `app.log` file. The macros used for logging are defined in `src/core/Core/Log.hpp`.

## Available macros

The available macros are defined in order of severity.

- `APP_TRACE`
- `APP_DEBUG`
- `APP_INFO`
- `APP_WARN`
- `APP_ERROR`
- `APP_FATAL`

The levels `APP_TRACE` and `APP_DEBUG` are only enabled in debug mode or when `DEBUG` is defined through CMake.

```shell
cmake -GNinja -DCMAKE_BUILD_TYPE=Release -DDEBUG -B build/release
```

Logging can also fully be **deactivated** via `DEACTIVATE_LOGGING`.

```shell
cmake -GNinja -DCMAKE_BUILD_TYPE=Debug -DDEACTIVATE_LOGGING -B build/debug
```

## Usage

Include the logger and use one of the macros. All logger macros use fmt under the hood for string formatting.

```c++
#include "Core/Log.hpp"

namespace App {

Window::Window(const Settings& settings) {
  APP_DEBUG("Window created: {}", settings.title);
}

}
```

***

Next up: [Dependencies](Dependencies.md)
