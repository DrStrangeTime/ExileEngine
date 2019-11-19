#include "pch.h"
#include "MouseInput.h"

void ExCore::MouseInput::UpdateButton(int button, int action, int mods)
{
	_current_button = button;
	
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

void ExCore::MouseInput::UpdatePosition(double xpos, double ypos)
{
	_ex_x = xpos;
	_ex_y = ypos;
}

void ExCore::MouseInput::UpdateScroll(double xoffset, double yoffset)
{
	if (yoffset > 0)
		_ex_scroll_state = 1;
	else
		_ex_scroll_state = -1;
}

double& ExCore::MouseInput::GetMouseX()
{
	return _ex_x;
}

double& ExCore::MouseInput::GetMouseY()
{
	return _ex_y;
}

double ExCore::MouseInput::GetMouseXNormalised(double width)
{
	return ((_ex_x / width) * 2) - 1;
}

double ExCore::MouseInput::GetMouseYNormalised(double height)
{
	return -(((_ex_y / height) * 2) - 1);
}

bool& ExCore::MouseInput::GetMouseLeftState()
{
	return _ex_mouse_left;
}

bool& ExCore::MouseInput::GetMouseMiddleState()
{
	return _ex_mouse_middle;
}

bool& ExCore::MouseInput::GetMouseRightState()
{
	return _ex_mouse_right;
}

int& ExCore::MouseInput::GetMouseScrollState()
{
	return _ex_scroll_state;
}

int& ExCore::MouseInput::GetMouseButtonState()
{
	return _current_button;
}

void ExCore::MouseInput::SetMouseX(double value)
{
	_ex_x = value;
}

void ExCore::MouseInput::SetMouseY(double value)
{
	_ex_y = value;
}

bool	ExCore::MouseInput::_ex_mouse_left;
bool	ExCore::MouseInput::_ex_mouse_right;
bool	ExCore::MouseInput::_ex_mouse_middle;
double	ExCore::MouseInput::_ex_x;
double	ExCore::MouseInput::_ex_y;
int		ExCore::MouseInput::_ex_scroll_state;
int		ExCore::MouseInput::_current_button;