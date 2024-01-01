#ifndef APPLICATION_H
#define APPLICATION_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "../Graphics/Mesh.h"
#include "../Graphics/Shader.h"
#include "../Graphics/SimpleObject.h"
#include "../Graphics/ShapeTypes.h"

#include "Camera.h"
#include "Config.h"
#include "InputHandler.h"

class Application {
public:
	Application();
	~Application();
	void run();

private:
	GLFWwindow* window;
	Shader* shader;
	Mesh* mesh;
	InputHandler* inputHandler;
	Camera* camera;
    std::vector<SimpleObject*> objects;
	float lastMouseX, lastMouseY;
	bool firstMouse = true;

	void init_GLFW();
	void init_GLEW();
	void init_input();
	void init_graphics();

	void handle_mouse_movement();
	void main_loop();
	void handle_input(float deltaTime);
	void create_object(ShapeTypes shape);

	void cleanup();
};

#endif
