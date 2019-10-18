#pragma once

#include "RigidBody.h"

class Editor
{
private:
	static void Initialise();
	static void Event();
	static void Update();
	static void Render();
	static void Destroy();

public:
	static void Run();
};