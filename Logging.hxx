#pragma once

#include <cstdio>
#include <cstdarg>
#include <cassert>

namespace the5 {
namespace logging {

/* User Options
** Do not re-define if user defined them elsewhere
*/
#ifndef LOG_MIN_LEVEL
#	define LOG_MIN_LEVEL 0
#endif// !LOG_MIN_LEVEL

#ifndef LOG_SHOW_LINE_NUMBER
#	define LOG_SHOW_LINE_NUMBER 1
#endif // !LOG_SHOW_LINE_NUMBER

#if LOG_SHOW_LINE_NUMBER > 0
#	define LOG_FILE_AND_LINE_FORMAT "\n\tIn file %s line %u\n"
#	define LOG_FILE_AND_LINE_PARAMS ,__FILE__ ,__LINE__
#else
#	define LOG_FILE_AND_LINE_FORMAT "\n"
#	define LOG_FILE_AND_LINE_PARAMS
#endif


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
	inline void Log_(Level level, const char * const msg, ...) {
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
#	define TRACE(msg, ...) the5::logging::Log_(the5::logging::Level::Trace, msg LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ LOG_FILE_AND_LINE_PARAMS);
#endif

#if 1 >= LOG_MIN_LEVEL 
#	define LOG(msg, ...) the5::logging::Log_(the5::logging::Level::Debug, msg LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ LOG_FILE_AND_LINE_PARAMS);
#endif

#if 2 >= LOG_MIN_LEVEL 
#	define INFO(msg, ...) the5::logging::Log_(the5::logging::Level::Info, msg LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ LOG_FILE_AND_LINE_PARAMS);
#endif

#if 3 >= LOG_MIN_LEVEL 
#define WARNING(msg, ...) the5::logging::Log_(the5::logging::Level::Warning, msg LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ LOG_FILE_AND_LINE_PARAMS);
#endif

#if 4 >= LOG_MIN_LEVEL 
#	define ERROR(msg, ...) the5::logging::Log_(the5::logging::Level::Error, msg LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ LOG_FILE_AND_LINE_PARAMS);
#endif

#if 5 >= LOG_MIN_LEVEL && !defined(NDEBUG)
#	define ASSERT(condition, msg, ...) if(!(condition)){the5::logging::Log_(the5::logging::Level::Assert, msg "\n\tAssertion Failed: %s" LOG_FILE_AND_LINE_FORMAT, __VA_ARGS__ , #condition LOG_FILE_AND_LINE_PARAMS);__debugbreak();}
#endif

}
}