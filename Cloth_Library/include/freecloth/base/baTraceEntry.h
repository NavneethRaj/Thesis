#ifndef freecloth_base_baTraceEntry_h
#define freecloth_base_baTraceEntry_h

#ifndef freecloth_base_package_h
#include <freecloth/base/package.h>
#endif

#ifndef freecloth_base_types_h
#include <freecloth/base/types.h>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
/*!
 * \internal
 * \class BaTraceEntry freecloth/base/baTraceEntry.h
 * \brief Utility class used by DGFX_TRACE_ENTER macro.
 *
 * On construction, increases the trace indent level, and on destruction
 * decreases it.
 */
class BaTraceEntry {

public:
    // ----- member functions -----
    BaTraceEntry();
    ~BaTraceEntry();

    std::ostream& getStream();
    void doneOutput();

private:

    // ----- data members -----

};

FREECLOTH_NAMESPACE_END
#endif
