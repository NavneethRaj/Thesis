#ifndef freecloth_base_debug_h
#define freecloth_base_debug_h

#ifndef freecloth_base_package_h
#include <freecloth/base/package.h>
#endif

// Since the debug build will need this for tracing, we'll also include it
// in the release build. We want the two to have similar levels of
// knowledge of standard headers.
#include <freecloth/base/iostream>

#ifdef NDEBUG

#define DGFX_ASSERT(x)
#define DGFX_TRACE_ENTER(x)
#define DGFX_TRACE(x)

#else

#include <assert.h>

#ifndef freecloth_base_baTraceEntry_h
#include <freecloth/base/baTraceEntry.h>
#endif

#ifndef freecloth_base_baTraceStream_h
#include <freecloth/base/baTraceStream.h>
#endif

//! Custom assertion macro.
#define DGFX_ASSERT(x) assert( x )

//! Do a DGFX_TRACE of x at execution, and another one when the current
//! scope ends. Useful for tracking function entry/exit. Indentation
//! of trace output is increased from here to end of scope.
#define DGFX_TRACE_ENTER(x)                             \
    BaTraceEntry theBaTraceEntry;                       \
    theBaTraceEntry.getStream() << x;                   \
    theBaTraceEntry.doneOutput();

//! Dump \p x to tracing stream, typically debug_trace.txt. Only happens in
//! debug builds with NDEBUG flag undefined.
#define DGFX_TRACE(x)                                   \
    BaTraceStream::theTraceStream().getStream()         \
        << BaTraceStream::theTraceStream().startl()     \
        << x                                            \
        << std::endl

#endif


#endif
