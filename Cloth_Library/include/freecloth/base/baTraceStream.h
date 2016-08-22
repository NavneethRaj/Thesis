#ifndef freecloth_base_baTraceStream_h
#define freecloth_base_baTraceStream_h

#ifndef freecloth_base_package_h
#include <freecloth/base/package.h>
#endif

#ifndef freecloth_base_types_h
#include <freecloth/base/types.h>
#endif

#ifndef freecloth_base_iostream
#include <freecloth/base/iostream>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS
//

////////////////////////////////////////////////////////////////////////////////
/*!
 * \internal
 * \class BaTraceStream freecloth/base/baTraceStream.h
 * \brief Output stream for DGFX_TRACE_* macros.
 *
 * Maintains indentation level, etc.
 */
class BaTraceStream {

public:
    // ----- types and enumerations -----
    enum LineType {
        LINE_NORMAL,
        LINE_INDENT,
        LINE_UNINDENT
    };

    // ----- static member functions -----
    static BaTraceStream& theTraceStream();

    // ----- member functions -----
    ~BaTraceStream();
    std::ostream& getStream();
    String startl( LineType = LINE_NORMAL ) const;
    void indent();
    void unindent();

private:

    // ----- classes -----
    class Imp;

    // ----- member functions -----
    BaTraceStream();

    // ----- static data members -----
    static BaTraceStream _theTraceStream;

    // ----- data members -----
    Imp* _imp;

};

FREECLOTH_NAMESPACE_END
#endif
