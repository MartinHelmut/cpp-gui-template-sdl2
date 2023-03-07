# Generate app icon sets

## macOS

To generate a `.icns` file on macOS, an `.iconset` folder needs to be converted via `iconutil`. The
folder `src/assets/icons/icon.iconset` contains all needed icon sizes. From inside the `src/assets/icons` folder run:

```shell
iconutil -c icns icon.iconset
```
