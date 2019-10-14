#pragma once

#include "Headers.h"

class Editor
{
private:
	static std::thread	_update_thread;

	static void StartUpdateThread();

	static void Initialise();
	static void Update();
	static void Render();
	static void Destroy();

public:
	static void Loop();
};