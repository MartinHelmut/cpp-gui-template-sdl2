#pragma once

#include <SDL.h>

#include <string>

namespace App {

class Window {
 public:
  struct Settings {
    std::string title;
    const int width{1280};
    const int height{720};
  };

  explicit Window(const Settings& settings);
  ~Window();

  Window(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(Window other) = delete;
  Window& operator=(Window&& other) = delete;

  [[nodiscard]] SDL_Window* get_native_window() const;
  [[nodiscard]] SDL_Renderer* get_native_renderer() const;

 private:
  SDL_Window* m_window{nullptr};
  SDL_Renderer* m_renderer{nullptr};
};

}  // namespace App
