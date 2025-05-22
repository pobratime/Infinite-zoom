#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <stdexcept>

namespace infz {
class InfzWindow {
public:
  // constructor and destructor
  InfzWindow(int w, int h, std::string name);
  ~InfzWindow();

  // close funcion for loop
  bool ShouldClose();

private:
  // window and window paramaters
  GLFWwindow *window;
  const int width;
  const int height;
  const std::string name;
};
} // namespace infz
