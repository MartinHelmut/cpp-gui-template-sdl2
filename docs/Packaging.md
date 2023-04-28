# Packaging

The app comes with packaging through [CPack](https://cmake.org/cmake/help/latest/module/CPack.html), creating installer for macOS, Windows, and Linux.

General packaging settings are located under `packaging/`. Executable specific settings in `src/app/cmake/Packaging.cmake` and OS specifics under `src/app/cmake/packaging/`.

## General packaging settings

General packaging settings are in `packaging/CMakeLists.txt`. It defines names, versions, metadata, where to build the package to (`build/distribution/`), and more.

## OS specific settings

### macOS

For macOS a `.dmg` (DragNDrop) file will be generated. Resources for the installer are located under `packaging/dmg/`, containing the background image for the DMG view and an apple script to generate the custom DMG view.

Packaging settings for the application executable are in `src/app/cmake/packaging/Darwin.cmake`.

The final application build for Apple devices should be built via the `Xcode` generator with CMake.

```shell
cmake -GXCode -DCMAKE_BUILD_TYPE=Release -B build/xcode
cmake --build build/xcode
```

### Windows

On Windows a `.exe` is created via [NSIS](https://nsis.sourceforge.io/Main_Page). NSIS **needs to be installed** in Windows to create the package. Resources for the installer are located under `packaging/nsis/`, containing installer images and the uninstaller icon.

Packaging settings for the application executable are in `src/app/cmake/packaging/Windows.cmake`.

### Linux

On Linux a `.deb` file will be created that can be installed via the systems package manager.

Packaging settings for the application executable are in `src/app/cmake/packaging/Linux.cmake`.

## Distribution package creation

A release build is needed before creating the distribution package. Packages **for a system** are created **on the system**.

### macOS

XCode should be used to create the release build for the application distributable.

```shell
cmake -GXCode -DCMAKE_BUILD_TYPE=Release -B build/xcode
cmake --build build/xcode
cpack --config build/xcode/CPackConfig.cmake
```

**Attention:** Creating the package will open a Finder window a couple of times to set the DMG window properties. This windows should be ignored and will auto-close.

### Windows & Linux

```shell
cmake -GNinja -DCMAKE_BUILD_TYPE=Release -B build/release
cmake --build build/release
cpack --config build/release/CPackConfig.cmake
```

***

Next up: [Platform dependent code](PlatformCode.md)
