set(NAME "App")

include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

set(STATIC_ASSETS
  ${PROJECT_SOURCE_DIR}/src/assets/icons/icon.icns
  ${PROJECT_SOURCE_DIR}/src/assets/fonts/Manrope.ttf)

# Info.plist file settings
set(MACOSX_EXECUTABLE_NAME ${NAME})
set(MACOSX_BUNDLE_ICON_FILE "icon")
set(MACOSX_DEPLOYMENT_TARGET "13.1")

set(CMAKE_BUILD_WITH_INSTALL_RPATH YES)

add_executable(${NAME} WIN32 MACOSX_BUNDLE App/Main.cpp ${STATIC_ASSETS})

install(TARGETS ${NAME}
  BUNDLE DESTINATION .
  FRAMEWORK DESTINATION ${NAME}.app/Contents/Frameworks)

# macOS package settings
set_source_files_properties(${STATIC_ASSETS} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
set_target_properties(${NAME} PROPERTIES
  XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
  MACOSX_BUNDLE_BUNDLE_VERSION "${BUILD_VERSION}"
  MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
  MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist"
  MACOSX_BUNDLE_GUI_IDENTIFIER "com.mycompany.app"
  MACOSX_BUNDLE_COPYRIGHT "(c) 2023 My Company"
  INSTALL_RPATH @executable_path/../Frameworks
  RESOURCE "${STATIC_ASSETS}")

# Copy DLL files on Windows to the target App build folder.
if (WIN32)
  add_custom_command(TARGET ${NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL2::SDL2>
    $<TARGET_FILE_DIR:${NAME}>)
endif ()

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${NAME} PRIVATE cxx_std_20)
target_link_libraries(${NAME} PRIVATE project_warnings Core)
