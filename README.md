# GEODE: Heterogeneous Labeling Heuristic

**MAGMA Module III.1**

An automated classifier for hybrid 3D rendering systems that analyzes geometric and appearance properties to determine whether scene regions are better suited for mesh or Gaussian Splat representation.

## Overview

GEODE (Heterogeneous Labeling Heuristic) solves the representation selection problem in hybrid rendering pipelines. Instead of relying on human labeling or expensive joint-training, GEODE provides a fast preprocessing step that classifies arbitrary scenes using:

- **PCA-based planarity analysis** - Measures geometric flatness
- **Alpha-complexity metrics** - Analyzes opacity consistency
- **Normal coherence** - Evaluates surface consistency

## Project Status

🚧 **In Development** - Phase 1: Foundation (Week 1-3)

See [GEODE.pdf](GEODE.pdf) for the complete 12-week implementation plan.

## Building

### Requirements

- C++17 compiler (GCC 9+, Clang 10+, or MSVC 2019+)
- CMake 3.16+
- Eigen 3.4+
- Assimp 5.0+

### Build Instructions

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### Running

```bash
./labeler input.ply --output labeled.json
./labeler input.obj --visualize
```

## Project Structure

```
GEODE/
├── include/geode/       # Public headers
│   ├── core/           # Core data structures
│   ├── loaders/        # File format loaders
│   ├── clustering/     # Spatial clustering
│   ├── metrics/        # Classification metrics
│   └── classification/ # Decision logic
├── src/                # Implementation files
├── tests/              # Unit tests
├── examples/           # Example programs
├── data/               # Test data and datasets
└── docs/               # Documentation
```

## Development Timeline

- **Phase 1** (Weeks 1-3): Foundation - Loaders, unified representation, clustering
- **Phase 2** (Weeks 4-6): Classification metrics - PCA, alpha-complexity, normal coherence
- **Phase 3** (Weeks 7-9): Visualization - Interactive viewer with heat-maps
- **Phase 4** (Weeks 10-11): Validation & tuning - Ground truth, threshold optimization
- **Phase 5** (Week 12): Polish & documentation - CLI, library packaging, integration guide

## Key Features

✅ Unified primitive representation (Gaussians + meshes)
✅ Fast spatial clustering with k-means
⏳ PCA-based geometric analysis
⏳ Opacity and normal coherence metrics
⏳ Interactive visualization with Polyscope
⏳ Configurable threshold system
⏳ CLI and library interfaces

## License

TBD

## Contact

Michael Salton - Concordia University, Montréal
