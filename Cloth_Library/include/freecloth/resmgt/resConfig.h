#ifndef freecloth_resmgt_resConfig_h
#define freecloth_resmgt_resConfig_h

#ifndef freecloth_resmgt_package_h
#include <freecloth/resmgt/package.h>
#endif

#ifndef freecloth_resmgt_rcBase_h
#include <freecloth/resmgt/rcBase.h>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS

class ResConfigRegistryR;
class ResConfigRegistryW;
template <class T> class RCShdPtr;

////////////////////////////////////////////////////////////////////////////////
/*!
 * \class ResConfig freecloth/resmgt/resConfig.h
 * \brief Application configuration data.
 *
 * Used for storing persistent application configuration data, which can be
 * is stored on disk/registry/whatever.
 */
class ResConfig : public RCBase {

public:
    //----- member functions -----

    virtual RCShdPtr<ResConfig> clone() const = 0;
    virtual void load( ResConfigRegistryR& reg ) = 0;
    virtual void save( ResConfigRegistryW& reg ) const = 0;

};

FREECLOTH_NAMESPACE_END
#endif
