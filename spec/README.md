# GEODE Feature Specifications

This directory contains concise specification sheets for each feature/component of the GEODE project.

## Phase 1: Foundation (Weeks 1-3)
- [1.1 PLY Loader](1.1-ply-loader.md) - Load 3D Gaussian Splat files
- [1.2 Mesh Loader](1.2-mesh-loader.md) - Load OBJ/FBX mesh files
- [1.3 Unified Primitive Representation](1.3-unified-primitive.md) - Convert all inputs to common format
- [2.1 Spatial Clustering](2.1-spatial-clustering.md) - Partition scene into spatial clusters

## Phase 2: Classification Metrics (Weeks 4-6)
- [3.1 PCA Analysis](3.1-pca-analysis.md) - Measure geometric structure
- [3.2 Alpha Metrics](3.2-alpha-metrics.md) - Analyze opacity consistency
- [3.3 Normal Coherence](3.3-normal-coherence.md) - Measure surface consistency
- [3.4 Classification Logic](3.4-classification-logic.md) - Decision tree and confidence scoring

## Phase 3: Visualization (Weeks 7-9)
- [4.1 Viewer Setup](4.1-viewer-setup.md) - Basic 3D visualization
- [4.2 Visualization Modes](4.2-visualization-modes.md) - Heat-maps and color mapping
- [4.3 Inspection Tools](4.3-inspection-tools.md) - Interactive cluster inspection

## Phase 4: Validation & Tuning (Weeks 10-11)
- [5.1 Test Dataset](5.1-test-dataset.md) - Ground truth and evaluation metrics
- [5.2 Threshold Tuning](5.2-threshold-tuning.md) - Optimize classification parameters

## Phase 5: Polish (Week 12)
- [6.1 Final Polish](6.1-final-polish.md) - CLI, documentation, packaging
