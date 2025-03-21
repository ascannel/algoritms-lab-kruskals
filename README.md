# Kruskal's Algorithm Performance Analyzer

![C++](https://img.shields.io/badge/C++-17-blue)
![GoogleTest](https://img.shields.io/badge/Google_Test-1.11.0-green)

Implementation of Kruskal's algorithm for Minimum Spanning Tree (MST) with comparative analysis of path compression efficiency.

## Key Features
- **DSU Implementation**:
  - Union by rank
  - Optional path compression
  - Two variants: `findSet` (with compression) and `findSetWithoutCompression`
- **Graph Generation**:
  - Random connected graph generator
  - Configurable vertices/edges/weight ranges
- **Performance Testing**:
  - 14 benchmark scenarios
  - Time measurements for:
    - Sparse/dense graphs (`m = O(n)`, `m = O(n²)`)
    - Variable weight ranges
    - Scalability up to 10M edges
  - Output to timestamped CSV files

## Test Scenarios
| Test Case          | Parameters                     | Output File                          |
|--------------------|--------------------------------|--------------------------------------|
| 3.1A (Dense)       | `m = n²/10`, variable `n`      | `*PathCompression3Dot1ATimes.txt`  |
| 3.1B (Very Dense)  | `m = n²`, variable `n`         | `*PathCompression3Dot1BTimes.txt`  |
| 3.2A (Sparse)      | `m = 100n`, variable `n`       | `*PathCompression3Dot2ATimes.txt`  |
| 3.2B (Mid-Sparse)  | `m = 1000n`, variable `n`      | `*PathCompression3Dot2BTimes.txt`  |
| 3.3 (Scalability)  | Fixed `n=10k`, variable `m`    | `*PathCompression3Dot3Times.txt`   |
| 3.4A/B (Weight Impact)| Variable weight ranges       | `*PathCompression3Dot4A/BTimes.txt` |

## Porject Structure 
```
.
├── kruskalsHeader.hpp # DSU/MST declarations
├── kruskalsFunctions.cpp # Core algorithm implementation
├── kruskalTest.cpp # GoogleTest benchmarks
├── input.txt # Sample input graph
├── output_*.txt # MST results
└── times/ # Generated performance reports
```

## Limitations

- Memory-intensive for n > 10⁴
- No parallel edge handling
- Weight range limited to `[1, 10⁶]`
