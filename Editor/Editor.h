#pragma once

#include "Actor.h"

class Editor
{
private:
	static void Initialise();
	static void Update();
	static void Render();
	static void Destroy();

public:
	static void Run();
};