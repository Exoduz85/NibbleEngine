#ifndef APPLICATION_H
#define APPLICATION_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "InputManager.h"
#include "../Graphics/Mesh.h"
#include "../Graphics/Shader.h"

class Application {
public:
	Application();
	~Application();
	void run();

private:
	GLFWwindow* window;
	Shader* shader;
	Mesh* mesh;
	InputManager* inputManager;
	
	void initGLFW();
	void initGLEW();
	void initInput();
	void initGraphics();
	void mainLoop();
	void cleanup();
};

#endif
