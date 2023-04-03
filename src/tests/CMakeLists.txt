set(NAME "TestRunner")

add_library(${NAME} OBJECT ${PROJECT_SOURCE_DIR}/src/tests/TestRunner.cpp)
target_compile_features(${NAME} PRIVATE cxx_std_20)
target_link_libraries(${NAME} PUBLIC doctest)
