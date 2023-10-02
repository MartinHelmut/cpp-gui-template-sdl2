message(STATUS "Fetching SDL ...")

option(SDL2_DISABLE_SDL2MAIN "Substitute for SDL_MAIN_HANDLED" ON)

FetchContent_MakeAvailable(SDL2)
