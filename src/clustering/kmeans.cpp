#include "geode/clustering/kmeans.h"
#include <stdexcept>

namespace geode {

KMeansClustering::KMeansClustering(int num_clusters, int max_iterations)
    : num_clusters_(num_clusters), max_iterations_(max_iterations) {}

std::vector<Cluster> KMeansClustering::cluster(const Scene& scene) {
    // TODO: Implement k-means clustering (Week 3)
    throw std::runtime_error("KMeansClustering::cluster() not yet implemented");
}

} // namespace geode
