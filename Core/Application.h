#ifndef APPLICATION_H
#define APPLICATION_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Config.h"
#include <iostream>

#include "../Graphics/Mesh.h"
#include "../Graphics/Shader.h"
#include "../Graphics/SimpleObject.h"
#include "../Graphics/ShapeTypes.h"

#include "Camera.h"
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

    void create_object(ShapeTypes shape);
	void init_GLFW();
	void init_GLEW();
	void init_input();
	void init_graphics();
	void main_loop();
	void cleanup();
};

#endif
