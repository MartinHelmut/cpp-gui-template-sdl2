message(STATUS "==================================================")
message(STATUS "What the fuck why does this not execute!")
message(STATUS "==================================================")

set(CEF_URL "https://cef-builds.spotifycdn.com/cef_binary_108.4.13+ga98cd4c+chromium-108.0.5359.125_macosarm64.tar.bz2")

vcpkg_download_distfile(ARCHIVE
  URLS ${CEF_URL}
  FILENAME "cef.tar.bz2"
  SHA512 1f618116163ff6abfdb917b1cbe1cb04f0e6c1e045792419723b85b6d2a3ab158241c6eb0455452a88f43185e052bf49331f513c8fa129c3edcec9d80dcfadce
)

vcpkg_extract_source_archive_ex(
  OUT_SOURCE_PATH SOURCE_PATH
  ARCHIVE ${ARCHIVE}
)

file(COPY ${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt DESTINATION ${SOURCE_PATH})

vcpkg_configure_cmake(
  SOURCE_PATH ${SOURCE_PATH}
)

vcpkg_install_cmake()
vcpkg_copy_pdbs()

file(INSTALL "${SOURCE_PATH}/include" DESTINATION "${CURRENT_PACKAGES_DIR}")
file(INSTALL "${SOURCE_PATH}/Debug" "${SOURCE_PATH}/Release" "${SOURCE_PATH}/Resources" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}")
file(INSTALL "${SOURCE_PATH}/LICENSE.txt" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}" RENAME copyright)
