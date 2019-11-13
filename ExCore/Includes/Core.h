#ifndef __CORE_H__
#define __CORE_H__

#include "Logger.h"
#include "Application.h"
#include "FixedTimestep.h"

// Gloal macro definitions
#define exInit()					ExCore::Logger::Initialise()

// Logging marco definitions
#define exLogInfo(...)				ExCore::Logger::PrintInfo(__VA_ARGS__)
#define exLogWar(...)				ExCore::Logger::PrintWar(__VA_ARGS__)
#define exLogErr(...)				ExCore::Logger::PrintErr(__VA_ARGS__)
#define exLogArr(...)				ExCore::Logger::PrintArr(__VA_ARGS__)

#define STATIC_CAST(cast_to, obj)		static_cast<cast_to>(obj)
#define DYNAMIC_CAST(cast_to, obj)		dynamic_cast<cast_to>(obj)
#define REINTERPRET_CAST(cast_to, obj)	reinterpret_cast<cast_to>(obj)
#define CONST_CAST(cast_to, obj)		const_cast<cast_to>(obj)

#endif