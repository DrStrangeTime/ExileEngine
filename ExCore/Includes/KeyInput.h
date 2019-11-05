#ifndef __KEY_INPUT_H__
#define __KEY_INPUT_H__

#include "ExCore.h"

namespace ExCore
{
	class EXILE_CORE_API KeyInput
	{
	private:
		static bool key_states[512];

	public:
		static bool& GetKeyState(int key);
		static void UpdateKey(int key, int scancode, int action, int mods);
	};
}

#endif