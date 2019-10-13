#include "pch.h"
#include "KeyInput.h"

bool& ExCore::KeyInput::GetKeyState(int key)
{
	return key_states[key];
}

void ExCore::KeyInput::Update(int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
		key_states[key] = true;
	else if (action == GLFW_RELEASE)
		key_states[key] = false;
}

bool ExCore::KeyInput::key_states[512];