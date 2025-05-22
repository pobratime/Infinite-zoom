#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "infz_vulkan.hpp"
#include "infz_window.hpp"

namespace infz {
class App {
public:
  const int w = 800;
  const int h = 600;
  App();
  ~App();
  void run();

private:
  InfzWindow infzWindow{w, h, "infinite-zoom"};
  InfzVulkan infzVulkan{};
};
} // namespace infz