set(NAME "App")

include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_executable(${NAME} WIN32 MACOSX_BUNDLE App/Main.cpp)

include(${PROJECT_SOURCE_DIR}/src/app/cmake/AppAssets.cmake)
include(${PROJECT_SOURCE_DIR}/src/app/cmake/Packaging.cmake)

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CEF_ROOT})
target_compile_features(${NAME} PRIVATE cxx_std_20)
target_link_libraries(${NAME} PRIVATE Core libcef_dll_wrapper)
