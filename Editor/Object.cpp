#include "Object.h"

Object::Object() 
{
	_name = "Object";
}

std::string& Object::GetName()
{
	return _name;
}

void Object::SetName(std::string x)
{
	_name = x;
}