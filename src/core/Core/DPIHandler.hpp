/*
 * Copyright (c) 2023 Martin Helmut Fieber <info@martin-fieber.se>
 */

#pragma once

#include <SDL.h>
#include <imgui.h>

namespace App {

class DPIHandler {
 public:
  [[nodiscard]] static float get_scale();
  static void set_render_scale(SDL_Renderer* renderer);
  static void set_global_font_scaling(ImGuiIO* io);
};

}  // namespace App
