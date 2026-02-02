#pragma once

#include "geode/core/types.h"
#include <array>

namespace geode {

/**
 * Primitive representation for 3D Gaussian Splats.
 * Contains derived geometric properties computed during ingestion.
 */
struct Primitive {
    // Core Gaussian properties
    vec3 position;                          // Spatial location
    mat3 covariance;                        // 3x3 covariance matrix (reconstructed from scale + rotation)
    float alpha;                            // Opacity value [0, 1]

    // Derived from eigendecomposition of covariance
    vec3 eigenvalues;                       // λ₁ >= λ₂ >= λ₃ (sorted descending)
    vec3 normal;                            // Smallest eigenvector (surface normal)
    float effective_rank;                   // exp(H(q₁, q₂, q₃)) - shape complexity [1, 3]

    // Color (Spherical Harmonics)
    std::array<float, 48> sh_coefficients;  // DC (3) + higher-order (45)

    Primitive()
        : position(vec3::Zero())
        , covariance(mat3::Identity())
        , alpha(1.0f)
        , eigenvalues(vec3::Ones())
        , normal(vec3::UnitZ())
        , effective_rank(3.0f)
        , sh_coefficients{}
    {}
};

} // namespace geode
