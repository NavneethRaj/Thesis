#ifndef freecloth_resmgt_resConfigRegistryUnix_h
#define freecloth_resmgt_resConfigRegistryUnix_h

#ifndef freecloth_resmgt_package_h
#include <freecloth/resmgt/package.h>
#endif

#ifndef freecloth_resmgt_resConfigRegistry_h
#include <freecloth/resmgt/resConfigRegistry.h>
#endif

#ifndef freecloth_resmgt_resConfigRegistryFile_h
#include <freecloth/resmgt/resConfigRegistryFile.h>
#endif

#ifndef freecloth_base_map
#include <freecloth/base/map>
#endif

#ifndef freecloth_base_fstream
#include <freecloth/base/fstream>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// CLASS ResConfigRegistryWUnix
typedef ResConfigRegistryWFile ResConfigRegistryWUnix;

////////////////////////////////////////////////////////////////////////////////
// CLASS ResConfigRegistryWUnix
typedef ResConfigRegistryRFile ResConfigRegistryRUnix;

FREECLOTH_NAMESPACE_END

#endif
