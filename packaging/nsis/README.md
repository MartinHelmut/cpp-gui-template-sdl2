# NSIS images

## Uninstall icon

To create the `uninstall_icon.ico` file ImageMagick is used. From inside the `packaging/nsis` folder run:

```shell
convert resources/uninstall_icon_16x16.png resources/uninstall_icon_32x32.png resources/uninstall_icon_64x64.png resources/uninstall_icon_128x128.png resources/uninstall_icon_256x256.png resources/uninstall_icon_512x512.png uninstall_icon.ico
```

Verify that the `uninstall_icon.ico` was successfully created:

```shell
identify uninstall_icon.ico
```

## Installer images

The NSIS installer uses `.bmp` files for the UI images, specifically BPM Windows 3.x format. To convert the appropriate images to `.bmp` files run the following command inside the `packaging/nsis` folder.

```shell
convert resources/nsis_header.png BMP3:nsis_header.bmp && convert resources/nsis_install_welcome.png BMP3:nsis_install_welcome.bmp && convert resources/nsis_uninstall_welcome.png BMP3:nsis_uninstall_welcome.bmp
```
