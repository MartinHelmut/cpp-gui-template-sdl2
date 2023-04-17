# Assets for all platforms
set(SHARED_STATIC_ASSETS ${PROJECT_SOURCE_DIR}/src/assets/fonts/Manrope.ttf)

# Platform specific static assets
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
