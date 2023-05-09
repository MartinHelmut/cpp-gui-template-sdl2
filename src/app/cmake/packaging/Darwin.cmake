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

# For distribution without XCode:
if (NOT "${CMAKE_GENERATOR}" STREQUAL "Xcode")
  install(FILES $<TARGET_FILE:SDL2::SDL2> DESTINATION ${APP_BUNDLE_PATH}/Contents/Frameworks/)
endif ()

# macOS package settings
string(TIMESTAMP CURR_YEAR "%Y")
set_target_properties(${NAME} PROPERTIES
  XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
  MACOSX_BUNDLE_BUNDLE_VERSION "${BUILD_VERSION}"
  MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
  MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/Manifests/Info.plist"
  MACOSX_BUNDLE_GUI_IDENTIFIER "${PROJECT_COMPANY_NAMESPACE}.${CMAKE_PROJECT_NAME}"
  MACOSX_BUNDLE_COPYRIGHT "(c) ${CURR_YEAR} ${PROJECT_COMPANY_NAME}"
  INSTALL_RPATH @executable_path/../Frameworks
  RESOURCE "${MACOSX_STATIC_ASSETS}")
