#include "geode/core/scene.h"
#include <limits>

namespace geode {

void Scene::addPrimitive(const Primitive& prim) {
    primitives_.push_back(prim);
}

void Scene::computeBounds() {
    if (primitives_.empty()) {
        bounds_ = BoundingBox();
        return;
    }

    vec3 min_point = vec3::Constant(std::numeric_limits<float>::max());
    vec3 max_point = vec3::Constant(std::numeric_limits<float>::lowest());

    for (const auto& prim : primitives_) {
        min_point = min_point.cwiseMin(prim.position);
        max_point = max_point.cwiseMax(prim.position);
    }

    bounds_ = BoundingBox(min_point, max_point);
}

void Scene::clear() {
    primitives_.clear();
    bounds_ = BoundingBox();
}

} // namespace geode
