#ifndef __INPUT_EVENT_H__
#define __INPUT_EVENT_H__

#include "pch.h"
#include "KeyInput.h"
#include "MouseInput.h"

namespace ExCore
{
	class EXILE_CORE_API InputEvent
	{
	public:
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		static void scroll_callback(GLFWwindow* window, double xoffest, double yoffset);
	};
}

#endif