#pragma once

#include "geode/clustering/kmeans.h"
#include "geode/core/types.h"
#include "geode/metrics/pca_analysis.h"
#include "geode/metrics/alpha_metrics.h"
#include <vector>

namespace geode {

/**
 * Combined metrics for a cluster.
 */
struct ClusterMetrics {
    PCAMetrics pca;
    AlphaMetrics alpha;
    float normal_coherence;
    float erank_mean;       // Mean effective rank of primitives in cluster
    float erank_variance;   // Variance of effective rank

    ClusterMetrics()
        : normal_coherence(0)
        , erank_mean(0)
        , erank_variance(0)
    {}
};

/**
 * Classification result for a cluster.
 */
struct ClassificationResult {
    ClusterLabel label;
    float confidence;
    ClusterMetrics metrics;
    uint32_t cluster_id;

    ClassificationResult() : label(ClusterLabel::UNCERTAIN), confidence(0), cluster_id(0) {}
};

/**
 * Configuration for classification thresholds.
 * A cluster is MESH_OPTIMAL if ALL conditions pass.
 */
struct ClassificationConfig {
    float planarity_threshold = 0.7f;           // > for mesh
    float erank_mean_low = 1.8f;                // > for mesh (disk-like)
    float erank_mean_high = 2.2f;               // < for mesh (not too spherical)
    float alpha_mean_threshold = 0.85f;         // > for mesh (opaque)
    float alpha_variance_threshold = 0.1f;      // < for mesh (consistent opacity)
    float normal_coherence_threshold = 0.7f;    // > for mesh (aligned normals)
    float uncertainty_margin = 0.1f;            // Mark as UNCERTAIN if within this margin
};

/**
 * Classifier that determines mesh-optimal vs Gaussian-optimal
 * representation for each cluster.
 */
class Classifier {
public:
    Classifier(const ClassificationConfig& config = ClassificationConfig());

    /**
     * Classify a single cluster.
     */
    ClassificationResult classify(const Cluster& cluster, const Scene& scene);

    /**
     * Classify all clusters in a scene.
     */
    std::vector<ClassificationResult> classifyAll(
        const std::vector<Cluster>& clusters,
        const Scene& scene);

    // Configuration access
    const ClassificationConfig& config() const { return config_; }
    void setConfig(const ClassificationConfig& config) { config_ = config; }

private:
    ClassificationConfig config_;

    // TODO: Implement in Week 6
    float computeConfidence(const ClusterMetrics& metrics) const;
};

} // namespace geode
