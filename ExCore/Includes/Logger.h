#pragma once

#include "pch.h"
#include "ExCore.h"

#define TAG_EXT		static_cast<std::string>("EXILE")
#define INFO_EXT	static_cast<std::string>("INFO:")
#define WAR_EXT		static_cast<std::string>("WARNING:")
#define ERR_EXT		static_cast<std::string>("ERROR:")
#define ARR_EXT		static_cast<std::string>("ARRAY:")


namespace ExCore {

	/*	Logger contains utilities such including timestamp and text colour formatting.
		Templates are used for printing out different variable types.	*/

	class EXILE_CORE_API Logger
	{
	private:
		// Adjust text colour
		static void SetColour(unsigned short colour)
		{
			HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);	// Init handle
			SetConsoleTextAttribute(hcon, colour);	// Adjust console text attrib
		}

		// Get the current time and return string
		static inline std::string Timestamp()
		{
			time_t timer = time(NULL);	// Get current time
			struct tm tm_info;
			localtime_s(&tm_info, &timer);
			char time_buffer[26] = {};
			strftime(time_buffer, 26, "[%H:%M:%S]", &tm_info);		// Get current time in string form

			return time_buffer;	// return string
		}

		// Log a single line of information
		template<typename T>
		static inline void Log(T s, std::string l_ext, unsigned short colour)
		{
			SetColour(colour);
			std::string t = Timestamp();
			std::cout << t << " " << TAG_EXT << "::" << l_ext << " " << static_cast<T>(s) << std::endl;
			SetColour(7);
		}

	public:
		// Initialise logger
		static inline void Initialise()
		{
			const char* msg = { "Log system successfully initialised!" };
			PrintInfo(msg);
		}

		// Print formats
		template<typename T> static inline void PrintInfo(T s)	{ Log(s, INFO_EXT, 10); }
		template<typename T> static inline void PrintWar(T s)	{ Log(s, WAR_EXT, 14); }
		template<typename T> static inline void PrintErr(T s)	{ Log(s, ERR_EXT, 12); }

		// Print array of data
		template<typename T> static inline void PrintArray(T* s, size_t l, const char* n) 
		{ 
			std::cout << std::endl;

			std::string t = Timestamp();
			std::cout << t << " " << TAG_EXT << "::" << ARR_EXT << " ";
			SetColour(14);
			std::cout << n << std::endl;
			SetColour(7);

			for (size_t i = 0; i < l; i++)
				std::cout << "\t| " << i << "\t" << static_cast<T>(s[i]) << std::endl;

			std::cout << std::endl;
		}
	};

}