#ifndef __CORE_H__
#define __CORE_H__

#include "Logger.h"
#include "Precision.h"
#include "Application.h"
#include "FixedTimestep.h"

// Gloal macro definitions
#define ExCoreInit()					ExCore::Logger::Initialise()

// Logging marco definitions
#define ExLogInfo(...)					ExCore::Logger::PrintInfo(__VA_ARGS__)
#define ExLogWar(...)					ExCore::Logger::PrintWar(__VA_ARGS__)
#define ExLogErr(...)					ExCore::Logger::PrintErr(__VA_ARGS__)
#define ExLogArr(...)					ExCore::Logger::PrintArray(__VA_ARGS__)

/* Input definitions */
#define ExGetMouseX()					ExCore::MouseInput::GetMouseX()
#define ExGetMouseY()					ExCore::MouseInput::GetMouseY()
#define ExGetMouseXNormalised(...)		ExCore::MouseInput::GetMouseXNormalised(__VA_ARGS__)
#define ExGetMouseYNormalised(...)		ExCore::MouseInput::GetMouseYNormalised(__VA_ARGS__)

/* Precision operators */
#define ExToRadians(...)				ExCore::Precision::ToRadians(__VA_ARGS__)		
#define ExToDegrees(...)				ExCore::Precision::ToDegrees(__VA_ARGS__)		

/* Redefinitions */
#define STATIC_CAST(cast_to, obj)		static_cast<cast_to>(obj)
#define DYNAMIC_CAST(cast_to, obj)		dynamic_cast<cast_to>(obj)
#define REINTERPRET_CAST(cast_to, obj)	reinterpret_cast<cast_to>(obj)
#define CONST_CAST(cast_to, obj)		const_cast<cast_to>(obj)
#define BUFFER_OFFSET(i)				((char*)(i))
#define TO_STRING(x)					std::to_string(x)

#endif