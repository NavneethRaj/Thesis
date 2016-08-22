//////////////////////////////////////////////////////////////////////
// Copyright (c) 2001-2002 David Pritchard <drpritch@alumni.uwaterloo.ca>
// 
#ifndef freecloth_base_baMath_inline_h
#define freecloth_base_baMath_inline_h

FREECLOTH_NAMESPACE_START

//------------------------------------------------------------------------------

inline Float BaMath::ceil( Float x )
{
    return static_cast<Float>( ::ceil(x) );
}

//------------------------------------------------------------------------------

inline Float BaMath::floor( Float x )
{
    return static_cast<Float>( ::floor(x) );
}

//------------------------------------------------------------------------------

inline Float BaMath::round( Float x )
{
    return floor( x + 0.5f );
}

//------------------------------------------------------------------------------

inline bool BaMath::isInteger( Float x )
{
    return round( x ) == x;
}

//------------------------------------------------------------------------------

inline Float BaMath::sqr( Float x )
{
    return x * x;
}

//------------------------------------------------------------------------------

inline Float BaMath::sqrt( Float x )
{
    return static_cast<Float>( ::sqrt( x ) );
}

//------------------------------------------------------------------------------

inline Float BaMath::cos( Float x )
{
    return static_cast<Float>( ::cos( x ) );
}

//------------------------------------------------------------------------------

inline Float BaMath::sin( Float x )
{
    return static_cast<Float>( ::sin( x ) );
}

//------------------------------------------------------------------------------

inline Float BaMath::tan( Float x )
{
    return static_cast<Float>( ::tan( x ) );
}

//------------------------------------------------------------------------------

inline Float BaMath::arccos( Float x )
{
    return static_cast<Float>( ::acos( x ) );
}

//------------------------------------------------------------------------------

inline Float BaMath::arcsin( Float x )
{
    return static_cast<Float>( ::asin( x ) );
}

//------------------------------------------------------------------------------

inline Float BaMath::arctan( Float x )
{
    return static_cast<Float>( ::atan( x ) );
}

//------------------------------------------------------------------------------

inline Float BaMath::arctan2( Float y, Float x )
{
    return static_cast<Float>( ::atan2( y, x ) );
}

//------------------------------------------------------------------------------

inline Float BaMath::exp( Float x )
{
    return static_cast<Float>( ::exp( x ) );
}

//------------------------------------------------------------------------------

inline Float BaMath::log( Float x )
{
    return static_cast<Float>( ::log( x ) );
}

//------------------------------------------------------------------------------

inline Float BaMath::log10( Float x )
{
    return static_cast<Float>( ::log10( x ) );
}

FREECLOTH_NAMESPACE_END

#endif
