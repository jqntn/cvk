#define GLFW_INCLUDE_NONE

#include "cvk.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

static void
error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

static void
key_callback(GLFWwindow* p_window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(p_window, GLFW_TRUE);
  }
}

int
main(void)
{
  if (EOF == puts("hi")) {
    exit(EXIT_FAILURE);
  }

  if (GLFW_FALSE == glfwInit()) {
    exit(EXIT_FAILURE);
  }

  glfwSetErrorCallback(error_callback);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);

  GLFWwindow* p_window = glfwCreateWindow(720, 480, "", NULL, NULL);
  if (NULL == p_window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwSetKeyCallback(p_window, key_callback);

  glfwMakeContextCurrent(p_window);
  glfwSwapInterval(1);

  while (GLFW_FALSE == glfwWindowShouldClose(p_window)) {
    glfwSwapBuffers(p_window);
    glfwPollEvents();
  }

  glfwDestroyWindow(p_window);
  glfwTerminate();

  return EXIT_SUCCESS;
}