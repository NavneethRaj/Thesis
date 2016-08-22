#ifndef freecloth_base_baTime_inline_h
#define freecloth_base_baTime_inline_h

#include <freecloth/base/baMath.h>

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// CLASS BaTime
//

//------------------------------------------------------------------------------

inline Float BaTime::instantAsSeconds( Instant instant )
{
    return instant / Float( S );
}

//------------------------------------------------------------------------------

inline Float BaTime::durationAsSeconds( Duration duration )
{
    return duration / Float( S );
}

//------------------------------------------------------------------------------

inline BaTime::Instant BaTime::floatAsInstant( Float t )
{
    return BaMath::roundUInt32( t * Float( S ) );
}

//------------------------------------------------------------------------------

inline BaTime::Duration BaTime::floatAsDuration( Float t )
{
    return BaMath::roundInt32( t * Float( S ) );
}

FREECLOTH_NAMESPACE_END

#endif
