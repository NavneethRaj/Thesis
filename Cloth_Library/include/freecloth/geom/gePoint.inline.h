#ifndef freecloth_geom_gePoint_inline_h
#define freecloth_geom_gePoint_inline_h

#include <freecloth/base/baMath.h>

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// CLASS GePoint

//------------------------------------------------------------------------------

inline GePoint::GePoint()
{}

//------------------------------------------------------------------------------

inline GePoint::GePoint( Float x, Float y, Float z)
    : _x( x ), _y( y ), _z( z )
{}

//------------------------------------------------------------------------------

inline bool GePoint::operator==( const GePoint& rhs ) const
{
    return
        BaMath::isEqual( _x, rhs._x ) &&
        BaMath::isEqual( _y, rhs._y ) &&
        BaMath::isEqual( _z, rhs._z );
}

//------------------------------------------------------------------------------

inline bool GePoint::operator!=( const GePoint& rhs ) const
{
    return !operator==( rhs );
}


//------------------------------------------------------------------------------

inline Float GePoint::operator[]( UInt32 i ) const
{
    DGFX_ASSERT( i < 3 );
    switch( i ) {
        case 0: return _x;
        case 1: return _y;
        case 2: return _z;
    }
    return 0;
}

//------------------------------------------------------------------------------

inline Float& GePoint::operator[]( UInt32 i )
{
    DGFX_ASSERT( i < 3 );
    switch( i ) {
        case 0: return _x;
        case 1: return _y;
        case 2: return _z;
    }
    // Failure.
    return _x;
}


////////////////////////////////////////////////////////////////////////////////
// GLOBAL FUNCTIONS
//

FREECLOTH_NAMESPACE_END

#endif
