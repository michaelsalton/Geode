#include "geode/metrics/pca_analysis.h"
#include <stdexcept>

namespace geode {

PCAMetrics PCAAnalysis::analyze(const Cluster& cluster, const Scene& scene) {
    // TODO: Implement PCA analysis (Week 4)
    // 1. Compute covariance matrix from cluster positions
    // 2. Perform eigenvalue decomposition
    // 3. Compute derived metrics
    throw std::runtime_error("PCAAnalysis::analyze() not yet implemented");
}

} // namespace geode
