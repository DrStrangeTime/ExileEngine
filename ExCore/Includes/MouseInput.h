#ifndef __MOUSE_INPUT_H__
#define __MOUSE_INPUT_H__

#include "ExCore.h"

namespace ExCore
{
	class EXILE_CORE_API MouseInput
	{
	private:
		static int		_current_button;

		static bool		_ex_mouse_left;
		static bool		_ex_mouse_right;
		static bool		_ex_mouse_middle;

		static double	_ex_x;
		static double	_ex_y;
		static double	_ex_x_offset;
		static double	_ex_y_offset;
		static double	_ex_x_last;
		static double	_ex_y_last;

		static int		_ex_scroll_state;
	
	public:
		static void		UpdateButton(int button, int action, int mods);
		static void		UpdatePosition(double xpos, double ypos);
		static void		UpdateScroll(double xoffset, double yoffset);

		static double&	GetMouseX();
		static double&	GetMouseY();
		static double&	GetMouseXOffset();
		static double&	GetMouseYOffset();
		static double&	GetMouseXLast();
		static double&	GetMouseYLast();

		static double	GetMouseXNormalised(double width);
		static double	GetMouseYNormalised(double height);

		static bool&	GetMouseLeftState();
		static bool&	GetMouseMiddleState();
		static bool&	GetMouseRightState();

		static int&		GetMouseScrollState();
		static int&		GetMouseButtonState();

		static void		SetMouseXOffset(double value);
		static void		SetMouseYOffset(double value);
		static void		SetMouseXLast(double value);
		static void		SetMouseYLast(double value);
	};
}

#endif