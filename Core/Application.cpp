#include "Application.h"
#include "Config.h"
#include "InputManager.h"
#include <iostream>

Application::Application() : window(nullptr), shader(nullptr), mesh(nullptr), inputManager(nullptr) {
	initGLFW();
	initGLEW();
	initInput();
	initGraphics();
}

Application::~Application() {
	cleanup();
}

void Application::run() {
	mainLoop();
}

void Application::initGLFW() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(1920, 1080, "NibbleEngine", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		std::cerr << "Failed to create GLFW window" << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
}

void Application::initGLEW() {
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
}

void Application::initInput()
{
	inputManager = new InputManager();
	inputManager->setWindow(window);
}

void Application::initGraphics() {
	shader = new Shader(Config::VertexShaderPath, Config::FragmentShaderPath);
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   
	};
	mesh = new Mesh(vertices, sizeof(vertices));
}

void Application::mainLoop() {
	while (!glfwWindowShouldClose(window)) {
		if (inputManager->isKeyPressed(GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}

		glClear(GL_COLOR_BUFFER_BIT);

		shader->use();
		mesh->Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
		inputManager->update();
	}
}

void Application::cleanup() {
	delete shader;
	delete mesh;
	if (window) {
		glfwDestroyWindow(window);
	}
	glfwTerminate();
}
