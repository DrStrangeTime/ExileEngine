#include "ActionMapMouseEvent.h"

ActionMapMouseEvent::ActionMapMouseEvent(const char* name, uint16_t button, uint16_t state, uint16_t action)
{
	_name = name;
	_button = button;
	_state = state;
	_action = action;
}

uint16_t& ActionMapMouseEvent::GetButton()
{
	return _button;
}

bool ActionMapMouseEvent::isActive()
{
	if (_button == GLFW_MOUSE_BUTTON_LEFT)
		return (_state == GLFW_PRESS);
	else if (_button == GLFW_MOUSE_BUTTON_RIGHT)
		return (_state == GLFW_PRESS);
	else if (_button == GLFW_MOUSE_BUTTON_MIDDLE)
		return (_state == GLFW_PRESS);

	return false;
}
