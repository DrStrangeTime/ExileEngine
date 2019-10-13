#pragma once

#include "Headers.h"

class Editor
{
private:
	static std::thread	_update_thread;
	static std::mutex	_mutex;

	static void StartThread();

	static void Update();
	static void Render();

public:
	static void Create();
	static void Destroy();
	static void Loop();
};