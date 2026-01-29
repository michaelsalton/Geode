#pragma once

#include <Eigen/Core>
#include <Eigen/Dense>
#include <array>
#include <cstdint>

namespace geode {

// Type aliases for convenience
using vec3 = Eigen::Vector3f;
using mat3 = Eigen::Matrix3f;

// Primitive type enumeration
enum class PrimitiveType {
    GAUSSIAN,
    MESH_VERTEX
};

// Cluster label enumeration
enum class ClusterLabel {
    MESH_OPTIMAL,
    GAUSSIAN_OPTIMAL,
    UNCERTAIN
};

// Bounding box structure
struct BoundingBox {
    vec3 min;
    vec3 max;

    BoundingBox() : min(vec3::Zero()), max(vec3::Zero()) {}
    BoundingBox(const vec3& min_, const vec3& max_) : min(min_), max(max_) {}

    vec3 center() const { return (min + max) * 0.5f; }
    vec3 extent() const { return max - min; }
    float volume() const {
        vec3 e = extent();
        return e.x() * e.y() * e.z();
    }
};

} // namespace geode
