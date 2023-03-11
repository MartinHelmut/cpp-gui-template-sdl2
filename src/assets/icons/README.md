# Generate app icon sets

## macOS

To generate a `.icns` file on macOS, an `.iconset` folder needs to be converted via `iconutil`. The
folder `src/assets/icons/icon.iconset` contains all needed icon sizes. From inside the `src/assets/icons` folder run:

```shell
iconutil -c icns icon.iconset
```

## Windows

### App and install icon

To create the `icon.ico` file ImageMagick is used. From inside the `src/assets/icons` folder run:

```shell
convert windows/icon_16x16.png windows/icon_32x32.png windows/icon_64x64.png windows/icon_128x128.png windows/icon_256x256.png windows/icon_512x512.png icon.ico
```

Verify that the `icon.ico` was successfully created:

```shell
identify icon.ico
```

### Uninstall icon

To create the `uninstall_icon.ico` file ImageMagick is used. From inside the `src/assets/icons` folder run:

```shell
convert windows/uninstall_icon_16x16.png windows/uninstall_icon_32x32.png windows/uninstall_icon_64x64.png windows/uninstall_icon_128x128.png windows/uninstall_icon_256x256.png windows/uninstall_icon_512x512.png uninstall_icon.ico
```

Verify that the `uninstall_icon.ico` was successfully created:

```shell
identify uninstall_icon.ico
```

### NSIS installer images

The NSIS installer uses `.bmp` files for the UI images. To convert the appropriate images to `.bmp` files run the following command inside the `src/assets/icons` folder.

```shell
convert windows/nsis_header.png nsis_header.bmp && convert windows/nsis_install_welcome.png nsis_install_welcome.bmp && convert windows/nsis_uninstall_welcome.png nsis_uninstall_welcome.bmp
```
