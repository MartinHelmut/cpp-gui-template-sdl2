set(NAME "SomeLibrary")

include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_library(${NAME} STATIC
  SomeLibrary/Core/Log.cpp SomeLibrary/Core/Log.hpp
  SomeLibrary/Debug/Instrumentor.hpp)

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${NAME} PRIVATE cxx_std_20)
target_link_libraries(${NAME} PRIVATE project_warnings PUBLIC fmt spdlog)
