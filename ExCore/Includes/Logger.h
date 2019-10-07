#pragma once

#include "pch.h"
#include "ExCore.h"

namespace ExCore {
	class EXILE_CORE_API Logger
	{
	public:
		static inline void PrintTest()
		{
			std::cout << "Initialised\n";
			system("PAUSE");
		}
	};
}