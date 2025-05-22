#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

namespace infz {

class InfzVulkan {

public:
  // construct and destructor
  InfzVulkan();
  ~InfzVulkan();

  // function that will call other function for vulkan initialization
  void initVulkan();
  void cleanupVulkan();

private:
  void createInstance();
  VkInstance instance;

};

} // namespace infz