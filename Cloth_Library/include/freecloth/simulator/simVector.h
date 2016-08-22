#ifndef freecloth_sim_simVector_h
#define freecloth_sim_simVector_h

#ifndef freecloth_simulator_package_h
#include <freecloth/simulator/package.h>
#endif

#ifndef freecloth_geom_geVector_h
#include <freecloth/geom/geVector.h>
#endif

#ifndef freecloth_base_vector
#include <freecloth/base/vector>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS

////////////////////////////////////////////////////////////////////////////////
/*!
 * \class SimVector freecloth/simulator/simVector.h
 * \brief Dense vector class.
 *
 * Uses 3x1 GeVector objects as the contents of the vector.
 *
 * This implements the bare minimum necessary for the cloth simulation,
 * and is not really intended as a general purpose dense vector class.
 *
 * See SimMatrix for a discussion of other matrix libraries.
 */
class SimVector {

public:

    // ----- types and enumerations -----
    typedef std::vector<GeVector> Container;
    typedef Container::const_iterator const_iterator;
    typedef Container::iterator iterator;

    // ----- static member functions -----
    // named constructor
    static SimVector zero( UInt32 size );

    // ----- member functions -----
    SimVector();
    explicit SimVector( UInt32 size );
    // Default copy constructor is fine.

    const_iterator begin() const;
    const_iterator end() const;
    iterator begin();
    iterator end();

    UInt32 size() const;

    // Default assignment operator is fine.
    SimVector& operator+=( const SimVector& );
    SimVector& operator-=( const SimVector& );
    SimVector& operator+=( Float );
    SimVector& operator-=( Float );
    SimVector& operator*=( Float );
    SimVector& operator/=( Float );
    SimVector operator-() const;
    SimVector operator+( const SimVector& ) const;
    SimVector operator-( const SimVector& ) const;
    SimVector operator+( Float ) const;
    SimVector operator-( Float ) const;
    SimVector operator*( Float ) const;
    SimVector operator/( Float ) const;

    //! A combined operator, saving the overhead of constructing a temporary:
    //!   *this += scalar * vec
    //! We don't have expression templates, so this is the best alternative.
    SimVector& plusEqualsScaled( Float, const SimVector& );

    Float dot( const SimVector& ) const;
    Float length() const;

    const GeVector& operator[]( UInt32 ) const;
    GeVector& operator[]( UInt32 );

    // Set to zero
    void clear();

private:

    // ----- data members -----

    Container _data;
};

////////////////////////////////////////////////////////////////////////////////
// GLOBAL FUNCTIONS
//
std::ostream& operator<<( std::ostream&, const SimVector& );
SimVector operator*( Float, SimVector const& );

FREECLOTH_NAMESPACE_END

#include <freecloth/simulator/simVector.inline.h>

#endif
