#include "Core/DPIHandler.hpp"

namespace App {

float DPIHandler::get_scale() {
  constexpr int display_index{0};
  const float default_dpi{96.0F};
  float dpi{default_dpi};

  SDL_GetDisplayDPI(display_index, nullptr, &dpi, nullptr);

  return dpi / default_dpi;
}

void DPIHandler::set_render_scale([[maybe_unused]] SDL_Renderer* renderer) {
  // do nothing
}

void DPIHandler::set_global_font_scaling([[maybe_unused]] ImGuiIO* io) {
  // do nothing
}

}  // namespace App
