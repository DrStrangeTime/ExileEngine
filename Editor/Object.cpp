#include "Object.h"

Object::Object() 
{
	_type = 0;
	_active = true;
	_name = "";
}

uint8_t& Object::GetType()
{
	return _type;
}

bool& Object::GetActive()
{
	return _active;
}

std::string& Object::GetName()
{
	return _name;
}

void Object::SetType(uint8_t x)
{
	_type = x;
}

void Object::SetActive(bool x)
{
	_active = x;
}

void Object::SetName(std::string x)
{
	_name = x;
}