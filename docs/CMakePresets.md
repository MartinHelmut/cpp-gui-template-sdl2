# CMake Presets

The template uses [Cmake Presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html), enabling a
convenient way of running CMake, CTest, and CPack.

You can find out more about presets in
the [official CMake documentation about Presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html). I
also wrote an [article as a
TL;DR on CMake presets](https://martin-fieber.de/blog/cmake-presets/), giving an overview of how to define and work with
them.

## Configure

To list all available configure presets, some dependent on the current system:

```shell
cmake --list-presets
```

Run configure presets by name:

```shell
cmake --preset debug
```

## Build

To list all available build presets, some dependent on the current system:

```shell
cmake --build --list-presets
```

Run build presets by name:

```shell
cmake --build --preset debug
```

## Test

To list all available test presets:

```shell
ctest --list-presets
```

Run test presets by name, executing CTest:

```shell
ctest --preset all
```

## Packaging

To list all available packaging presets, some dependent on the current system:

```shell
cpack --list-presets
```

Run packaging presets by name, executing CPack:

```shell
cpack --preset release
```

## Workflows

To list all available workflows, some dependent on the current system:

```shell
cmake --workflow --list-presets
```

Run a workflow by name:

```shell
cmake --workflow --preset dist
```

***

Next up: [Platform dependent code](PlatformCode.md)
