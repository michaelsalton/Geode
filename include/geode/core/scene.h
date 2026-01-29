#pragma once

#include "geode/core/primitive.h"
#include "geode/core/types.h"
#include <vector>
#include <string>

namespace geode {

/**
 * Scene class that holds a collection of primitives
 * and provides scene-level metadata.
 */
class Scene {
public:
    Scene() = default;

    // Add a primitive to the scene
    void addPrimitive(const Primitive& prim);

    // Get all primitives
    const std::vector<Primitive>& primitives() const { return primitives_; }
    std::vector<Primitive>& primitives() { return primitives_; }

    // Scene metadata
    size_t primitiveCount() const { return primitives_.size(); }
    BoundingBox bounds() const { return bounds_; }

    // Compute or update bounding box
    void computeBounds();

    // Clear the scene
    void clear();

private:
    std::vector<Primitive> primitives_;
    BoundingBox bounds_;
};

} // namespace geode
