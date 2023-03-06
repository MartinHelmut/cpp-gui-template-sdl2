message(STATUS "Fetching Doctest ...")

set(DOCTEST_NO_INSTALL ON)

FetchContent_MakeAvailable(doctest)
