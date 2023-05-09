# Where is what

Where to find what inside the project, from folder structure to configuration.

## Source code

All relevant source code is located in `src/`. The example setup is having one library, here called _"Core"_ under `src/core/`, and the application called _"App"_ under `src/app/`.

## Tests

The test setup is done under `src/tests/`. Test implementations are under the respective source code unit, e.g. App tests would be located under `src/app/Tests/`, where Core tests are located under `src/core/Tests/`.

## Static assets

Static assets like fonts and images are under `src/assets/`. This also includes all application icons in `src/assets/icons/`.

## Manifest files

Manifest files contain operating system dependent configuration. They all are located under `src/app/Manifests/`.

- `src/app/Manifests/Info.plist` - Apple properties file ([ref](https://developer.apple.com/library/archive/documentation/General/Reference/InfoPlistKeyReference/Articles/AboutInformationPropertyListFiles.html#//apple_ref/doc/uid/TP40009254-SW1))
- `src/app/Manifests/App.manifest` - Windows manifest file ([ref](https://learn.microsoft.com/en-us/windows/win32/sbscs/application-manifests))
- `src/app/Manifests/app.rc` - Windows resource file ([ref](https://learn.microsoft.com/en-us/windows/win32/menurc/about-resource-files))
- `src/app/Manifests/App.desktop.in` - Linux app icon configuration ([ref](https://specifications.freedesktop.org/desktop-entry-spec/desktop-entry-spec-latest.html))

## Dependencies

Generally dependencies are located in `vendor/`. The `vendor/CMakeLists.txt` uses CMake's [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) to load dependencies on configure time. Every dependency also has an associated folder containing a `CMakeLists.txt` for configuration.

## Configurations

### Project

General CMake project settings are defined under `cmake/StandardProjectSettings.cmake`, containing build types and compiler flags.

### Compiler

Compiler warnings for all platforms are defined in `cmake/CompilerWarnings.cmake`.

### Static analyzers

Clang Tidy and Address Sanitizer setup is located in `cmake/StaticAnalyzers.cmake`. Clang-tidy is configured through `.clang-tidy`.

### Code format

In the root of the project a `.clang-format` together with the `.editorconfig` define the code style of the project.

### Apple build

To configure how to build for Apple Silicon or Intel the `cmake/UniversalAppleBuild.cmake` defines the behavior on release builds.

### Packaging

The main configuration to create distributable packages is in `packaging/`. Besides general files it also contains platform dependent resources.

- `packaging/dmg/` - Apple DMG files
- `packaging/nsis/` - Windows NSIS files

Under `src/app/cmake/` are specific packaging files for the main executable.

***

Next up: [Make it your own](MakeItYourOwn.md)
