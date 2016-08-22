#ifndef freecloth_geom_geMeshTypes_h
#define freecloth_geom_geMeshTypes_h

#ifndef freecloth_base_vector
#include <freecloth/base/vector>
#endif

#ifndef freecloth_geom_package_h
#include <freecloth/geom/package.h>
#endif

FREECLOTH_NAMESPACE_START

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS
//
class GePoint;

////////////////////////////////////////////////////////////////////////////////
/*!
 * \class GeMeshTypes freecloth/geom/geMeshTypes.h
 * \brief A class to collect a few common typedefs.
 *
 * These typedefs are used by the various GeMesh* classes.
 */
class GeMeshTypes {

public:

    // ----- types and enumerations -----
    
    //! Face index
    typedef UInt32 FaceId;
    //! Vertex index
    typedef UInt32 VertexId;
    //! Texture vertex index
    typedef UInt32 TextureVertexId;
    //! Index of a vertex within a face
    typedef UInt32 FaceVertexId;

    //! Vertex
    typedef GePoint VertexType;
    //! Texture vertex, i.e. texture co-ordinates.
    typedef GePoint TextureVertexType;

    //! Container for vertices
    typedef std::vector<VertexType>         VertexContainer;
    //! Iterator for vertices
    typedef VertexContainer::iterator       VertexIterator;
    //! ConstIterator for vertices
    typedef VertexContainer::const_iterator VertexConstIterator;
    //! Container for texture vertices
    typedef std::vector<TextureVertexType>          TextureVertexContainer;
    //! Iterator for texture vertices
    typedef TextureVertexContainer::iterator        TextureVertexIterator;
    //! ConstIterator for texture vertices
    typedef TextureVertexContainer::const_iterator  TextureVertexConstIterator;
};

FREECLOTH_NAMESPACE_END

#endif
