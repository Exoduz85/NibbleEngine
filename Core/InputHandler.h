#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <unordered_map>
#include <GLFW/glfw3.h>

class InputHandler {
public:
	explicit InputHandler(GLFWwindow* window);
	~InputHandler();

	void clear();
	bool is_key_pressed(int key) const;
	bool is_key_held(int key) const;
	bool is_key_released(int key) const;
	bool is_mouse_button_pressed(int button) const;
	bool is_mouse_button_held(int button) const;
	bool is_mouse_button_released(int button) const;
	void get_mouse_position(double& x, double& y) const;
	
private:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static std::unordered_map<int, int> keys;
	static std::unordered_map<int, int> mouseButtons;
	static double mouseX;
	static double mouseY;
};

#endif // INPUTHANDLER_H
