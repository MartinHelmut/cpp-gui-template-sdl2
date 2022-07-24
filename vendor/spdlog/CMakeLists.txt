message(STATUS "Fetching spdlog ...")

set(SPDLOG_FMT_EXTERNAL "ON")

FetchContent_MakeAvailable(spdlog)
