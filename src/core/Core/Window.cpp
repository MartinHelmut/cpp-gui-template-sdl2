/*
 * Copyright (c) 2022-2023 Martin Helmut Fieber <info@martin-fieber.se>
 */

#include "Window.hpp"

#include "Core/Debug/Instrumentor.hpp"
#include "Core/Log.hpp"

namespace App {

Window::Window(const Settings& settings) {
  APP_PROFILE_FUNCTION();

  const auto window_flags{static_cast<SDL_WindowFlags>(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI)};
  constexpr int window_center_flag{SDL_WINDOWPOS_CENTERED};
  const float scale{get_scale()};

  const int window_dpi_scaled_width{static_cast<int>(settings.width * scale)};
  const int window_dpi_scaled_height{static_cast<int>(settings.height * scale)};

  m_window = SDL_CreateWindow(settings.title.c_str(),
      window_center_flag,
      window_center_flag,
      window_dpi_scaled_width,
      window_dpi_scaled_height,
      window_flags);

  auto renderer_flags{
      static_cast<SDL_RendererFlags>(SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED)};
  m_renderer = SDL_CreateRenderer(m_window, -1, renderer_flags);

  if (m_renderer == nullptr) {
    APP_ERROR("Error creating SDL_Renderer!");
    return;
  }

  SDL_RendererInfo info;
  SDL_GetRendererInfo(m_renderer, &info);
  APP_DEBUG("Current SDL_Renderer: {}", info.name);

  // Don't render scale on Windows.
  // SDL_RenderSetScale(m_renderer, scale, scale);
}

Window::~Window() {
  APP_PROFILE_FUNCTION();

  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
}

float Window::get_scale() const {
  const float default_dpi =
#ifdef __APPLE__
      72.0F;
#elif defined(_WIN32)
      96.0F;
#endif

  float dpi{default_dpi};
  constexpr int display_index{0};

  SDL_GetDisplayDPI(display_index, nullptr, &dpi, nullptr);

  return dpi / default_dpi;
}

SDL_Window* Window::get_native_window() const {
  return m_window;
}

SDL_Renderer* Window::get_native_renderer() const {
  return m_renderer;
}

}  // namespace App
