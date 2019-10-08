#pragma once

#include "Logger.h"
#include "Application.h"

// Gloal macro definitions
#define exCoreInit()				ExCore::Logger::Initialise()
#define exCoreRunning()				ExCore::Application::isRunning()
#define exCoreSwap()				ExCore::Application::Swap()
#define exCoreDestroy()				ExCore::Application::Destroy()

// Window macro definitions
#define exCoreCreateWindow(...)		ExCore::Application::Create(__VA_ARGS__)

// Logging marco definitions
#define exLogInfo(...)				ExCore::Logger::PrintInfo(__VA_ARGS__)
#define exLogWar(...)				ExCore::Logger::PrintWar(__VA_ARGS__)
#define exLogErr(...)				ExCore::Logger::PrintErr(__VA_ARGS__)
#define exLogArr(...)				ExCore::Logger::PrintArr(__VA_ARGS__)