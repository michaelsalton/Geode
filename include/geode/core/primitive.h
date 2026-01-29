#pragma once

#include "geode/core/types.h"
#include <array>

namespace geode {

/**
 * Unified primitive representation that works for both
 * Gaussian splats and mesh vertices.
 */
struct Primitive {
    vec3 position;
    mat3 covariance;
    float alpha;
    vec3 normal;
    std::array<float, 48> sh_coefficients; // Optional, for color
    PrimitiveType type;

    Primitive()
        : position(vec3::Zero())
        , covariance(mat3::Identity())
        , alpha(1.0f)
        , normal(vec3::UnitZ())
        , sh_coefficients{}
        , type(PrimitiveType::MESH_VERTEX)
    {}
};

} // namespace geode
