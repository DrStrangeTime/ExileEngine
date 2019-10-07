#pragma once

#ifndef EXILE_CORE_EXPORTS
	#define EXILE_CORE_API __declspec(dllexport)
#else
	#define EXILE_CORE_API __declspec(dllimport)
#endif

#include "Core.h"