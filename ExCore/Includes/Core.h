#ifndef __CORE_H__
#define __CORE_H__

#include "Logger.h"
#include "Application.h"

// Gloal macro definitions
#define exInit()					ExCore::Logger::Initialise()
//#define exRunning()					ExCore::Application::isRunning()
//#define exSwap()					ExCore::Application::Swap()
//#define exPollEvents()				ExCore::Application::PollEvents();
//#define exDestroy()					ExCore::Application::Destroy()

// Window macro definitions
//#define exCreateWindow(...)			ExCore::Application::Create(__VA_ARGS__)
//#define exGetScreenWidth()			ExCore::Application::GetWidth()
//#define exGetScreenHeight()			ExCore::Application::GetHeight()
//#define exGetWindowTitle()			ExCore::Application::GetTitle()
//#define exGetWindow()				ExCore::Application::GetWindow()

// Logging marco definitions
#define exLogInfo(...)				ExCore::Logger::PrintInfo(__VA_ARGS__)
#define exLogWar(...)				ExCore::Logger::PrintWar(__VA_ARGS__)
#define exLogErr(...)				ExCore::Logger::PrintErr(__VA_ARGS__)
#define exLogArr(...)				ExCore::Logger::PrintArr(__VA_ARGS__)

// Input macro definitions
//#define exGetKeyState(x)			ExCore::KeyInput::GetKeyState(x)
//#define exGetMouseScrollState()		ExCore::MouseInput::GetMouseScrollState()
//#define exGetMouseLeftState()		ExCore::MouseInput::GetMouseLeftState()
//#define exGetMouseMiddleState()		ExCore::MouseInput::GetMouseMiddleState()
//#define exGetMouseRightState()		ExCore::MouseInput::GetMouseRightState()
//#define exGetMouseX()				ExCore::MouseInput::GetMouseX()
//#define exGetMouseY()				ExCore::MouseInput::GetMouseY()

#endif