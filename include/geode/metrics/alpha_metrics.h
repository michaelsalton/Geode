#pragma once

#include "geode/clustering/kmeans.h"
#include "geode/core/scene.h"

namespace geode {

/**
 * Alpha (opacity) metrics for a cluster.
 */
struct AlphaMetrics {
    float mean;
    float variance;
    float min;
    float max;

    AlphaMetrics() : mean(0), variance(0), min(0), max(0) {}
};

/**
 * Computes alpha-complexity metrics for clusters.
 */
class AlphaMetricsComputer {
public:
    /**
     * Compute alpha metrics for a cluster.
     * @param cluster Input cluster
     * @param scene Scene containing primitives with alpha values
     * @return Alpha metrics
     */
    static AlphaMetrics compute(const Cluster& cluster, const Scene& scene);

private:
    // TODO: Implement in Week 5
};

} // namespace geode
