#pragma once

#include "pch.h"
#include "ExCore.h"

namespace ExCore {
	class EXILE_CORE_API Logger
	{
		// TESTING
	public:
		static inline void PrintTest()
		{
			std::cout << "Print test!\n";
			system("PAUSE");
		}
	};
}