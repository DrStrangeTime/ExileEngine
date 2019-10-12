#include "pch.h"
#include "Cursor.h"

void ExCore::Cursor::Initialise()
{

}

void ExCore::Cursor::CreateCustom(int w, int h, GLFWimage i)
{
	_cursor = glfwCreateCursor(&i, w, h);
}

int& ExCore::Cursor::GetWidth()
{
	return _width;
}

int& ExCore::Cursor::GetHeight()
{
	return _height;
}

GLFWcursor* ExCore::Cursor::GetCursor()
{
	return _cursor;
}


int				ExCore::Cursor::_width;
int				ExCore::Cursor::_height;
GLFWcursor*		ExCore::Cursor::_cursor;