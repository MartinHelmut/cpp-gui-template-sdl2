# Fonts

Applications fonts are in `src/assets/fonts`, and the template comes with the amazing open source font [Manrope](https://manropefont.com).

## Add new font

After adding a new font to the `src/assets/fonts` folder, the fonts needs to be added to ImGUI. This is done in `src/core/Core/Application.cpp`, the `run` method.

```c++
ExitStatus App::Application::run() {
  // other code ...

  // Get DPI scaling for high DPI display handling.
  const float font_scaling_factor{DPIHandler::get_scale()};

  // Sets the base font size, scaled relative to the monitor DPI.
  const float font_size{18.0F * font_scaling_factor};

  // Load the actual font file from resources.
  const std::string font_path{Resources::font_path("Manrope.ttf").generic_string()};

  // Add font to make it available for display.
  io.Fonts->AddFontFromFileTTF(font_path.c_str(), font_size);

  // Set default font file.
  io.FontDefault = io.Fonts->AddFontFromFileTTF(font_path.c_str(), font_size);

  // DPI handling.
  DPIHandler::set_global_font_scaling(&io);
}
```

***

Next up: [High DPI support](HighDPISupport.md)
