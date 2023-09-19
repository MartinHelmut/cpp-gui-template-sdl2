#include "Core/Application.hpp"
#include "Core/Debug/Instrumentor.hpp"
#include "Core/Log.hpp"

#include <nlohmann/json.hpp>
#include <fmt/printf.h>

void test_cef() {
  //
}

void test_json() {
  using json = nlohmann::json;
  const json ex1 = json::parse(R"(
    {
      "pi": 3.141,
      "happy": true
    }
  )");
  fmt::print("JSON: {}", ex1.dump());
}

int main() {
  try {
    APP_PROFILE_BEGIN_SESSION_WITH_FILE("App", "profile.json");

    {
      APP_PROFILE_SCOPE("Test scope");
      // App::Application app{"App"};
      // app.run();
    }

    // VCPKG Test
    {
      APP_PROFILE_SCOPE("VCPKG Test scope");
      test_json();
    }

    APP_PROFILE_END_SESSION();
  } catch (std::exception& e) {
    APP_ERROR("Main process terminated with: {}", e.what());
  }

  return 0;
}
