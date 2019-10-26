#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "Headers.h"

/* Handles all of the key states for each device, including mouse and keyboard */
class InputManager
{
public:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffest, double yoffset);
};

#endif