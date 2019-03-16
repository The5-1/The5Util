#pragma once

namespace the5{
namespace util{

/* replaces a classes name with a string literal.
*/

#ifndef CLASSNAME_TO_STRING
#define CLASSNAME_TO_STRING(__class__) \
({              \
    __class__ *x;\
    #__class__ ;\
})
#endif // !CLASSNAME_TO_STRING

}
}