# GEODE

**Heterogeneous Labeling Heuristic for 3D Gaussian Splatting Assets**

GEODE is an automated classifier that analyzes pre-trained 3D Gaussian Splatting (3DGS) assets and labels spatial clusters as mesh-optimal or Gaussian-optimal. It enables hybrid rendering pipelines that combine traditional mesh rendering with Gaussian splatting for real-time applications like video games.

Part of the **MAGMA** (Mesh-Adaptive Gaussian-Mesh Architecture) thesis project - Module III.1.

## Problem

Hybrid rendering systems that combine meshes and 3D Gaussian Splats currently rely on human labeling or expensive joint-training to decide which representation to use for each region of a scene. This creates a bottleneck for automated pipelines and prevents adoption in real-time applications.

## Solution

GEODE operates as a fast preprocessing step at asset import time, requiring no retraining or neural network inference. The classifier uses:

- **PCA-based planarity analysis** - Identifies flat, surface-like regions
- **Effective rank distribution** - Measures Gaussian shape complexity
- **Alpha-complexity metrics** - Analyzes opacity patterns
- **Normal coherence** - Evaluates surface consistency

## Pipeline

```
Load 3DGS .ply
     │
     ▼
┌─────────────┐
│  Ingestion  │  Reconstruct covariance, derive normals, compute effective rank
└─────────────┘
     │
     ▼
┌─────────────┐
│  Clustering │  Spatial hash grid + k-means partitioning
└─────────────┘
     │
     ▼
┌─────────────┐
│  Labeling   │  Per-cluster metrics → MESH_OPTIMAL / GAUSSIAN_OPTIMAL / UNCERTAIN
└─────────────┘
     │
     ▼
┌─────────────┐
│ Conversion  │  Poisson reconstruction for mesh regions
└─────────────┘
     │
     ▼
  Output .hga
```

## Output Format

GEODE produces `.hga` (Hybrid Gaussian Asset) files - a binary container format that packages:

- Triangle mesh geometry (from mesh-optimal clusters)
- Gaussian splat data (from Gaussian-optimal clusters)
- Cluster metadata and classification confidence scores

## Performance Targets

| Stage          | Game Asset (50K) | Full Scene (1M) |
|----------------|------------------|-----------------|
| Ingestion      | < 100ms          | < 5s            |
| Clustering     | < 50ms           | < 5s            |
| Classification | < 10ms           | < 1s            |
| Conversion     | < 500ms          | < 30s           |
| **Total**      | **< 1s**         | **< 45s**       |

## Usage

```bash
geode input.ply -o output.hga
```

## Building

### Requirements

- C++17 compiler (GCC 11+, Clang 14+, or MSVC 2022)
- CMake 3.16+

### Dependencies

| Library | Purpose |
|---------|---------|
| Eigen 3.4+ | Linear algebra, eigenvalue decomposition |
| tinyply/happly | PLY file loading |
| nlohmann/json | Configuration parsing |
| CGAL/Open3D | Poisson surface reconstruction |
| Polyscope | Interactive visualization |

### Build

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

## Configuration

Classification thresholds can be tuned via JSON configuration:

```json
{
  "planarity_threshold": 0.7,
  "erank_mean_low": 1.8,
  "erank_mean_high": 2.2,
  "alpha_mean_threshold": 0.85,
  "alpha_variance_threshold": 0.1,
  "normal_coherence_threshold": 0.7
}
```

## Project Structure

```
GEODE/
├── src/           # Source files
├── include/       # Header files
├── tests/         # Unit tests
├── data/          # Test assets
└── docs/          # Documentation
```

## Documentation

See the [spec/](spec/) directory for detailed feature specifications:

- Data ingestion and PLY loading
- Spatial clustering algorithms
- Classification metrics and decision logic
- Visualization and inspection tools
- HGA format specification

## License

Part of the MAGMA thesis project.

## Author

Michael Salton
Concordia University, Montréal
February 2026