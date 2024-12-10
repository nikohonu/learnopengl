#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <expected>
#include <print>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  std::println("{} {}", width, height);
  glViewport(0, 0, width, height);
}

void process_input(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

auto app_main() -> std::expected<int, std::string> {
  const auto width = 800;
  const auto height = 600;

  // init glfw
  glfwInit();
  // setup major version of opengl >3<.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  // setup minor version of opengl 3.>3<
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // explicitly use the core-profile, without backwards-compatible features
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  auto window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);

  if (window == NULL) {
    glfwTerminate();
    return std::unexpected("Failed to create GLFW window");
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    return std::unexpected("Failed to initialize GLAD");
  }

  glViewport(0, 0, width, height);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  while (!glfwWindowShouldClose(window)) {
    // process input
    process_input(window);

    // render
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // check events and swap buffers
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();

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
