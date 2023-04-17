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
configure_file(
  ${PROJECT_SOURCE_DIR}/src/app/Manifests/App.desktop.in
  ${CMAKE_CURRENT_BINARY_DIR}/App.desktop
  @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/App.desktop
  DESTINATION share/applications)
install(FILES ${PROJECT_SOURCE_DIR}/src/assets/icons/BaseAppIcon.png
  DESTINATION share/pixmaps)
