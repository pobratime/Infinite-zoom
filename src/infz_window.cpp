#include "infz_window.hpp"

namespace infz {
InfzWindow::InfzWindow(int w, int h, std::string name)
    : width(w), height(h), name(name) {

  if (!glfwInit()) {
    throw std::runtime_error("failed to initialize glwf");
  }
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    throw std::runtime_error("failed to create a window");
  }
}

bool InfzWindow::ShouldClose() { return glfwWindowShouldClose(window); }

InfzWindow::~InfzWindow() { glfwDestroyWindow(window); }
} // namespace infz