/*
 * Copyright (c) 2022-2023 Martin Helmut Fieber <info@martin-fieber.se>
 */

#include "Application.hpp"

#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer.h>
#include <imgui.h>

#include "Core/Debug/Instrumentor.hpp"

namespace App {

Application::Application(const std::string& title) {
  APP_PROFILE_FUNCTION();

  const unsigned int init_flags{SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER};
  if (SDL_Init(init_flags) != 0) {
    APP_ERROR("Error: %s\n", SDL_GetError());
    m_exit_status = ExitStatus::FAILURE;
  }

  m_window = std::make_unique<Window>(Window::Settings{title});
}

Application::~Application() {
  APP_PROFILE_FUNCTION();

  ImGui_ImplSDLRenderer_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();

  SDL_Quit();
}

ExitStatus App::Application::run() {
  APP_PROFILE_FUNCTION();

  if (m_exit_status == ExitStatus::FAILURE) {
    return m_exit_status;
  }

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io{ImGui::GetIO()};

  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_DockingEnable |
                    ImGuiConfigFlags_ViewportsEnable;

  const std::string user_config_path{SDL_GetPrefPath("com.mycompany", "app")};
  APP_DEBUG("User config path: {}", user_config_path);

  // Absolute imgui.ini path to preserve settings independent of app location.
  static const std::string imgui_ini_filename{user_config_path + "imgui.ini"};
  io.IniFilename = imgui_ini_filename.c_str();

  // ImGUI font
  const float font_scaling_factor{m_window->get_scale()};
  const float font_size{18.0F * font_scaling_factor};
  std::string font_path{SDL_GetBasePath()};
  font_path.append("Manrope.ttf");

  io.Fonts->AddFontFromFileTTF(font_path.c_str(), font_size);
  io.FontDefault = io.Fonts->AddFontFromFileTTF(font_path.c_str(), font_size);
  io.FontGlobalScale = 1.0F / font_scaling_factor;

  // Setup Platform/Renderer backends
  ImGui_ImplSDL2_InitForSDLRenderer(m_window->get_native_window(), m_window->get_native_renderer());
  ImGui_ImplSDLRenderer_Init(m_window->get_native_renderer());

  m_running = true;
  while (m_running) {
    APP_PROFILE_SCOPE("MainLoop");

    SDL_Event event{};
    while (SDL_PollEvent(&event) == 1) {
      APP_PROFILE_SCOPE("EventPolling");

      ImGui_ImplSDL2_ProcessEvent(&event);

      if (event.type == SDL_QUIT) {
        stop();
      }

      if (event.type == SDL_WINDOWEVENT &&
          event.window.windowID == SDL_GetWindowID(m_window->get_native_window())) {
        on_event(event.window);
      }
    }

    // Start the Dear ImGui frame
    ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    if (!m_minimized) {
      ImGui::DockSpaceOverViewport();

      if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
          if (ImGui::MenuItem("Exit", "Cmd+Q")) {
            stop();
          }
          ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("View")) {
          ImGui::MenuItem("Some Panel", nullptr, &m_show_some_panel);
          ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
      }

      // Whatever GUI to implement here ...
      if (m_show_some_panel) {
        ImGui::Begin("Some panel", &m_show_some_panel);
        ImGui::Text("Hello World");
        ImGui::End();
      }
    }

    // Rendering
    ImGui::Render();

    SDL_SetRenderDrawColor(m_window->get_native_renderer(), 100, 100, 100, 255);
    SDL_RenderClear(m_window->get_native_renderer());
    ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
    SDL_RenderPresent(m_window->get_native_renderer());
  }

  return m_exit_status;
}

void App::Application::stop() {
  m_running = false;
}

void Application::on_event(const SDL_WindowEvent& event) {
  switch (event.event) {
    case SDL_WINDOWEVENT_CLOSE:
      return on_close();
    case SDL_WINDOWEVENT_MINIMIZED:
      return on_minimize();
    case SDL_WINDOWEVENT_SHOWN:
      return on_shown();
  }
}

void Application::on_minimize() {
  m_minimized = true;
}

void Application::on_shown() {
  m_minimized = false;
}

void Application::on_close() {
  stop();
}

}  // namespace App
