#include "pch.h"
#include "InputEvent.h"

void ExCore::InputEvent::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	ExCore::KeyInput::Update(key, scancode, action, mods);
}

void ExCore::InputEvent::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	ExCore::MouseInput::Update(button, action, mods);
}
