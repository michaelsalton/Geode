#pragma once

#include "geode/core/scene.h"
#include <string>

namespace geode {

/**
 * Loads mesh files (OBJ, FBX) using Assimp and converts
 * to unified Primitive representation.
 */
class MeshLoader {
public:
    MeshLoader() = default;

    /**
     * Load a mesh file and convert to unified Scene representation.
     * @param filename Path to the mesh file (.obj, .fbx, etc.)
     * @return Scene containing loaded primitives
     */
    Scene load(const std::string& filename);

private:
    // TODO: Implement Assimp-based loading (Week 1)
};

} // namespace geode
