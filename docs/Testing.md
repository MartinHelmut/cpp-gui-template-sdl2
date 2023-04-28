# Testing

## Setup

The repo uses [Doctest](https://github.com/doctest/doctest) for testing. The dependency to Doctest is defined in `vendor/CMakeLists.txt` and configured in `vendor/doctest/CMakeLists.txt`.

The setup of the test runner is done in `src/tests/` through `src/tests/TestRunner.cpp`.

In general, tests are located **close to the associated source code**. That means for example the tests for the Core library `src/core/Core/` are located in `src/core/Tests/`.

## Creation

Let's create the test setup for _App_. Add a new _Tests_ folder to app including a CMake file `src/app/Tests/CMakeLists.txt`.

```cmake
# src/app/Tests/CMakeLists.txt

# Tests will be defined here ...
```

Include the new test directory in the apps CMake file:

```cmake
# src/app/CMakeLists.txt

# All other App CMake code ...

add_subdirectory(Tests)
```

A new test is a combination of an entry in the tests CMake file and a C++ file containing the actual test. In this example, inside the `src/app/Tests/CMakeLists.txt` file a new test is adding an executable, declaring the test and linking Doctest plus any other required dependencies.

The example test defines a new test named `AppTest`, using `App.spec.cpp` as test file. The `$<TARGET_OBJECTS:TestRunner>` [CMake generator expression](https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html) includes the test runner.

It then declares a test with `add_test` and links doctest and Core as dependencies through `target_link_libraries`.

```cmake
# src/app/Tests/CMakeLists.txt
add_executable(AppTest App.spec.cpp $<TARGET_OBJECTS:TestRunner>)
add_test(NAME AppTest COMMAND AppTest)
target_link_libraries(AppTest PRIVATE doctest Core)
```

The test file `App.spec.cpp` will include the actual test suite. In this case an example test. The `NOLINT` comments are for clang-tidy to accept Doctest, and are only defined at the start and end of a test file.

```c++
#include <doctest/doctest.h>
#include <string>

// NOLINTBEGIN(misc-use-anonymous-namespace, cppcoreguidelines-avoid-do-while, cert-err33-c)

TEST_SUITE("App") {
  TEST_CASE("Example") {
    const std::string input{"A"};
    CHECK_EQ(input, "A");
  }
}

// NOLINTEND(misc-use-anonymous-namespace, cppcoreguidelines-avoid-do-while, cert-err33-c)
```

## Execution

Before being able to run tests they need to be built. Either have a look at the [Quick Start guide for building](QuickStart.md#build) or try running the following command.

```shell
cmake --build build/debug
```

Then you can run all tests from the build target. Executing the App test will look something like this:

```shell
$ ctest --test-dir build/debug

Internal ctest changing into directory: /Projects/_templates/cpp-gui-template-sdl2/build/debug
Test project /Projects/_templates/cpp-gui-template-sdl2/build/debug
    Start 1: AppTest
1/1 Test #1: AppTest ....................   Passed    0.06 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.07 sec
```

This can also be done through an IDE like CLion, usually providing an _"All Tests"_ target configuration that will work out of the box.

***

Next up: [Profiling](Profiling.md)
