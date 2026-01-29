#pragma once

#include "geode/clustering/kmeans.h"
#include "geode/core/scene.h"

namespace geode {

/**
 * Computes normal coherence metrics for clusters.
 */
class NormalCoherence {
public:
    /**
     * Compute normal coherence for a cluster.
     * Coherence = (1/N) Σ |nᵢ · n̄|
     * where n̄ is the mean normal direction.
     *
     * @param cluster Input cluster
     * @param scene Scene containing primitives with normals
     * @return Coherence value in [0, 1]
     */
    static float compute(const Cluster& cluster, const Scene& scene);

private:
    // TODO: Implement in Week 5
};

} // namespace geode
