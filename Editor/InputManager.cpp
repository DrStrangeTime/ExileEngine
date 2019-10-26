#include "InputManager.h"
// Include a world class here for polling actor events...


void InputManager::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	ExCore::KeyInput::Update(key, scancode, action, mods);
}

void InputManager::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	ExCore::MouseInput::UpdateButton(button, action, mods);
}

void InputManager::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	ExCore::MouseInput::UpdatePosition(xpos, ypos);
}

void InputManager::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	ExCore::MouseInput::UpdateScroll(xoffset, yoffset);
}