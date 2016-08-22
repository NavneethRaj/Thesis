#ifndef freecloth_base_baStringUtil_h
#define freecloth_base_baStringUtil_h

#ifndef freecloth_base_package_h
#include <freecloth/base/package.h>
#endif

#ifndef freecloth_base_types_h
#include <freecloth/base/types.h>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
/*!
 * \class BaStringUtil freecloth/base/baStringUtil.h
 * \brief Utilities for manipulating strings.
 *
 * These are very basic, aren't compliant with any good text processing
 * standards, can't handle Unicode, etc.
 */
class BaStringUtil {
public:
    // ----- static member functions -----

    //! Convert to lowercase.
    static String toLower( const String& );
    //! Convert to uppercase.
    static String toUpper( const String& );
    //! Convert to Float
    static Float toFloat( const String& );
    //! Convert to Int32
    static Int32 toInt32( const String& );
    //! Convert from UInt32
    static String fromUInt32( UInt32 );
    //! Convert from UInt32
    static String fromUInt32( UInt32, UInt32 zeroPad );
    //! Convert from Float
    static String fromFloat( Float );
    //! Convert from Float
    static String fromFloat( Float, UInt32 nbFracDigits );
};

FREECLOTH_NAMESPACE_END
 
#endif
