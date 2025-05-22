#include "infz_app.hpp"
#include <iostream>

namespace infz {

App::App() {
  std::cout << "app constructed" << std::endl;
}

App::~App() {
  // Clean up GLFW at the application level
  glfwTerminate();
  std::cout << "app destroyed" << std::endl;;
}

void App::run() {
  while (!infzWindow.ShouldClose()) {
    glfwPollEvents();
  }
}
} // namespace infz
