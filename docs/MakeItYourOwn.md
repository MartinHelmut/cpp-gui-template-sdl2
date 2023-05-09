# Make it your own

There are some variables and settings that should be adapted to specific project needs.

## Project name and company

Inside the root `CMakeLists.txt`, the CMake [project](https://cmake.org/cmake/help/latest/command/project.html) call also defines the project name as `CMAKE_PROJECT_NAME` variable. This is currently called `BasicGuiProjectSetup`. Here an example how this could look like:

```cmake
# CMakeLists.txt
project(
  MySuperAppName
  DESCRIPTION "This is a crazy good app."
  VERSION 1.0.0
  LANGUAGES CXX)
```

In that same file, the **project company name and namespace** ([Reverse domain name notation](https://en.wikipedia.org/wiki/Reverse_domain_name_notation)) are defined.

```cmake
# CMakeLists.txt

# ...

set(PROJECT_COMPANY_NAME "My Company")
set(PROJECT_COMPANY_NAMESPACE "com.mycompany")  # Reverse domain name notation
```

## App icons

App icons are located under `src/assets/icons/`. There is dedicated documentation on how to update and integrate those into the project under [Application Icons](ApplicationIcons.md).

## Installer graphics

The installer on macOS and Windows are graphical and use some images to properly represent the app. Images and documentation for macOS are in `packaging/dmg/`, same for Windows under `packaging/nsis/`.

## Code of conduct

There is a basic Code of Conduct (CoC) provided by https://www.contributor-covenant.org in `CODE_OF_CONDUCT.md`. Search for `EMAIL` inside that document to provide a contact for the CoC.

***

Next up: [Build and Execution](BuildAndExecution.md)
