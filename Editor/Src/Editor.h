#pragma once

#include "Headers.h"

class Editor
{
public:
	static void Create();
	static void Destroy();
	static void Loop();

private:
	static void Update();
	static void Render();
};