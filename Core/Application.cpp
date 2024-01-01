#include "Application.h"

using namespace std;

Application::Application() : window(nullptr), shader(nullptr), mesh(nullptr), inputHandler(nullptr), camera(nullptr) {
	init_GLFW();
	init_GLEW();
	init_input();
	init_graphics();
	lastMouseX = static_cast<float>(config::WindowWidth) * 0.5f;
	lastMouseY = static_cast<float>(config::WindowHeight) * 0.5f;
	firstMouse = true;
}

Application::~Application() {
	cleanup();
}

void Application::run() {
	main_loop();
}

void Application::init_GLFW() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(config::WindowWidth, config::WindowHeight, "NibbleEngine", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		std::cerr << "Failed to create GLFW window" << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSetWindowUserPointer(window, this);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); // visible for now

}

void Application::init_GLEW() {
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glEnable(GL_DEPTH_TEST);
}

void Application::init_input()
{
	inputHandler = new InputHandler(window);
}

void Application::init_graphics() {
	shader = new Shader(config::VertexShaderPath, config::FragmentShaderPath);
	camera = new Camera(
		glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);
}

void Application::create_object(ShapeTypes shape) {
    SimpleObject* newObject = new SimpleObject(shader, shape);
    objects.push_back(newObject);
}

void Application::handle_input(float deltaTime)
{
	if (inputHandler->is_key_just_pressed(GLFW_KEY_ESCAPE)) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	if (inputHandler->is_key_just_pressed(GLFW_KEY_1)) {
		cout << "Creating a cube!" << endl;
		create_object(ShapeTypes::Cube);
	}
	
	const float cameraSpeed = config::CameraSpeed * deltaTime;
	if (inputHandler->is_key_pressed_or_held(GLFW_KEY_W)) {
		camera->moveForward(cameraSpeed);
	}
	if (inputHandler->is_key_pressed_or_held(GLFW_KEY_S)) {
		camera->moveBackward(cameraSpeed);
	}
	if (inputHandler->is_key_pressed_or_held(GLFW_KEY_A)) {
		camera->moveLeft(cameraSpeed);
	}
	if (inputHandler->is_key_pressed_or_held(GLFW_KEY_D)) {
		camera->moveRight(cameraSpeed);
	}
	if (inputHandler->is_key_pressed_or_held(GLFW_KEY_Q)) {
		camera->moveDown(cameraSpeed);
	}
	if (inputHandler->is_key_pressed_or_held(GLFW_KEY_E)) {
		camera->moveUp(cameraSpeed);
	}
}

void Application::handle_mouse_movement() {
	float xPos, yPos = 0.0f;
	inputHandler->get_mouse_position(xPos, yPos);
	
	if (firstMouse) {
		lastMouseX = xPos;
		lastMouseY = yPos;
		firstMouse = false;
	}

	float xOffset = xPos - lastMouseX;
	float yOffset = lastMouseY - yPos;
	lastMouseX = xPos;
	lastMouseY = yPos;

	xOffset *= config::CameraSensitivity;
	yOffset *= config::CameraSensitivity;

	camera->rotate(xOffset, yOffset);
}

void Application::main_loop() {
	float lastFrameTime = 0;
	while (!glfwWindowShouldClose(window)) {
		const auto currentFrameTime = static_cast<float>(glfwGetTime());
		const float deltaTime = currentFrameTime - lastFrameTime;
		lastFrameTime = currentFrameTime;
		
		glfwPollEvents();
		handle_input(deltaTime);
		handle_mouse_movement();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
		
		shader->use();

		glm::mat4 view = camera->get_view_matrix();
		const float aspectRatio = static_cast<float>(config::WindowWidth) / static_cast<float>(config::WindowHeight);
		glm::mat4 projection = camera->get_projection_matrix(config::Fov, aspectRatio, config::NearPlane, config::FarPlane);

		shader->set_mat4("view", view);
		shader->set_mat4("projection", projection);

        for (const SimpleObject* obj : objects) {
            obj->draw();
        }

		glfwSwapBuffers(window);
		inputHandler->update();
	}
}

void Application::cleanup() {
    for (SimpleObject* obj : objects) {
        delete obj;
    }
	delete shader;
	delete mesh;
	delete camera;
    delete inputHandler;
	if (window) {
		glfwDestroyWindow(window);
	}
	glfwTerminate();
}
