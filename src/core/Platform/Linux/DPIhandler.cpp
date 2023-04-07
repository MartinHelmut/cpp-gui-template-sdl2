#include "Core/DPIHandler.hpp"

#include "Core/Debug/Instrumentor.hpp"

namespace App {

float DPIHandler::get_scale() {
  APP_PROFILE_FUNCTION();

  constexpr int display_index{0};
  const float default_dpi{96.0F};
  float dpi{default_dpi};

  SDL_GetDisplayDPI(display_index, nullptr, &dpi, nullptr);

  return dpi / default_dpi;
}

WindowSize DPIHandler::get_dpi_aware_window_size(const Window::Settings& settings) {
  APP_PROFILE_FUNCTION();

  return {settings.width, settings.height};
}

void DPIHandler::set_render_scale([[maybe_unused]] SDL_Renderer* renderer) {
  APP_PROFILE_FUNCTION();
  // do nothing
}

void DPIHandler::set_global_font_scaling([[maybe_unused]] ImGuiIO* io) {
  APP_PROFILE_FUNCTION();
  // do nothing
}

}  // namespace App
