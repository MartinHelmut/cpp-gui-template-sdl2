# Base GUI project setup with SDL2

C++ gui project template with SDL2.

## Setup

The project uses [CMake](https://cmake.org) and [Ninja](https://ninja-build.org).

### Using Litr

When using [Litr](https://github.com/krieselreihe/litr), the quick setup to build and run the application is:

```shell
litr build,start
```

### Without Litr

Build the application in debug mode:

```shell
cmake -GNinja -DCMAKE_BUILD_TYPE=Debug -B build/debug
ninja -C build/debug
```

Run the application:

```shell
cd ./build/debug/src/app && ./App
```

## Disclaimer

Special acknowledgment to the amazing open source font [Manrope](https://manropefont.com).
