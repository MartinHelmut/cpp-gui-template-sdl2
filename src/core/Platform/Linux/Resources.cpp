#include "Core/Resources.hpp"

#include <SDL2/SDL.h>

#include <filesystem>
#include <string>
#include <string_view>

#include "Core/Debug/Instrumentor.hpp"

namespace App {

static const std::string BASE_PATH{SDL_GetBasePath()};

std::filesystem::path Resources::resource_path(const std::filesystem::path& file_path) {
  APP_PROFILE_FUNCTION();

  std::filesystem::path font_path{BASE_PATH};
  font_path /= "../share";
  font_path /= "fonts" / file_path;
  return font_path;
}

std::filesystem::path Resources::font_path(const std::string_view& font_file) {
  APP_PROFILE_FUNCTION();

  return resource_path(font_file);
}

}  // namespace App
