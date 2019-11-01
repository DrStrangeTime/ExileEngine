#include "ActionMapKeyboardEvent.h"

ActionMapKeyboardEvent::ActionMapKeyboardEvent(const char* name, uint32_t key, uint16_t state, uint16_t action)
{
	_name = name;
	_key = key;
	_state = state;
	_action = action;
}

uint32_t& ActionMapKeyboardEvent::GetKey()
{
	return _key;
}

bool ActionMapKeyboardEvent::isActive()
{
	return (ExCore::KeyInput::GetKeyState(_key));
}
