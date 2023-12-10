#include "GLFWInit.h"

GLFWwindow* initGLFW() {
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
