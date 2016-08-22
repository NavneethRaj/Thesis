#ifndef freecloth_resmgt_rcBase_h
#define freecloth_resmgt_rcBase_h

#ifndef freecloth_resmgt_package_h
#include <freecloth/resmgt/package.h>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS

class RCShdPtrBase;

////////////////////////////////////////////////////////////////////////////////
/*!
 * \class RCBase freecloth/resmgt/rcBase.h
 * \brief Base class for reference-counted objects.
 *
 * This class contains a reference count, for use with the RCShdPtr<>
 * smart pointer class. Any object that is intended to be usable as a
 * smart-pointed object should derive from this.
 */
class RCBase
{
protected:
    UInt32 _rcCount;

    //----- member functions -----
    RCBase();
    RCBase( RCBase const& );
    virtual ~RCBase();

    friend class RCShdPtrBase;
};

FREECLOTH_NAMESPACE_END
#endif
