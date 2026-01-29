#include "geode/metrics/alpha_metrics.h"
#include <stdexcept>

namespace geode {

AlphaMetrics AlphaMetricsComputer::compute(const Cluster& cluster, const Scene& scene) {
    // TODO: Implement alpha metrics computation (Week 5)
    // 1. Extract alpha values from cluster primitives
    // 2. Compute mean, variance, min, max
    throw std::runtime_error("AlphaMetricsComputer::compute() not yet implemented");
}

} // namespace geode
