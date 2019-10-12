#ifndef __CORE_H__
#define __CORE_H__

#include "Logger.h"
#include "Application.h"

// Gloal macro definitions
#define exInit()					ExCore::Logger::Initialise()
#define exRunning()					ExCore::Application::isRunning()
#define exSwap()					ExCore::Application::Swap()
#define exPollEvents()				ExCore::Application::PollEvents();
#define exDestroy()					ExCore::Application::Destroy()

// Window macro definitions
#define exCreateWindow(...)			ExCore::Application::Create(__VA_ARGS__)

// Logging marco definitions
#define exLogInfo(...)				ExCore::Logger::PrintInfo(__VA_ARGS__)
#define exLogWar(...)				ExCore::Logger::PrintWar(__VA_ARGS__)
#define exLogErr(...)				ExCore::Logger::PrintErr(__VA_ARGS__)
#define exLogArr(...)				ExCore::Logger::PrintArr(__VA_ARGS__)

// Input macro definitions
#define exGetKeyState(x)			ExCore::KeyInput::GetKeyState(x)
#define exGetMouseScrollState(x)	ExCore::MouseInput::GetMouseScrollState(x)
#define exGetMouseLeftState(x)		ExCore::MouseInput::GetMouseLeftState(x)
#define exGetMouseMiddleState(x)	ExCore::MouseInput::GetMouseMiddleState(x)
#define exGetMouseRightState(x)		ExCore::MouseInput::GetMouseRightState(x)
#define exGetMouseX(x)				ExCore::MouseInput::GetMouseX(x)
#define exGetMouseY(x)				ExCore::MouseInput::GetMouseY(x)

#endif