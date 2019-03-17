#pragma once

#include <cstdio>
#include <cstdarg>
#include <cassert>

namespace the5 {
	namespace logging {

#define LOG_MIN_LEVEL 0

#define LOG_FILE_AND_LINE_FORMAT "\n\tIn file %s line %u\n"

		enum Level {
			Trace,
			Debug,
			Info,
			Warning,
			Error,
			Assert,
		};

		const char* const LevelString[] = { "Trace", "Debug", "Info", "Warning", "Error", "Assert" };


		/* Passing Arguments to printf
		** https://stackoverflow.com/questions/1056411/how-to-pass-variable-number-of-arguments-to-printf-sprintf
		*/
		void Log_(Level level, const char * const msg, ...) {
			va_list argptr;
			va_start(argptr, msg);
			printf("%-8s", LevelString[level]);
			vprintf(msg, argptr);
			va_end(argptr);
		}

		/* Macros for printing something with __FILE__ and __LINE__
		** https://stackoverflow.com/questions/15549893/modify-printfs-via-macro-to-include-file-and-line-number-information
		*/

#if 0 >= LOG_MIN_LEVEL 
#	define TRACE(msg, ...) the5::logging::Log_(the5::logging::Level::Trace, msg LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ , __FILE__, __LINE__);
#endif

#if 1 >= LOG_MIN_LEVEL 
#	define LOG(msg, ...) the5::logging::Log_(the5::logging::Level::Debug, msg LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ , __FILE__, __LINE__);
#endif

#if 2 >= LOG_MIN_LEVEL 
#	define INFO(msg, ...) the5::logging::Log_(the5::logging::Level::Info, msg LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ , __FILE__, __LINE__);
#endif

#if 3 >= LOG_MIN_LEVEL 
#define WARNING(msg, ...) the5::logging::Log_(the5::logging::Level::Warning, msg LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ , __FILE__, __LINE__);
#endif

#if 4 >= LOG_MIN_LEVEL 
#	define ERROR(msg, ...) the5::logging::Log_(the5::logging::Level::Error, msg LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ , __FILE__, __LINE__);
#endif

#if 5 >= LOG_MIN_LEVEL && !defined(NDEBUG)
#	define ASSERT(condition, msg, ...) if (!(condition)){the5::logging::Log_(the5::logging::Level::Assert, msg LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ , #condition, __FILE__, __LINE__);__debugbreak(); }
#endif
}

namespace util{


/*
//old implementation
//https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
//#include <Windows.h> //for coloring console output 

#ifndef LOG(x)
#define LOG(x) do { \
					HANDLE  hConsole;  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole, 8);\
					std::cerr << x << std::endl;\
					SetConsoleTextAttribute(hConsole, 15);\
				  } while (0)
#endif // !LOG(x)


#ifndef ERR(x)
	#define ERR(x) do { \
						HANDLE  hConsole;  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole, 12);\
						std::cerr << "ERROR:\t"<< x  << "\n\tError in Funcion \"" << __func__ << "()\" Line " <<__LINE__<< "\n\tCode File: " << __FILE__ << std::endl; \
						SetConsoleTextAttribute(hConsole, 15);\
					  } while (0)
#endif // !ERR(x)


#ifndef ERR_GL(x)
#define ERR_GL(x) do { \
						HANDLE  hConsole;  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole, 13 + 4*16);\
						std::cerr << "OpenGL:\t"<< x  << "\n\tError in Funcion \"" << __func__ << "()\" Line " <<__LINE__<< "\n\tCode File: " << __FILE__ << std::endl; \
						SetConsoleTextAttribute(hConsole, 15);\
					  } while (0)
#endif // !ERR_GL(x)
*/

}
}