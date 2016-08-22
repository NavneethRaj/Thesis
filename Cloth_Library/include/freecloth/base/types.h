#ifndef freecloth_base_types_h
#define freecloth_base_types_h

#ifndef freecloth_base_package_h
#include <freecloth/base/package.h>
#endif

#ifndef freecloth_base_string
#include <freecloth/base/string>
#endif

FREECLOTH_NAMESPACE_START

typedef unsigned int    UInt32;
typedef signed int      Int32;
typedef unsigned short  UInt16;
typedef signed short    Int16;
typedef unsigned char   UInt8;
typedef signed char     Int8;

typedef float           Float;
typedef std::string     String;

FREECLOTH_NAMESPACE_END

#endif
