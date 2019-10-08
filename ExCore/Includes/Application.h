#pragma once

#include "pch.h"
#include "ExCore.h"
#include <glfw3.h>

namespace ExCore
{
	class EXILE_CORE_API Application
	{
	public:
		static int								width;
		static int								height;
		static const char*						title;
		static GLFWwindow*						window;

		static void Create(int width, int height, const char* title);
		static void Destroy();
		static void Swap();

		static bool isRunning();
	};
}