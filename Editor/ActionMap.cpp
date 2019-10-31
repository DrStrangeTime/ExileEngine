#include "ActionMap.h"

ActionMap::ActionMap(const char* name, unsigned int key, unsigned int action)
{
	_name = name;
	Map(key, action);
}

const char* ActionMap::GetName()
{
	return _name;
}

unsigned int ActionMap::GetKey()
{
	return _key;
}

unsigned int ActionMap::GetAction()
{
	return _action;
}

void ActionMap::SetName(const char* name)
{
	_name = name;
}

void ActionMap::SetKey(unsigned int key)
{
	_key = key;
}

void ActionMap::SetAction(unsigned int action)
{
	_action = action;
}

void ActionMap::Map(unsigned int key, unsigned int action)
{
	_key = key;
	_action = action;
}
