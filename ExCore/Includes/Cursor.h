#ifndef __CURSOR_H__
#define __CURSOR_H__

#include "pch.h"
#include "ExCore.h"

namespace ExCore
{
	class EXILE_CORE_API Cursor
	{
	private:
		static int							_width;
		static int							_height;
		static GLFWcursor*					_cursor;

	public:
		static void							Initialise();
		static void							CreateCustom(int w, int h, GLFWimage i);

		static void							Assign(GLFWcursor* c);

		static int&							GetWidth();
		static int&							GetHeight();
		static GLFWcursor*					GetCursor();
	};
}

#endif