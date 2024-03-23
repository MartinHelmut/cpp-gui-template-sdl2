if (NOT CMAKE_BUILD_TYPE STREQUAL "Release")
  find_program(CLANGTIDY clang-tidy)
  if (CLANGTIDY)
    message(STATUS "Using clang-tidy, found ${CLANGTIDY}")
    set(CMAKE_CXX_CLANG_TIDY "${CLANGTIDY};-extra-arg=-Wno-unknown-warning-option")
    # Explicitly enable exceptions on Windows
    if (WIN32)
      set(CMAKE_CXX_CLANG_TIDY "${CMAKE_CXX_CLANG_TIDY};--extra-arg=/EHsc")
    endif ()
  else ()
    message(WARNING "clang-tidy requested but executable not found")
  endif ()

  # This will gradually increase memory usage of the program,
  # discovered on Apple M1, 13.0.
  if (NOT WIN32)
    message(STATUS "Using address sanitizer")
    add_compile_options(-O0 -fsanitize=address -g)
    add_link_options(-O0 -fsanitize=address -g)
  endif ()
endif ()
