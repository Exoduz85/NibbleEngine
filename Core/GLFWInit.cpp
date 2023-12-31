#include "GLFWInit.h"

GLFWwindow* init_GLFW() {
	if (!glfwInit()) {
		return nullptr;
	}

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "NibbleEngine", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		return nullptr;
	}

	glfwMakeContextCurrent(window);
	return window;
}
