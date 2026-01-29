#include <iostream>
#include "geode/core/scene.h"

int main(int argc, char** argv) {
    std::cout << "GEODE: Heterogeneous Labeling Heuristic" << std::endl;
    std::cout << "Version 0.1.0" << std::endl;

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        std::cerr << "Supported formats: .ply, .obj, .fbx" << std::endl;
        return 1;
    }

    std::string input_file = argv[1];
    std::cout << "Input file: " << input_file << std::endl;

    // TODO: Implement file loading and classification
    geode::Scene scene;
    std::cout << "Scene initialized with " << scene.primitiveCount() << " primitives" << std::endl;

    return 0;
}
