message(STATUS "Fetching fmt ...")

option(FMT_INSTALL "Enable installation for the {fmt} project." OFF)

FetchContent_MakeAvailable(fmt)
