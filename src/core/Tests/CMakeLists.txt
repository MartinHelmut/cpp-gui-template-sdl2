# Test cases

add_executable(ResourcesTest Resources.spec.cpp $<TARGET_OBJECTS:TestRunner>)
add_test(NAME ResourcesTest COMMAND ResourcesTest)
target_link_libraries(ResourcesTest PRIVATE doctest Core)
