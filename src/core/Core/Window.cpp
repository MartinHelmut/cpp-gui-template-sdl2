#include "Window.hpp"

#include "Core/DPIHandler.hpp"
#include "Core/Debug/Instrumentor.hpp"
#include "Core/Log.hpp"

namespace App {

Window::Window(const Settings& settings) {
  APP_PROFILE_FUNCTION();

  const auto window_flags{
      static_cast<SDL_WindowFlags>(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI)};
  const WindowSize size{DPIHandler::get_dpi_aware_window_size(settings)};

  m_window = SDL_CreateWindow(settings.title.c_str(),
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      size.width,
      size.height,
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
  DPIHandler::set_render_scale(m_renderer);

  APP_DEBUG("Current SDL_Renderer: {}", info.name);
}

Window::~Window() {
  APP_PROFILE_FUNCTION();

  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
}

SDL_Window* Window::get_native_window() const {
  return m_window;
}

SDL_Renderer* Window::get_native_renderer() const {
  return m_renderer;
}

}  // namespace App
