# Application icons

## Generate app icons

### macOS

To generate a `.icns` file on macOS, an `.iconset` folder needs to be converted via `iconutil`. The
folder `src/assets/icons/icon.iconset` contains all needed icon sizes. To generate the needed app icon under `src/assets/icons/icon.icns`, run from inside the `src/assets/icons` folder:

```shell
iconutil -c icns icon.iconset
```

### Windows

To create the `icon.ico` file [ImageMagick](https://www.imagemagick.org) is used. From inside the `src/assets/icons` folder run:

```shell
convert \
  windows/icon_16x16.png windows/icon_32x32.png \
  windows/icon_64x64.png windows/icon_128x128.png \
  windows/icon_256x256.png windows/icon_512x512.png \
  icon.ico
```

Verify that the `icon.ico` was successfully created:

```shell
identify icon.ico
```

### Linux

There is no need to generate an icon set for Linux. A high resolution PNG (1024x1024px) is enough for the app icon. This is located under `icons/BaseAppIcon.png`.

## Icon design guidelines

The example project contains an example icon. To get guiding for creating an own unique app icon, here a couple of resources:

- [Windows app icon guidelines](https://learn.microsoft.com/en-us/windows/apps/design/style/iconography/app-icon-design)
- [Apple human interface design, icons guide](https://developer.apple.com/design/human-interface-guidelines/foundations/app-icons/)

## Integrating icons

How are those application icons connected to become the icon of the generated executable? Through the packaging process and manifest files.

### Package app icons

For macOS and Windows app icons are packed as static resources via CMake's [target_sources](https://cmake.org/cmake/help/latest/command/target_sources.html) function in `src/app/cmake/AppAssets.cmake`. For example, adding the Windows `.ico` file to the main executable:

```cmake
# src/app/cmake/AppAssets.cmake
target_sources(App PUBLIC ${PROJECT_SOURCE_DIR}/src/assets/icons/icon.ico)
```

On Linux, it needs to be part of the installation process that is defined in `src/app/cmake/packaging/Linux.cmake`, where application icons are installed in a shared directory `share/pixmaps`. This does look like the following:

```cmake
# src/app/cmake/packaging/Linux.cmake
install(FILES ${PROJECT_SOURCE_DIR}/src/assets/icons/BaseAppIcon.png
  DESTINATION share/pixmaps)
```

### Manifest files

The manifest files then link the app icon to the executable.

#### macOS

For macOS the manifest file is an [Info.plist](https://developer.apple.com/documentation/bundleresources/information_property_list) defining application properties. It is located at `src/app/Manifests/Info.plist` and added to the app bundle through `src/app/cmake/packaging/Darwin.cmake`. Here the CMake function [set_target_properties](https://cmake.org/cmake/help/latest/command/set_target_properties.html) defines `MACOSX_BUNDLE_INFO_PLIST` for the manifest location. The icon name is defined inside the `Info.plist` file under the property name `CFBundleIconFile`.

```cmake
# src/app/cmake/packaging/Darwin.cmake

# Reduced version of `set_target_properties` as example to set the manifest file.
set_target_properties(App PROPERTIES
  MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/Manifests/Info.plist")
```

#### Windows

The resource file `src/app/Manifests/app.rc` will bind the icon to the Windows executable. The resource file itself is then added as part of the application bundle via [target_sources](https://cmake.org/cmake/help/latest/command/target_sources.html) in `src/app/cmake/AppAssets.cmake`.

```cmake
target_sources(App PUBLIC
    ${PROJECT_SOURCE_DIR}/src/assets/icons/icon.ico
    ${PROJECT_SOURCE_DIR}/src/app/Manifests/app.rc)
```

#### Linux

For Linux a `src/app/Manifests/App.desktop.in` defines the created shortcut with icon. The `.in` file will be processed by CMake via [configure_file](https://cmake.org/cmake/help/latest/command/configure_file.html) in `src/app/cmake/packaging/Linux.cmake`.

It will take the `.in` file and produce a final `.desktop` file for Linux with the given icon name under the property `Icon=`.

```cmake
# src/app/cmake/packaging/Linux.cmake
configure_file(
  ${PROJECT_SOURCE_DIR}/src/app/Manifests/App.desktop.in
  ${CMAKE_CURRENT_BINARY_DIR}/App.desktop
  @ONLY)
```

The icon and the `.desktop` file then need to be installed.

```cmake
# src/app/cmake/packaging/Linux.cmake

# Install .desktop file under share/applications
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/App.desktop
  DESTINATION share/applications)

# Install icon file under share/pixmaps
install(FILES ${PROJECT_SOURCE_DIR}/src/assets/icons/BaseAppIcon.png
  DESTINATION share/pixmaps)
```

***

Next up: [Fonts](Fonts.md)
