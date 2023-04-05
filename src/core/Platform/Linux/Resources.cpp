/*
 * Copyright (c) 2023 Martin Helmut Fieber <info@martin-fieber.se>
 */

#include <SDL.h>

#include "Core/Resources.hpp"

namespace App {

static const std::string BASE_PATH{SDL_GetBasePath()};

std::filesystem::path Resources::resource_path(const std::filesystem::path& file_path) {
  // @todo: Not yet verified.
  std::filesystem::path font_path{BASE_PATH};
  font_path /= file_path;
  return font_path;
}

std::filesystem::path Resources::font_path(const std::string_view& font_file) {
  return resource_path(font_file);
}

}  // namespace App
