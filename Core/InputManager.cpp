#include "InputManager.h"

std::unordered_map<int, bool> InputManager::keysPressed;
std::unordered_map<int, bool> InputManager::keysHeld;
std::unordered_map<int, bool> InputManager::keysReleased;
std::unordered_map<int, bool> InputManager::mouseButtonsPressed;
std::unordered_map<int, bool> InputManager::mouseButtonsHeld;
std::unordered_map<int, bool> InputManager::mouseButtonsReleased;
double InputManager::mouseX = 0;
double InputManager::mouseY = 0;

InputManager::InputManager() : currentWindow(nullptr) {}

void InputManager::update() {
	clearReleasedStates();
}

void InputManager::clearReleasedStates() {
	keysReleased.clear();
	mouseButtonsReleased.clear();
}

void InputManager::setWindow(GLFWwindow* window) {
	currentWindow = window;
	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetCursorPosCallback(window, cursorPositionCallback);
}

bool InputManager::isKeyPressed(int key) const {
	return keysPressed.find(key) != keysPressed.end() && keysPressed.at(key);
}

bool InputManager::isKeyHeld(int key) const {
	return keysHeld.find(key) != keysHeld.end() && keysHeld.at(key);
}

bool InputManager::isKeyReleased(int key) const {
	return keysReleased.find(key) != keysReleased.end() && keysReleased.at(key);
}

bool InputManager::isMouseButtonPressed(int key) const {
	return mouseButtonsPressed.find(key) != mouseButtonsPressed.end() && mouseButtonsPressed.at(key);
}

bool InputManager::isMouseButtonHeld(int key) const {
	return mouseButtonsHeld.find(key) != mouseButtonsHeld.end() && mouseButtonsHeld.at(key);
}

bool InputManager::isMouseButtonReleased(int key) const {
	return mouseButtonsReleased.find(key) != mouseButtonsReleased.end() && mouseButtonsReleased.at(key);
}

void InputManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	switch(action)
	{
	case GLFW_PRESS:
		keysPressed[key] = true;
		keysHeld[key] = true;
		break;
	case GLFW_REPEAT:
		keysHeld[key] = true;
		break;
	case GLFW_RELEASE:
		keysReleased[key] = true;
		keysHeld[key] = false;
		break;
	}
}

void InputManager::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	switch(action)
	{
	case GLFW_PRESS:
		mouseButtonsPressed[button] = true;
		mouseButtonsHeld[button] = true;
		break;
	case GLFW_REPEAT:
		mouseButtonsHeld[button] = true;
		break;
	case GLFW_RELEASE:
		mouseButtonsPressed[button] = true;
		mouseButtonsHeld[button] = false;
		break;
	}
}

void InputManager::getMousePosition(double& x, double& y) const {
	x = mouseX;
	y = mouseY;
}

void InputManager::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	mouseX = xpos;
	mouseY = ypos;
}
