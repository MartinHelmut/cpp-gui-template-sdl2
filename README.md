# Base GUI project setup with SDL2

C++ gui project template with SDL2.

![Image of the example app.](example-app.png)

**Remark:** The SDL2 renderer does not support multi-viewport and detached widgets. For this you can have a look at the
[OpenGL version of this template](https://github.com/MartinHelmut/cpp-gui-template-sdl2-opengl).

## Setup

The project uses [CMake](https://cmake.org) and [Ninja](https://ninja-build.org).

Build the application in debug mode:

```shell
cmake -GNinja -DCMAKE_BUILD_TYPE=Debug -B build/debug
ninja -C build/debug
```

Run the application:

```shell
cd ./build/debug/src/app && ./App
```

### Using Litr

When using [Litr](https://github.com/krieselreihe/litr), the quick setup to build and run the application is:

```shell
litr build,start
```

## Disclaimer

Special acknowledgment to the amazing open source font [Manrope](https://manropefont.com).
