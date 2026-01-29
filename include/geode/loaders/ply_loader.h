#pragma once

#include "geode/core/scene.h"
#include <string>

namespace geode {

/**
 * Loads PLY files containing 3D Gaussian Splats or point clouds.
 * Supports the format produced by nerfstudio/gsplat.
 */
class PLYLoader {
public:
    PLYLoader() = default;

    /**
     * Load a PLY file and convert to unified Scene representation.
     * @param filename Path to the .ply file
     * @return Scene containing loaded primitives
     */
    Scene load(const std::string& filename);

private:
    // TODO: Implement PLY parsing (Week 1)
};

} // namespace geode
