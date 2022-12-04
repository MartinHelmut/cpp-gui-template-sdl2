set(NAME "Core")

include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_library(${NAME} STATIC
  Core/Log.cpp Core/Log.hpp Core/Debug/Instrumentor.hpp
  Core/Application.cpp Core/Application.hpp Core/Window.cpp Core/Window.hpp)

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${NAME} PRIVATE cxx_std_20)

if(MINGW)
  target_link_libraries(${NAME} PUBLIC mingw32)
endif()

target_link_libraries(${NAME}
  PRIVATE project_warnings
  PUBLIC fmt spdlog SDL2::SDL2 imgui)
