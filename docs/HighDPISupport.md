# High DPI support

The template app supports high DPI displays out-of-the-box. The header `src/core/Core/DPIHandler.hpp` defines the interface for DPI handling. The implementations are in `src/core/Platform` under `DPIHandler.cpp` per platform.

The following two functions are important for DPI handling.

## `get_scale()`

Returns a `float` scaling factor used to set render and font scale. Should be used whenever a relative scaling is needed. See usage in platform `DPIhandler.cpp` files and `src/core/Core/Application.cpp`, `run` method.

## `get_dpi_aware_window_size()`

Returns a `WindowSize`, a struct with height and width as `int`. Will scale `Window::Settings` DPI aware per platform. See file `src/core/Core/Window.cpp`.
