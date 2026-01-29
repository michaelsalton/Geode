#pragma once

#include "geode/clustering/kmeans.h"
#include <Eigen/Eigenvalues>

namespace geode {

/**
 * PCA-derived geometric metrics for a cluster.
 */
struct PCAMetrics {
    float planarity;        // (λ₂ - λ₃) / λ₁
    float linearity;        // (λ₁ - λ₂) / λ₁
    float sphericity;       // λ₃ / λ₁
    float surface_variation; // λ₃ / (λ₁ + λ₂ + λ₃)

    vec3 eigenvalues;      // λ₁ >= λ₂ >= λ₃
    mat3 eigenvectors;     // Principal directions

    PCAMetrics() : planarity(0), linearity(0), sphericity(0), surface_variation(0) {}
};

/**
 * Performs PCA analysis on clusters to measure geometric structure.
 */
class PCAAnalysis {
public:
    /**
     * Compute PCA metrics for a cluster.
     * @param cluster Input cluster
     * @param scene Scene containing primitive positions
     * @return PCA metrics
     */
    static PCAMetrics analyze(const Cluster& cluster, const Scene& scene);

private:
    // TODO: Implement in Week 4
};

} // namespace geode
