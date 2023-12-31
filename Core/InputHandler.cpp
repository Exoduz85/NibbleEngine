#include "InputHandler.h"

std::unordered_map<int, int> InputHandler::keys;
std::unordered_map<int, int> InputHandler::mouseButtons;
double InputHandler::mouseX;
double InputHandler::mouseY;

InputHandler::InputHandler(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
}

void InputHandler::clear()
{
	keys.clear();
	mouseButtons.clear();
}


bool InputHandler::is_key_pressed(int key) const
{
	return keys[key] == 1 || keys[key] == 2;
}

bool InputHandler::is_key_held(int key) const
{
	return keys[key] == 2;
}

bool InputHandler::is_key_released(int key) const
{
	return keys[key] == 0;
}

bool InputHandler::is_mouse_button_pressed(int button) const
{
	return mouseButtons[button] == 1 || mouseButtons[button] == 2;
}

bool InputHandler::is_mouse_button_held(int button) const
{
	return mouseButtons[button] == 2;
}

bool InputHandler::is_mouse_button_released(int button) const
{
	return mouseButtons[button] == 0;
}

void InputHandler::get_mouse_position(double& x, double& y) const
{
	x = mouseX;
	y = mouseY;
}

void InputHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	keys[key] = action;
}

void InputHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	mouseButtons[button] = action;
}

void InputHandler::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	mouseX = xpos;
	mouseY = ypos;
}

InputHandler::~InputHandler() = default;
