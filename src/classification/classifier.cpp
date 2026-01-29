#include "geode/classification/classifier.h"
#include <stdexcept>

namespace geode {

Classifier::Classifier(const ClassificationConfig& config)
    : config_(config) {}

ClassificationResult Classifier::classify(const Cluster& cluster, const Scene& scene) {
    // TODO: Implement classification logic (Week 6)
    // 1. Compute all metrics
    // 2. Apply decision tree
    // 3. Compute confidence
    throw std::runtime_error("Classifier::classify() not yet implemented");
}

std::vector<ClassificationResult> Classifier::classifyAll(
    const std::vector<Cluster>& clusters,
    const Scene& scene) {

    std::vector<ClassificationResult> results;
    results.reserve(clusters.size());

    for (const auto& cluster : clusters) {
        results.push_back(classify(cluster, scene));
    }

    return results;
}

float Classifier::computeConfidence(const ClusterMetrics& metrics) const {
    // TODO: Implement confidence computation (Week 6)
    return 0.0f;
}

} // namespace geode
