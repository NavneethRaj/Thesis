#ifndef freecloth_base_baTime_h
#define freecloth_base_baTime_h

#ifndef freecloth_base_package_h
#include <freecloth/base/package.h>
#endif

#ifndef freecloth_base_types_h
#include <freecloth/base/types.h>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
/*!
 * \class BaTime freecloth/base/baTime.h
 * \brief Basic measurement of time.
 *
 * Defines instants and durations, and methods for retrieving the current time
 * and measuring durations.
 */
class BaTime
{
public:
    //----- types and enumerations -----
    //! A period of time.
    typedef Int32  Duration;
    //! A single point in time.
    typedef UInt32  Instant;

    enum {
        MS = 1,
        S = 1000,
        MIN = S * 60
    };

    // ----- static member functions -----

    //! Retrieve the current time.
    static Instant getTime();

    //! Calculate the elapsed time between two instants.
    static Duration getDuration( Instant start, Instant end );

    //! Return a floating point value representing the given instant as a
    //! number, measured in seconds.
    static Float instantAsSeconds( Instant );
    //! Return a floating point value representing the given duration as a
    //! number, measured in seconds.
    static Float durationAsSeconds( Duration );
    static Instant floatAsInstant( Float );
    static Duration floatAsDuration( Float );
};

FREECLOTH_NAMESPACE_END

#include <freecloth/base/baTime.inline.h>

#endif
