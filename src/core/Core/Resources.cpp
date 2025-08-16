#include "Core/Resources.hpp"

#include <sys/stat.h>

#include <filesystem>

#include "Core/Debug/Instrumentor.hpp"

namespace App {

bool Resources::exists(const std::filesystem::path& pathname) {
  APP_PROFILE_FUNCTION();

  struct stat buffer;
  return (stat(pathname.generic_string().c_str(), &buffer) == 0);
}

}  // namespace App
