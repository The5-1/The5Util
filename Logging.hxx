#pragma once

#include <stdio.h>

namespace the5 {
namespace util {

/* Quick Macro for printing something with __FILE__ and __LINE__
** https://stackoverflow.com/questions/15549893/modify-printfs-via-macro-to-include-file-and-line-number-information
*/

#define LOG(msg, ...) printf(msg "\nIn file %s line %u\n", __VA_ARGS__ , __FILE__, __LINE__);



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