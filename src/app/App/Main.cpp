/*
 * Copyright (c) 2022 Martin Helmut Fieber <info@martin-fieber.se>
 */

#include "Core/Application.hpp"
#include "Core/Debug/Instrumentor.hpp"

int main(int /*unused*/, char** /*unused*/) {
  APP_PROFILE_BEGIN_SESSION_WITH_FILE("App", "profile.json");

  {
    APP_PROFILE_SCOPE("Test scope");
    App::Application app{"GUI Template"};
    app.run();
  }

  APP_PROFILE_END_SESSION();

  return 0;
}
