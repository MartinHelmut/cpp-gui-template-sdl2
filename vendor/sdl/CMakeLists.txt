message(STATUS "Fetching SDL ...")

option(SDL2_DISABLE_SDL2MAIN "Disable building/installation of SDL2main" ON)

FetchContent_MakeAvailable(SDL2)
