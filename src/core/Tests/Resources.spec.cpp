#include <doctest/doctest.h>
#include <string>

TEST_SUITE("Core::Resources") {
  TEST_CASE("Example") {
    const std::string input{"A"};
    CHECK_EQ(input, "A");
  }
}