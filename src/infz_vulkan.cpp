#include "infz_vulkan.hpp"
#include <iostream>
#include <stdexcept>

namespace infz {

InfzVulkan::InfzVulkan() { initVulkan(); }

InfzVulkan::~InfzVulkan() { cleanupVulkan(); }

void InfzVulkan::initVulkan() { createInstance(); }

void InfzVulkan::cleanupVulkan() { vkDestroyInstance(instance, nullptr); }

void InfzVulkan::createInstance() {
  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "infinite-zoom";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  uint32_t glfwExtensionCount = 0;
  const char **glfwExtensions =
      glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  if (glfwExtensions == nullptr) {
    throw std::runtime_error("failed to get required GLFW extensions");
  }

  // this is a part that is required for macOS
  // FROM HERE
  std::vector<const char *> requiredExtensions;

  for (uint32_t i = 0; i < glfwExtensionCount; i++) {
    requiredExtensions.emplace_back(glfwExtensions[i]);
  }

  requiredExtensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

  createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;

  createInfo.enabledExtensionCount = (uint32_t)requiredExtensions.size();
  createInfo.ppEnabledExtensionNames = requiredExtensions.data();
  // TO HERE

  VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

  if (result != VK_SUCCESS) {
    throw std::runtime_error("failed to create vulkan instance");
  } else {
    std::cout << "vulkan instance created successfully" << std::endl;
  }
}

} // namespace infz