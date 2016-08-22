#ifndef freecloth_resmgt_resConfigRegistry_imp_h
#define freecloth_resmgt_resConfigRegistry_imp_h

#include <freecloth/resmgt/resConfigRegistry.h>
#include <freecloth/base/baStringUtil.h>

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES

//------------------------------------------------------------------------------

template <class T>
void rFloats(
    const ResConfigRegistryR& reg,
    const String& key,
    T& result,
    const T& def
) {
    if ( reg.hasKey( key ) ) {
        result.clear();
        String s = reg.readString( key );
        String::size_type startPos = 0;
        String::size_type spacePos = s.find_first_of( ' ', startPos );
        while ( spacePos != String::npos ) {
            result.push_back(
                BaStringUtil::toFloat( s.substr( startPos, spacePos ) )
            );
            startPos = spacePos + 1;
            spacePos = s.find_first_of( ' ', startPos );
        }
        result.push_back(
            BaStringUtil::toFloat( s.substr( startPos ) )
        );
    }
    else {
        result = def;
    }
}

//------------------------------------------------------------------------------

template <class T>
void wFloats(
    ResConfigRegistryW& reg,
    const String& key,
    const T& values
) {
    typename T::const_iterator i = values.begin();
    String string;
    if ( i != values.end() ) {
        string = BaStringUtil::fromFloat( *i );
        for ( ++i; i != values.end(); ++i ) {
            string += " " + BaStringUtil::fromFloat( *i );
        }
    }
    reg.writeString( key, string );
}


////////////////////////////////////////////////////////////////////////////////
// CLASS ResConfigRegistryW

//------------------------------------------------------------------------------

#if HAVE_MEMBER_TEMPLATES
template <class T>
void ResConfigRegistryW::writeFloats(
    const String& key,
    const T& values
) {
    wFloats( *this, key, values );
}
#endif

////////////////////////////////////////////////////////////////////////////////
// CLASS ResConfigRegistryR

//------------------------------------------------------------------------------

#if HAVE_MEMBER_TEMPLATES
template <class T>
void ResConfigRegistryR::readFloats(
    const String& key,
    T& result,
    const T& def
) const {
    rFloats( *this, key, result, def );
}
#endif

FREECLOTH_NAMESPACE_END

#endif
