cmake_minimum_required(VERSION 4.0.2)
project(infinite_zoom_vulkan VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(
  infinite_zoom_vulkan
  src/main.cpp
)

target_include_directories(
  infinite_zoom_vulkan
  PRIVATE
  dependencies
)

target_link_libraries(
  infinite_zoom_vulkan
  glfw
  Vulkan::Vulkan
)
