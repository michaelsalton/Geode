#include "geode/clustering/spatial_hash.h"
#include <stdexcept>

namespace geode {

SpatialHash::SpatialHash(const BoundingBox& bounds, int grid_resolution)
    : bounds_(bounds), grid_resolution_(grid_resolution) {
    // TODO: Initialize hash grid (Week 3)
}

void SpatialHash::insert(size_t primitive_index, const vec3& position) {
    // TODO: Implement (Week 3)
    throw std::runtime_error("SpatialHash::insert() not yet implemented");
}

std::vector<size_t> SpatialHash::query(const vec3& position, float radius) const {
    // TODO: Implement (Week 3)
    throw std::runtime_error("SpatialHash::query() not yet implemented");
}

} // namespace geode
