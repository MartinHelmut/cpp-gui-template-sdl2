# Usage Guide

This is the user guide for the template and how to adapt it to your own needs.

## Table of contents

- [Requirements](#requirements)
- [Quick Start](QuickStart.md)
- [Where is What?](WhereIsWhat.md)
- [Build and Execution](BuildAndExecution.md)
- [Testing](Testing.md)
- [Profiling](Profiling.md)
- [Logging](Logging.md)
- [Dependencies](Dependencies.md)
- [Packaging](Packaging.md)
- [Platform dependent code](PlatformCode.md)
- [Application Icons](ApplicationIcons.md)
- [Fonts](Fonts.md)
- [High DPI support](HighDPISupport.md)

***

## Requirements

### Git LFS

This template contains assets, specifically [icons and fonts](WhereIsWhat.md#static-assets). When starting a new project from a template it gets a clean history. Nevertheless, all assets should be stored through [Git Large File Storage (LFS)](https://git-lfs.com).

As preparation this template contains a `.gitattributes` marking all necessary files. **After project creation** from this template [git lfs migrate](https://github.com/git-lfs/git-lfs/wiki/Tutorial#migrating-existing-repository-data-to-lfs) should be executed. It requires Git LFS v2.2.1 or later to be installed.

Have a look at [Migrating existing repository data to LFS](https://github.com/git-lfs/git-lfs/wiki/Tutorial#migrating-existing-repository-data-to-lfs) for an in-depth how-to or run the following commands.

```shell
#
git lfs migrate import \
  --include="*.png" \
  --include="*.tiff" \
  --include="*.bmp" \
  --include="*.ico" \
  --include="*.icns" \
  --include="*.ttf"
git push --force
git reflog expire --expire-unreachable=now --all
git gc --prune=now
mv .gitattributes_example .gitattributes
```

### CMake & Ninja

The project uses [CMake](https://cmake.org) and [Ninja](https://ninja-build.org).

## Disclaimer

**Remark:** The SDL2 renderer does not support multi-viewport and detached widgets. For this you can have a look at the
[OpenGL version of this template](https://github.com/MartinHelmut/cpp-gui-template-sdl2-opengl).
