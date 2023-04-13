set(NAME "App")

include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

set(SHARED_STATIC_ASSETS ${PROJECT_SOURCE_DIR}/src/assets/fonts/Manrope.ttf)

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
endif ()

add_executable(${NAME} WIN32 MACOSX_BUNDLE App/Main.cpp)

# Add platform specific static assets
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_sources(${NAME} PUBLIC
    ${SHARED_STATIC_ASSETS}
    ${PROJECT_SOURCE_DIR}/src/assets/icons/icon.ico
    ${PROJECT_SOURCE_DIR}/src/app/Manifests/app.rc
    ${PROJECT_SOURCE_DIR}/src/app/Manifests/App.manifest)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(MACOSX_STATIC_ASSETS
    ${SHARED_STATIC_ASSETS}
    ${PROJECT_SOURCE_DIR}/src/assets/icons/icon.icns)
  set_source_files_properties(${MACOSX_STATIC_ASSETS}
    PROPERTIES MACOSX_PACKAGE_LOCATION ${CMAKE_INSTALL_DATADIR})
  target_sources(${NAME} PUBLIC ${MACOSX_STATIC_ASSETS})
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  target_sources(${NAME} PRIVATE ${SHARED_STATIC_ASSETS})
endif ()

install(TARGETS ${NAME}
  BUNDLE DESTINATION .
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  # Use main entry for Windows GUI app.
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /subsystem:windows /entry:mainCRTStartup")

  # Copy .dll files on Windows/Linux to the target App build folder.
  # For development:
  add_custom_command(TARGET ${NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL2::SDL2>
    $<TARGET_FILE_DIR:${NAME}>)

  # For distribution:
  install(FILES $<TARGET_FILE:SDL2::SDL2> DESTINATION ${CMAKE_INSTALL_BINDIR})

  # Copy assets into app bundle
  # For development:
  add_custom_command(TARGET ${NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/src/assets
    $<TARGET_FILE_DIR:${NAME}>/../share)

  # For distribution:
  install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/assets/ DESTINATION ${CMAKE_INSTALL_DATADIR})
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  # Copy .so files on Windows/Linux to the target App build folder.
  # For development:
  add_custom_command(TARGET ${NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL2::SDL2>
    $<TARGET_FILE_DIR:${NAME}>)

  # For distribution:
  install(FILES $<TARGET_FILE:SDL2::SDL2> DESTINATION ${CMAKE_INSTALL_BINDIR})

  # Copy assets into app bundle
  # For development:
  add_custom_command(TARGET ${NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/src/assets
    $<TARGET_FILE_DIR:${NAME}>/../share)

  # For distribution:
  install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/assets/ DESTINATION ${CMAKE_INSTALL_DATADIR})

  # Linux app icon setup
  install(FILES ${PROJECT_SOURCE_DIR}/src/app/Manifests/App.desktop
    DESTINATION share/applications)
  install(FILES ${PROJECT_SOURCE_DIR}/src/assets/icons/BaseAppIcon.png
    DESTINATION share/pixmaps)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  # Info.plist file settings
  set(MACOSX_EXECUTABLE_NAME ${NAME})
  set(MACOSX_BUNDLE_ICON_FILE "icon")
  set(MACOSX_DEPLOYMENT_TARGET "13.1")

  # XCode generates build directories with build types inside.
  if ("${CMAKE_GENERATOR}" STREQUAL "Xcode")
    set(APP_BUNDLE_PATH "${CMAKE_BUILD_TYPE}/${NAME}.app")
  else ()
    set(APP_BUNDLE_PATH "${NAME}.app")
  endif ()

  # Get dynamic SDL2 lib into Frameworks folder in app bundle.
  # For development:
  add_custom_command(TARGET ${NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL2::SDL2>
    ${APP_BUNDLE_PATH}/Contents/Frameworks/$<TARGET_FILE_NAME:SDL2::SDL2>)

  # For distribution:
  install(FILES $<TARGET_FILE:SDL2::SDL2> DESTINATION ${APP_BUNDLE_PATH}/Contents/Frameworks/)

  # macOS package settings
  string(TIMESTAMP CURR_YEAR "%Y")
  set_target_properties(${NAME} PROPERTIES
    XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
    MACOSX_BUNDLE_BUNDLE_VERSION "${BUILD_VERSION}"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
    MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/Manifests/Info.plist"
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.mycompany.app"
    MACOSX_BUNDLE_COPYRIGHT "(c) ${CURR_YEAR} My Company"
    INSTALL_RPATH @executable_path/../Frameworks
    RESOURCE "${MACOSX_STATIC_ASSETS}")
endif ()

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${NAME} PRIVATE cxx_std_20)
target_link_libraries(${NAME} PRIVATE project_warnings Core)
