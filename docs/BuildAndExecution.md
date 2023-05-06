# Build and execution

## Configure

There are options that can be used to create the project configuration before build.

### `CMAKE_BUILD_TYPE`

Always needs to be set, usual values are `Debug`, `Release`, or `RelWithDebInfo` for the different build targets.

**Example:**

```shell
cmake -GNinja -DCMAKE_BUILD_TYPE=Debug -B build/debug
```

### `DEACTIVATE_LOGGING`

Can be set to stop the application from logging.

**Example:**

```shell
cmake -GNinja -DCMAKE_BUILD_TYPE=Debug -DDEACTIVATE_LOGGING -B build/debug
```

### `DEBUG`

Will not only enable application internal debugging, but also profiling (`APP_PROFILE`). This option is mainly useful to get debugging and profiling output on release builds.

**Example:**

```shell
cmake -GNinja -DCMAKE_BUILD_TYPE=Release -DDEBUG -B build/release
```

### `APP_PROFILE`

Enable profiling, useful for profiling a release build.

**Example:**

```shell
cmake -GNinja -DCMAKE_BUILD_TYPE=Release -DAPP_PROFILE -B build/release
```

### `WARNINGS_AS_ERRORS`

Treat compiler warnings as errors. This option is by default **true**. To disable set it to `FALSE`.

**Example:**

```shell
cmake -GNinja -DCMAKE_BUILD_TYPE=Debug -DWARNINGS_AS_ERRORS=FALSE -B build/debug
```

## Build

After configuration the application can be built through CMake via `cmake --build`, passing a build folder as argument.

**Example:**

```shell
cmake --build build/debug
```

This will build the application with the given configuration. Depending on the platform it was executed on a different build directory structure will be generated, reflecting how the application will latter be [installed on packaging](Packaging.md).

## Execute

When not running through an [IDE like CLion](https://www.jetbrains.com/clion), the built application can be run by directly executing the generated binary. Depending on the operating system it can be found at a different place, as different build directory structures are generated.

### macOS

On Apple devices an app package structure is created under `./build/<TARGET>/src/app/App.app`, where `<TARGET>` is the build target like **debug** or **release**. Inside that [application bundle](https://developer.apple.com/library/archive/documentation/CoreFoundation/Conceptual/CFBundles/AboutBundles/AboutBundles.html#//apple_ref/doc/uid/10000123i-CH100-SW1) is the app executable.

Run on a built target, in this example **debug**:

```shell
./build/debug/src/app/App.app/Contents/MacOS/App
```

Though, even better is to use **XCode as generator** to create app builds on macOS. Only difference in usage is running CMake with `-GXCode`. If `CMAKE_OSX_ARCHITECTURES` is not set, it will create universal binaries on M1/2 macs.

To run a **debug** build created with XCode:

```shell
./build/xcode/src/app/Debug/App.app/Contents/MacOS/App
```

To run a **release** build created with XCode:

```shell
./build/xcode/src/app/Release/App.app/Contents/MacOS/App
```

### Windows

To run a **debug** build:

```shell
build/debug/src/app/App.exe
```

To run a **release** build:

```shell
build/release/src/app/App.exe
```

### Linux

For Linux the generated structure is a direct executable, as libraries and assets have dedicated locations on the system.

Run on a built target, in this example **debug**:

```shell
./build/debug/src/app/App
```

***

Next up: [Testing](Testing.md)
