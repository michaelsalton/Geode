cmake_minimum_required(VERSION 3.16)
project(GEODE VERSION 0.1.0 LANGUAGES CXX)

# C++17 required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(GEODE_BUILD_TESTS "Build tests" ON)
option(GEODE_BUILD_EXAMPLES "Build examples" ON)
option(GEODE_BUILD_VIEWER "Build interactive viewer" ON)

# Find dependencies
find_package(Eigen3 3.4 REQUIRED NO_MODULE)

# OpenMP (optional, for parallelization)
find_package(OpenMP)

# Main library sources
set(GEODE_SOURCES
    src/loaders/ply_loader.cpp
    src/core/primitive.cpp
    src/core/scene.cpp
    src/clustering/spatial_hash.cpp
    src/clustering/kmeans.cpp
    src/metrics/pca_analysis.cpp
    src/metrics/alpha_metrics.cpp
    src/metrics/normal_coherence.cpp
    src/classification/classifier.cpp
)

set(GEODE_HEADERS
    include/geode/loaders/ply_loader.h
    include/geode/core/primitive.h
    include/geode/core/scene.h
    include/geode/core/types.h
    include/geode/clustering/spatial_hash.h
    include/geode/clustering/kmeans.h
    include/geode/metrics/pca_analysis.h
    include/geode/metrics/alpha_metrics.h
    include/geode/metrics/normal_coherence.h
    include/geode/classification/classifier.h
)

# Create library
add_library(geode ${GEODE_SOURCES} ${GEODE_HEADERS})

target_include_directories(geode
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(geode
    PUBLIC
        Eigen3::Eigen
)

# Link OpenMP if available
if(OpenMP_CXX_FOUND)
    target_link_libraries(geode PUBLIC OpenMP::OpenMP_CXX)
endif()

# Compiler warnings
if(MSVC)
    target_compile_options(geode PRIVATE /W4)
else()
    target_compile_options(geode PRIVATE -Wall -Wextra -Wpedantic)
endif()

# CLI executable
add_executable(labeler src/main.cpp)
target_link_libraries(labeler PRIVATE geode)

# Tests
if(GEODE_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Examples
if(GEODE_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Viewer (Polyscope-based)
if(GEODE_BUILD_VIEWER)
    add_subdirectory(src/viewer)
endif()

# Installation
install(TARGETS geode labeler
    EXPORT geode-targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT geode-targets
    FILE geode-targets.cmake
    NAMESPACE geode::
    DESTINATION lib/cmake/geode
)
