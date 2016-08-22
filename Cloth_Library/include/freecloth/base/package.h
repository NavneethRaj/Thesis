#ifndef freecloth_base_package_h
#define freecloth_base_package_h

#include <freecloth/base/config.h>

namespace freecloth {
}

#ifdef DOXYGEN_NO_NAMESPACE
// Doxygen doesn't support namespaces very well yet, and doesn't make many
// of the links from classes outside the namespace into the namespace.
#define FREECLOTH_NAMESPACE_START
#define FREECLOTH_NAMESPACE_END
#else
#define FREECLOTH_NAMESPACE_START namespace freecloth {
#define FREECLOTH_NAMESPACE_END   }
#endif

#endif
