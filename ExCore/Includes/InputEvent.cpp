#include "pch.h"
#include "InputEvent.h"

void ExCore::InputEvent::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	ExCore::KeyInput::Update(key, scancode, action, mods);
}

void ExCore::InputEvent::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	ExCore::MouseInput::UpdateButton(button, action, mods);
}

void ExCore::InputEvent::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	ExCore::MouseInput::UpdatePosition(xpos, ypos);
}

void ExCore::InputEvent::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	ExCore::MouseInput::UpdateScroll(xoffset, yoffset);
}