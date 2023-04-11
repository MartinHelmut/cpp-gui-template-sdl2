# Base GUI project setup with SDL2

C++ gui project template with SDL2.

![Image of the example app.](example-app.png)

**Remark:** The SDL2 renderer does not support multi-viewport and detached widgets. For this you can have a look at the
[OpenGL version of this template](https://github.com/MartinHelmut/cpp-gui-template-sdl2-opengl).

## Setup

### Git LFS

Some of the assets are stored through [Git Large File Storage (LFS)](https://git-lfs.com). It **needs to be installed
before cloning** a repository using this template. In case it was installed after cloning, run `git lfs checkout`
to get all LFS files.

### CMake & Ninja

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

## Distribution

To create a distribution package CPack is used, e.g. from a Release build.

```shell
cpack --config build/release/CPackConfig.cmake
```

## Using Litr

When using [Litr](https://github.com/krieselreihe/litr), the quick setup to build and run the application is:

```shell
litr build,start
```

To create a package distribution run:

```shell
litr dist
```

## Disclaimer

Special acknowledgment to the amazing open source font [Manrope](https://manropefont.com).
