#include "pch.h"
#include "Application.h"


int& ExCore::Application::GetWidth()
{
	return width;
}

int& ExCore::Application::GetHeight()
{
	return height;
}

const char* ExCore::Application::GetTitle()
{
	return title;
}

GLFWwindow* ExCore::Application::GetWindow()
{
	return window;
}

ExCore::RenderDevice::Properties& ExCore::Application::GetRenderDeviceProperties()
{
	return rdp;
}