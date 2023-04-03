set(NAME "App")

include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

set(STATIC_ASSETS
  ${PROJECT_SOURCE_DIR}/src/assets/icons/icon.ico
  ${PROJECT_SOURCE_DIR}/src/app/app.rc
  ${PROJECT_SOURCE_DIR}/src/app/App.manifest
  ${PROJECT_SOURCE_DIR}/src/assets/icons/icon.icns
  ${PROJECT_SOURCE_DIR}/src/assets/fonts/Manrope.ttf)

set_source_files_properties(${STATIC_ASSETS}
  PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

# Info.plist file settings
set(MACOSX_EXECUTABLE_NAME ${NAME})
set(MACOSX_BUNDLE_ICON_FILE "icon")
set(MACOSX_DEPLOYMENT_TARGET "13.1")

set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)

add_executable(${NAME} WIN32 MACOSX_BUNDLE App/Main.cpp ${STATIC_ASSETS})

install(TARGETS ${NAME}
  BUNDLE DESTINATION .
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  # Use main entry for Windows GUI app.
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /subsystem:windows /entry:mainCRTStartup")

  # Copy DLL files on Windows to the target App build folder.
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
    ${CMAKE_SOURCE_DIR}/src/assets
    $<TARGET_FILE_DIR:${NAME}>/../share)

  # For distribution:
  install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/assets/ DESTINATION ${CMAKE_INSTALL_DATADIR})
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
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
endif ()

# macOS package settings
string(TIMESTAMP CURR_YEAR "%Y")
set_target_properties(${NAME} PROPERTIES
  XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
  MACOSX_BUNDLE_BUNDLE_VERSION "${BUILD_VERSION}"
  MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
  MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist"
  MACOSX_BUNDLE_GUI_IDENTIFIER "com.mycompany.app"
  MACOSX_BUNDLE_COPYRIGHT "(c) ${CURR_YEAR} My Company"
  INSTALL_RPATH @executable_path/../Frameworks
  RESOURCE "${STATIC_ASSETS}")

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${NAME} PRIVATE cxx_std_20)
target_link_libraries(${NAME} PRIVATE project_warnings Core)
