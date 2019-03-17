#pragma once

namespace the5 {
namespace util {

//WIP


/* https://stackoverflow.com/questions/5530248/creating-a-string-list-and-an-enum-list-from-a-c-macro/5530947#5530947
** This simple macro only works for a fixed number of arguments since the commas are hard-coded
**
** https://www.codeproject.com/Articles/1002895/Clean-Reflective-Enums-Cplusplus-Enum-to-String-wi
** Anything more sophisticated becomes very macro-heavy
*/

#ifndef ENUM_STRING
#define ENUM_STRING(name, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9)\
    enum name { v0, v1, v2, v3, v4, v5, v6, v7, v8, v9};\
    const char *name##Strings[] = { #v0, #v1, #v2, #v3, #v4, #v5, #v6, #v7, #v8, #v9};\
    const char *name##ToString(value) { return name##Strings[value]; }
#endif // !Enum

}
}