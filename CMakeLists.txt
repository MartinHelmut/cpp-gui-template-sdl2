cmake_minimum_required(VERSION 3.22)

include(cmake/UniversalAppleBuild.cmake)

project(
  BasicGuiProjectSetup
  DESCRIPTION "Base gui project setup."
  VERSION 1.0.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/StandardProjectSettings.cmake)
include(GNUInstallDirs)

# Link this "library" to use the warnings specified in CompilerWarnings.cmake.
add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

enable_testing()

add_subdirectory(vendor)
add_subdirectory(src)
add_subdirectory(packaging)
