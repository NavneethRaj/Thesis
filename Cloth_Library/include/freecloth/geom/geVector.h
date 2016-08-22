#ifndef freecloth_geom_geVector_h
#define freecloth_geom_geVector_h

#ifndef freecloth_geom_package_h
#include <freecloth/geom/package.h>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS

class GePoint;

////////////////////////////////////////////////////////////////////////////////
/*!
 * \class GeVector freecloth/geom/geVector.h
 * \brief A class for 3D vectors.
 *
 * In keeping with the principles of affine spaces, we distinguish between
 * vectors and points, which represent direction and position, respectively.
 */
class GeVector {

public:

    // ----- static member functions -----

    //! Named constructor: retrieve zero vector. More efficient than the
    //! ZERO static data member.
    static GeVector zero();
    //! Named constructor: retrieve vector for nth axis
    static GeVector axis( UInt32 n );
    //! Named constructor: retrieve vector for x axis
    static GeVector xAxis();
    //! Named constructor: retrieve vector for y axis
    static GeVector yAxis();
    //! Named constructor: retrieve vector for z axis
    static GeVector zAxis();

    // ----- member functions -----
    GeVector();
    GeVector( Float x, Float y, Float z );
    //! Construct a vector from p2-p1
    GeVector( const GePoint& p1, const GePoint& p2 );
    // Default copy constructor is fine.

    // Default assignment operator is fine.
    GeVector& operator+=( const GeVector& );
    GeVector& operator-=( const GeVector& );
    GeVector& operator+=( Float );
    GeVector& operator-=( Float );
    GeVector& operator*=( Float );
    GeVector& operator/=( Float );
    GeVector operator-() const;
    GeVector operator+( const GeVector& ) const;
    GeVector operator-( const GeVector& ) const;
    GeVector operator+( Float ) const;
    GeVector operator-( Float ) const;
    GeVector operator*( Float ) const;
    GeVector operator/( Float ) const;
    bool operator==( const GeVector& ) const;
    bool operator!=( const GeVector& ) const;
    Float operator[]( UInt32 ) const;
    Float& operator[]( UInt32 );

    //! Dot product
    Float dot( const GeVector& ) const;
    //! Cross product
    GeVector cross( const GeVector& ) const;

    //! Vector length (L2 norm)
    Float length() const;
    Float squaredLength() const;
    //! max(|x|,|y|,|z|)
    Float infinityNorm() const;

    bool isUnit() const;
    GeVector getUnit() const;

    // FIXME: this is more of a 2d thing... kill it.
    Float getAngle( const GeVector& ) const;

    // ----- static data members -----
    static const GeVector ZERO;

    // ----- data members -----
    Float _x,_y,_z;
};


////////////////////////////////////////////////////////////////////////////////
// GLOBAL FUNCTIONS
//
std::ostream& operator<<( std::ostream&, const GeVector& );
GeVector operator*( Float, GeVector const& );

FREECLOTH_NAMESPACE_END

#include <freecloth/geom/geVector.inline.h>

#endif
