#ifndef __MOUSE_INPUT_H__
#define __MOUSE_INPUT_H__

#include "ExCore.h"

namespace ExCore
{
	class EXILE_CORE_API MouseInput
	{
	private:
		static bool _ex_mouse_left;
		static bool _ex_mouse_right;
		static bool _ex_mouse_middle;
	
	public:
		static void Update(int button, int action, int mods);
	};
}

#endif