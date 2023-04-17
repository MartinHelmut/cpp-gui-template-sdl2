#include "Core/DPIHandler.hpp"

#include <cmath>

#include "Core/Debug/Instrumentor.hpp"

namespace App {

float DPIHandler::get_scale() {
  APP_PROFILE_FUNCTION();

  constexpr int display_index{0};
  // @todo: This should be 72.0F on Mac, but it seems like it is not. I'm not
  //  sure why, but this works ¯\_(ツ)_/¯
  const float default_dpi{96.0F};
  float dpi{default_dpi};

  SDL_GetDisplayDPI(display_index, nullptr, &dpi, nullptr);

  return std::floor(dpi / default_dpi);
}

WindowSize DPIHandler::get_dpi_aware_window_size(const Window::Settings& settings) {
  APP_PROFILE_FUNCTION();

  return {settings.width, settings.height};
}

void DPIHandler::set_render_scale(SDL_Renderer* renderer) {
  APP_PROFILE_FUNCTION();

  auto scale{get_scale()};
  SDL_RenderSetScale(renderer, scale, scale);
}

void DPIHandler::set_global_font_scaling(ImGuiIO* io) {
  APP_PROFILE_FUNCTION();

  io->FontGlobalScale = 1.0F / get_scale();
}

}  // namespace App
