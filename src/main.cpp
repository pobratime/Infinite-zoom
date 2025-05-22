#include "infz_app.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>
#include <stdexcept>

int main() {
  try {
    infz::App app;
    app.run();
  } catch (const std::exception &e) {
    std::cerr << "error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}