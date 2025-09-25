# Programming Challenges and Language Features Collection

A comprehensive collection of programming solutions, algorithm implementations, and language feature demonstrations across multiple programming languages including C, CUDA, Java, and PHP.

## Project Overview

This repository contains solutions to various programming challenges, algorithm implementations from competitive programming platforms like LeetCode, and demonstrations of advanced programming language features. The focus areas include:

- CUDA programming and GPU computing
- Advanced C programming techniques
- Classic algorithms and data structures
- Mathematical computations and optimization
- LeetCode problem solutions

## Directory Structure

```
c-cuda-tests/
├── anagrams-challenge/          # PHP implementation of anagram grouping
├── cuda/                        # CUDA programming examples
├── fibonacci/                   # Fibonacci sequence implementation in C
├── longest-increasing-path/     # Matrix path algorithms (LeetCode problem)
├── median-of-two-sorted-arrays/ # Array median calculation (LeetCode problem)
├── merge-k-sorted-lists/        # Linked list merging (LeetCode problem)
├── overload-function-in-c/      # Function overloading demonstration in C
├── run-before-constructor-in-c/ # Constructor-like behavior in C
└── CMakeLists.txt               # Build configuration
```

## Technologies and Languages

### C Programming
- **Standard**: C11
- **Features Demonstrated**: Function overloading using `_Generic`, constructor attributes, dynamic memory management
- **Build System**: CMake 3.30+

### CUDA Programming
- **Purpose**: GPU computing and parallel processing
- **Requirements**: NVIDIA CUDA Toolkit
- **Applications**: Version checking and basic CUDA runtime operations

### Java
- **Purpose**: Algorithm implementations for complex data structures
- **Applications**: LeetCode problem solutions

### PHP
- **Purpose**: String manipulation and combinatorial algorithms
- **Applications**: Anagram detection and grouping

## Build and Run Instructions

### Prerequisites

**For C/CUDA projects:**
```bash
# Install build tools
cmake --version  # Ensure CMake 3.30+
gcc --version    # C compiler

# For CUDA projects
sudo apt install nvidia-cuda-toolkit  # Ubuntu/Debian
# or
brew install cuda                      # macOS with Homebrew
```

**For Java projects:**
```bash
javac --version  # Java compiler
java --version   # Java runtime
```

**For PHP projects:**
```bash
php --version    # PHP interpreter
```

### Building C Projects

```bash
# Using CMake (recommended)
mkdir build && cd build
cmake ..
make

# Manual compilation
gcc fibonacci/fibonacci-test-1.c -o fibonacci-test-1
gcc longest-increasing-path/matrix-test-1.c -o matrix-test-1
gcc overload-function-in-c/overload-function.c -o overload-function
gcc run-before-constructor-in-c/run-before-constructor.c -o run-before-constructor
```

### Building CUDA Projects

```bash
# Compile CUDA code
nvcc cuda/cuda-test-1.c -o cuda-test-1

# Check CUDA installation
which nvcc
nvcc --version
nvidia-smi          # Check GPU status
cat /proc/driver/nvidia/version  # Check driver version
```

### Running Java Projects

```bash
# Median of Two Sorted Arrays
cd median-of-two-sorted-arrays/
javac Solution.java
java Solution

# Merge K Sorted Lists
cd merge-k-sorted-lists/
javac Solution.java
java Solution
```

### Running PHP Projects

```bash
# Anagrams Challenge
cd anagrams-challenge/
php anagrams-challenge-v1.php
```

## Problem Solutions and Algorithms

### LeetCode Problems

1. **Longest Increasing Path in a Matrix**
   - **Directory**: `longest-increasing-path/`
   - **Language**: C
   - **Problem**: Find the longest increasing path in a 2D matrix
   - **URL**: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

2. **Median of Two Sorted Arrays**
   - **Directory**: `median-of-two-sorted-arrays/`
   - **Language**: Java
   - **Problem**: Find median of two sorted arrays in O(log(m+n)) time
   - **URL**: https://leetcode.com/problems/median-of-two-sorted-arrays/

3. **Merge k Sorted Lists**
   - **Directory**: `merge-k-sorted-lists/`
   - **Language**: Java
   - **Problem**: Merge k sorted linked lists efficiently
   - **URL**: https://leetcode.com/problems/merge-k-sorted-lists/

### Mathematical Algorithms

1. **Fibonacci Sequence**
   - **Directory**: `fibonacci/`
   - **Language**: C
   - **Implementation**: Recursive approach
   - **Usage**: `./fibonacci-test-1 [number]`

### String Algorithms

1. **Anagram Grouping**
   - **Directory**: `anagrams-challenge/`
   - **Language**: PHP
   - **Problem**: Group words that are anagrams of each other
   - **Algorithm**: Generate all permutations and match with input array

## Advanced C Programming Features

### Function Overloading in C
- **File**: `overload-function-in-c/overload-function.c`
- **Technique**: Uses C11 `_Generic` macro for type-based function selection
- **Supported Types**: int, double, char*
- **Demonstration**: Type-safe printing with different formatters

### Constructor-like Behavior in C
- **File**: `run-before-constructor-in-c/run-before-constructor.c`
- **Technique**: Uses `__attribute__((constructor))` GCC extension
- **Purpose**: Execute code before main() function
- **Use Case**: Initialization routines, setup code

## CUDA Programming

### Basic CUDA Operations
- **File**: `cuda/cuda-test-1.c`
- **Purpose**: CUDA runtime and driver version detection
- **Functions**: `cudaDriverGetVersion()`, `cudaRuntimeGetVersion()`
- **Output**: Version information for debugging and compatibility

## Matrix Algorithms

### Neighbor Detection
- **File**: `longest-increasing-path/matrix-test-1.c`
- **Algorithm**: Find all valid neighbors for each matrix cell
- **Features**: Dynamic memory allocation, bounds checking
- **Data Structure**: Custom `ArrayWithInfo` struct for returning arrays with size information

## Development Notes

### Memory Management
- All C programs implement proper memory allocation and deallocation
- Dynamic arrays use `malloc()` and require explicit `free()` calls
- Memory safety is demonstrated in matrix neighbor detection

### Error Handling
- CUDA programs include version checking for compatibility
- Matrix algorithms include bounds checking for safe array access
- Memory allocation failure handling is implemented where applicable

### Code Organization
- Each algorithm is self-contained in its directory
- README files provide specific build and run instructions
- Examples include test cases and expected outputs

## Contributing

When adding new solutions or algorithms:

1. Create a dedicated directory for each problem/algorithm
2. Include a README.md with problem description and build instructions
3. Add appropriate comments explaining the algorithm approach
4. Include test cases and expected outputs
5. Update this main README.md with the new addition

## License

This project is for educational and demonstration purposes. Individual algorithm implementations may be subject to platform-specific terms (e.g., LeetCode problems).
