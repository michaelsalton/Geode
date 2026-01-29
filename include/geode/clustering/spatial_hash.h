#pragma once

#include "geode/core/types.h"
#include <vector>

namespace geode {

/**
 * Spatial hash grid for fast O(1) neighbor queries.
 * Used during clustering to efficiently find nearby primitives.
 */
class SpatialHash {
public:
    SpatialHash(const BoundingBox& bounds, int grid_resolution);

    // TODO: Implement in Week 3
    void insert(size_t primitive_index, const vec3& position);
    std::vector<size_t> query(const vec3& position, float radius) const;

private:
    BoundingBox bounds_;
    int grid_resolution_;
    // TODO: Add hash map data structure
};

} // namespace geode
