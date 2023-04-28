#include <doctest/doctest.h>
#include <string>

// NOLINTBEGIN(misc-use-anonymous-namespace, cppcoreguidelines-avoid-do-while, cert-err33-c)

TEST_SUITE("Core::Resources") {
  TEST_CASE("Example") {
    const std::string input{"A"};
    CHECK_EQ(input, "A");
  }
}

// NOLINTEND(misc-use-anonymous-namespace, cppcoreguidelines-avoid-do-while, cert-err33-c)
