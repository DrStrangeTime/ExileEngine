#include "ActionMap.h"

bool& ActionMap::GetState()
{
	return _state;
}

const char* ActionMap::GetName()
{
	return _name;
}

uint16_t& ActionMap::GetAction()
{
	return _action;
}