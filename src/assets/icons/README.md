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
