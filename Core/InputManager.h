#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <GLFW/glfw3.h>
#include <unordered_map>

class InputManager {
public:
	InputManager();
	~InputManager();

	void update();
	void setWindow(GLFWwindow* window);

	bool isKeyPressed(int key) const;
	bool isKeyHeld(int key) const;
	bool isKeyReleased(int key) const;

	bool isMouseButtonPressed(int button) const;
	bool isMouseButtonHeld(int button) const;
	bool isMouseButtonReleased(int button) const;

	void getMousePosition(double& x, double& y) const;

	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

private:
	GLFWwindow* currentWindow;
	static std::unordered_map<int, bool> keysPressed;
	static std::unordered_map<int, bool> keysHeld;
	static std::unordered_map<int, bool> keysReleased;
	static std::unordered_map<int, bool> mouseButtonsPressed;
	static std::unordered_map<int, bool> mouseButtonsHeld;
	static std::unordered_map<int, bool> mouseButtonsReleased;
	static double mouseX, mouseY;

	void clearReleasedStates();
};

#endif // INPUTMANAGER_H
