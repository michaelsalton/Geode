# GEODE Specification Index

This directory contains detailed feature specifications for the GEODE project. Each spec covers a single feature or component, organized by pipeline stage and development phase.

## Quick Reference

| Spec | Feature | Phase | Week |
|------|---------|-------|------|
| [1.1](1.1-ply-loader.md) | PLY Loader | Foundation | 1 |
| [1.2](1.2-primitive-representation.md) | Primitive Representation | Foundation | 2 |
| [2.1](2.1-spatial-clustering.md) | Spatial Clustering | Foundation | 3 |
| [3.1](3.1-pca-analysis.md) | PCA Analysis | Classification | 4 |
| [3.2](3.2-alpha-metrics.md) | Alpha Metrics | Classification | 5 |
| [3.3](3.3-normal-coherence.md) | Normal Coherence | Classification | 5 |
| [3.4](3.4-classification-logic.md) | Classification Logic | Classification | 6 |
| [4.1](4.1-viewer-setup.md) | Viewer Setup | Visualization | 7 |
| [4.2](4.2-visualization-modes.md) | Visualization Modes | Visualization | 8 |
| [4.3](4.3-inspection-tools.md) | Inspection Tools | Visualization | 9 |
| [5.1](5.1-mesh-extraction.md) | Mesh Extraction | Conversion | 12 |
| [5.2](5.2-hga-format.md) | HGA Format | Conversion | 13 |
| [6.1](6.1-cli-interface.md) | CLI Interface | Polish | 14 |

## Development Phases

### Phase 1: Foundation (Weeks 1-3)

Build the core data pipeline from PLY loading to spatial clustering.

- **[1.1 PLY Loader](1.1-ply-loader.md)** - Parse 3DGS binary PLY files
- **[1.2 Primitive Representation](1.2-primitive-representation.md)** - Covariance reconstruction, eigendecomposition
- **[2.1 Spatial Clustering](2.1-spatial-clustering.md)** - K-means with spatial hash acceleration

### Phase 2: Classification Metrics (Weeks 4-6)

Implement geometric analysis and the labeling decision function.

- **[3.1 PCA Analysis](3.1-pca-analysis.md)** - Cluster-level planarity, linearity, sphericity
- **[3.2 Alpha Metrics](3.2-alpha-metrics.md)** - Opacity statistics
- **[3.3 Normal Coherence](3.3-normal-coherence.md)** - Surface orientation consistency
- **[3.4 Classification Logic](3.4-classification-logic.md)** - Decision function, confidence scoring

### Phase 3: Visualization (Weeks 7-9)

Build interactive debugging and inspection tools.

- **[4.1 Viewer Setup](4.1-viewer-setup.md)** - Polyscope integration, basic display
- **[4.2 Visualization Modes](4.2-visualization-modes.md)** - Classification colors, heat maps
- **[4.3 Inspection Tools](4.3-inspection-tools.md)** - Cluster selection, threshold tuning

### Phase 4: Validation & Tuning (Weeks 10-11)

*No new specs - testing, threshold tuning, and ablation studies.*

### Phase 5: Conversion & Packaging (Weeks 12-13)

Convert classified clusters to hybrid assets.

- **[5.1 Mesh Extraction](5.1-mesh-extraction.md)** - Poisson reconstruction, color transfer
- **[5.2 HGA Format](5.2-hga-format.md)** - Binary container specification

### Phase 6: Polish & Documentation (Week 14)

Final cleanup and tooling.

- **[6.1 CLI Interface](6.1-cli-interface.md)** - Command-line batch processing

## Pipeline Overview

```
┌─────────────────────────────────────────────────────────────────────┐
│                         GEODE PIPELINE                              │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│  ┌─────────┐    ┌─────────┐    ┌─────────┐    ┌─────────┐          │
│  │   PLY   │ -> │Primitive│ -> │Clustering│ -> │Labeling │          │
│  │ Loader  │    │  Repr.  │    │ Engine  │    │ Engine  │          │
│  │ (1.1)   │    │ (1.2)   │    │ (2.1)   │    │(3.1-3.4)│          │
│  └─────────┘    └─────────┘    └─────────┘    └─────────┘          │
│                                                     │               │
│                                                     v               │
│  ┌─────────┐    ┌─────────┐    ┌─────────┐    ┌─────────┐          │
│  │   HGA   │ <- │  Mesh   │ <- │Conversion│ <- │Manifest │          │
│  │ Output  │    │Extraction│    │ Engine  │    │  JSON   │          │
│  │ (5.2)   │    │ (5.1)   │    │         │    │         │          │
│  └─────────┘    └─────────┘    └─────────┘    └─────────┘          │
│                                                                     │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │                    VISUALIZATION (4.1-4.3)                   │   │
│  │   Viewer Setup -> Visualization Modes -> Inspection Tools   │   │
│  └─────────────────────────────────────────────────────────────┘   │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

## Spec Format

Each spec follows this structure:

1. **Overview** - What the feature does
2. **Input/Output** - Data structures
3. **Algorithm** - Implementation details
4. **Requirements** - Functional checklist
5. **API** - C++ interface
6. **Test Cases** - Validation scenarios
7. **Notes** - Additional considerations

## Classification Thresholds

Default thresholds used across specs:

| Metric | Threshold | Direction |
|--------|-----------|-----------|
| Planarity | 0.7 | > for mesh |
| Effective Rank (low) | 1.8 | > for mesh |
| Effective Rank (high) | 2.2 | < for mesh |
| Alpha Mean | 0.85 | > for mesh |
| Alpha Variance | 0.1 | < for mesh |
| Normal Coherence | 0.7 | > for mesh |

## Dependencies

| Library | Used In | Purpose |
|---------|---------|---------|
| Eigen | 1.1, 1.2, 2.1, 3.x | Linear algebra |
| tinyply/happly | 1.1 | PLY parsing |
| nlohmann/json | 3.4, 5.2 | Config & manifest |
| CGAL/Open3D | 5.1 | Poisson reconstruction |
| Polyscope | 4.x | Visualization |
| CLI11 | 6.1 | Argument parsing |
