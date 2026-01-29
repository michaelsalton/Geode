#pragma once

#include "geode/core/scene.h"
#include <vector>
#include <cstdint>

namespace geode {

/**
 * Cluster structure representing a spatial region.
 */
struct Cluster {
    uint32_t id;
    std::vector<uint32_t> primitive_indices;
    BoundingBox bounds;
    vec3 centroid;

    Cluster() : id(0), centroid(vec3::Zero()) {}
};

/**
 * K-means clustering for spatial partitioning of scenes.
 */
class KMeansClustering {
public:
    KMeansClustering(int num_clusters, int max_iterations = 100);

    /**
     * Cluster the scene primitives spatially.
     * @param scene Input scene with primitives
     * @return Vector of clusters
     */
    std::vector<Cluster> cluster(const Scene& scene);

private:
    int num_clusters_;
    int max_iterations_;
    // TODO: Implement in Week 3
};

} // namespace geode
