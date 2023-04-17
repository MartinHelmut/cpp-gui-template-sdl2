# General target installation settings
install(TARGETS ${NAME}
  BUNDLE DESTINATION .
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Settings for packaging per platform
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  include(${PROJECT_SOURCE_DIR}/src/app/cmake/packaging/Windows.cmake)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  include(${PROJECT_SOURCE_DIR}/src/app/cmake/packaging/Linux.cmake)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  include(${PROJECT_SOURCE_DIR}/src/app/cmake/packaging/Darwin.cmake)
endif ()
