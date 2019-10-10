#include "pch.h"
#include "MouseInput.h"

void ExCore::MouseInput::Update(int button, int action, int mods)
{
	if (GLFW_PRESS)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
			_ex_mouse_left = true;
		if (button == GLFW_MOUSE_BUTTON_RIGHT)
			_ex_mouse_right = true;
		if (button == GLFW_MOUSE_BUTTON_MIDDLE)
			_ex_mouse_middle = true;
	}
	else if (GLFW_RELEASE)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
			_ex_mouse_left = false;
		if (button == GLFW_MOUSE_BUTTON_RIGHT)
			_ex_mouse_right = false;
		if (button == GLFW_MOUSE_BUTTON_MIDDLE)
			_ex_mouse_middle = false;
	}
}

bool ExCore::MouseInput::_ex_mouse_left;
bool ExCore::MouseInput::_ex_mouse_right;
bool ExCore::MouseInput::_ex_mouse_middle;