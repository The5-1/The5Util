#pragma once

#include <cstdio>
#include <cassert>

namespace the5 {
namespace util {

/* Passes a message and file and line to assert.
*/
#define ASSERT(condition, msg, ...) if (!(condition)) { printf("Assertion failed: %s " msg "\nIn file %s line %u\n", #condition, __VA_ARGS__, __FILE__, __LINE__); abort(); }


/*
#define ASSERT(condition, msg, ...) printf("ASSERT!: " msg "\nIn file %s line %u\n", __VA_ARGS__ , __FILE__, __LINE__); assert(condition); 
*/

}
}