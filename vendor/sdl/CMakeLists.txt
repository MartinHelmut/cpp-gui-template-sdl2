message(STATUS "Fetching SDL ...")

set(SDL2_DISABLE_SDL2MAIN ON)

FetchContent_MakeAvailable(SDL2)
