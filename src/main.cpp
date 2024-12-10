#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <expected>
#include <print>

auto app_main() -> std::expected<int, std::string> {
  // init glfw
  glfwInit();
  // setup major version of opengl >3<.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  // setup minor version of opengl 3.>3<
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // explicitly use the core-profile, without backwards-compatible features
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

  if (window == NULL) {
    glfwTerminate();
    return std::unexpected("Failed to create GLFW window");
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    return std::unexpected("Failed to initialize GLAD");
  }

  return 0;
}

auto main() -> int {
  if (auto result = app_main(); result.has_value()) {
    return result.value();
  } else {
    std::println("Error: {}", result.error());
    return -1;
  }
}
