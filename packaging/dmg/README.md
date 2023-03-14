# Generate icons

## Generate DMG background

To properly support Retina displays, a TIFF with a high DPI version needs to be created. From the project root run:

```shell
tiffutil \
  -cathidpicheck packaging/dmg/resources/AppDMGBackground.tiff \
  packaging/dmg/resources/AppDMGBackground@2x.tiff \
  -out packaging/dmg/AppDMGBackground.tiff
```
