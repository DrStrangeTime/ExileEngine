#include "Object.h"

Object::Object() 
{
	_type = 0;
	_name = "Object";
}

Object::~Object() {}

uint8_t& Object::GetType()
{
	return _type;
}

std::string& Object::GetName()
{
	return _name;
}

void Object::SetType(uint8_t x)
{
	_type = x;
}

void Object::SetName(std::string x)
{
	_name = x;
}