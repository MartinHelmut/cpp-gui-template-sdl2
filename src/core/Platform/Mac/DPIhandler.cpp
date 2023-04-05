/*
 * Copyright (c) 2023 Martin Helmut Fieber <info@martin-fieber.se>
 */

#include "Core/DPIHandler.hpp"

#include <cmath>

namespace App {

float DPIHandler::get_scale() {
  constexpr int display_index{0};
  // @todo: This should be 72.0F on Mac, but it seems like it is not. I'm not
  //  sure why, but this works.
  const float default_dpi{96.0F};
  float dpi{default_dpi};

  SDL_GetDisplayDPI(display_index, nullptr, &dpi, nullptr);

  return std::floor(dpi / default_dpi);
}

void DPIHandler::set_render_scale(SDL_Renderer* renderer) {
  auto scale{get_scale()};
  SDL_RenderSetScale(renderer, scale, scale);
}

void DPIHandler::set_global_font_scaling(ImGuiIO* io) {
  io->FontGlobalScale = 1.0F / get_scale();
}

}  // namespace App
