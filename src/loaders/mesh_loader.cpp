#include "geode/loaders/mesh_loader.h"
#include <stdexcept>

namespace geode {

Scene MeshLoader::load(const std::string& filename) {
    // TODO: Implement Assimp-based loading in Week 1
    // Will handle OBJ, FBX, and coordinate system conversions
    throw std::runtime_error("MeshLoader::load() not yet implemented");
}

} // namespace geode
