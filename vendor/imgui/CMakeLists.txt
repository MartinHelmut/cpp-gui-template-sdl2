message(STATUS "Fetching imgui ...")

set(CMAKE_CXX_STANDARD 20)

FetchContent_GetProperties(imgui)
if (NOT imgui_POPULATED)
  FetchContent_Populate(imgui)
endif ()

if (__APPLE__)
  add_definitions(-DGL_SILENCE_DEPRECATION)

  find_library(COCOA_LIBRARY Cocoa)
  find_library(IOKIT_LIBRARY IOKit)
endif ()

add_library(imgui
  ${imgui_SOURCE_DIR}/imgui.cpp ${imgui_SOURCE_DIR}/imgui.h
  ${imgui_SOURCE_DIR}/imconfig.h ${imgui_SOURCE_DIR}/imgui_demo.cpp
  ${imgui_SOURCE_DIR}/imgui_draw.cpp ${imgui_SOURCE_DIR}/imgui_internal.h
  ${imgui_SOURCE_DIR}/imgui_tables.cpp ${imgui_SOURCE_DIR}/imgui_widgets.cpp
  ${imgui_SOURCE_DIR}/imstb_rectpack.h ${imgui_SOURCE_DIR}/imstb_textedit.h
  ${imgui_SOURCE_DIR}/imstb_truetype.h
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl.h ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer.h ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer.cpp)

target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})
target_link_libraries(imgui PUBLIC SDL2::SDL2)

FetchContent_MakeAvailable(imgui)
