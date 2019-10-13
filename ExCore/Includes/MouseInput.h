#ifndef __MOUSE_INPUT_H__
#define __MOUSE_INPUT_H__

#include "ExCore.h"

namespace ExCore
{
	class EXILE_CORE_API MouseInput
	{
	private:
		static bool		_ex_mouse_left;
		static bool		_ex_mouse_right;
		static bool		_ex_mouse_middle;

		static double	_ex_x;
		static double	_ex_y;
		
		static int		_ex_scroll_state;
	
	public:
		static void		UpdateButton(int button, int action, int mods);
		static void		UpdatePosition(double xpos, double ypos);
		static void		UpdateScroll(double xoffset, double yoffset);

		static double&	GetMouseX();
		static double&	GetMouseY();

		static bool&	GetMouseLeftState();
		static bool&	GetMouseMiddleState();
		static bool&	GetMouseRightState();

		static int&		GetMouseScrollState();
	};
}

#endif