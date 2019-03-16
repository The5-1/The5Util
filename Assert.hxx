#pragma once

#include <cstdio>
#include <cassert>

namespace the5 {
namespace util {

/* Modified Assert that uses __debugbreak() rather than abort().
** Allows passing a printf like statement.
*/

#ifdef NDEBUG
#	define ASSERT(condition, msg, ...) ((void)0)
#else
#	define ASSERT(condition, msg, ...) if (!(condition)) { printf("Assertion failed: %s " msg "\nIn file %s line %u\n", #condition, __VA_ARGS__, __FILE__, __LINE__); __debugbreak(); }
#endif

}
}