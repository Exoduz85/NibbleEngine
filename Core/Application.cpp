#include "Application.h"

using namespace std;

Application::Application() : window(nullptr), shader(nullptr), mesh(nullptr), inputHandler(nullptr), camera(nullptr) {
	init_GLFW();
	init_GLEW();
	init_input();
	init_graphics();
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
}

void Application::init_GLEW() {
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
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

void Application::create_object() {
    std::vector<Vertex> newVertices = {
        { glm::vec3(0.0f,  0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f) },
        { glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f) },
        { glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f) }
    };

    std::vector<unsigned int> newIndices = {
            0, 1, 2
    };

    Mesh* newMesh = new Mesh(newVertices, newIndices);
    SimpleObject* newObject = new SimpleObject(newMesh);
    objects.push_back(newObject);
}

void Application::main_loop() {
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		if (inputHandler->is_key_pressed(GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (inputHandler->is_key_pressed(GLFW_KEY_1)) {
            cout << "Creating a new object!" << endl;
            create_object();
        }

		shader->use();

		glm::mat4 view = camera->get_view_matrix();
		float aspectRatio = static_cast<float>(config::WindowWidth) / static_cast<float>(config::WindowHeight);
		glm::mat4 projection = camera->get_projection_matrix(config::Fov, aspectRatio, config::NearPlane, config::FarPlane);

		shader->set_mat4("view", view);
		shader->set_mat4("projection", projection);

        for (SimpleObject* obj : objects) {
            obj->draw();
        }

		glfwSwapBuffers(window);
		inputHandler->clear();
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
