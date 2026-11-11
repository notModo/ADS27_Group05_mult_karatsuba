#pragma once

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>

namespace heritage {

/// @brief Tracks binary multiplication costs.
struct MultiplicationMetrics {
    // 1. Hardware-Independent Operation Counters
    uint64_t limb_ops{0};     ///< Single-limb multiplications or add-with-carries
    uint64_t bit_shifts{0};   ///< Bitwise shift operations performed
    size_t   max_depth{0};    ///< Peak recursion depth observed

    // 2. Memory Footprint and Allocations
    size_t alloc_count{0};    ///< Number of dynamic heap allocations
    size_t peak_aux_bytes{0}; ///< Peak temporary memory in bytes

    // 3. Wall-Clock Execution Time
    double elapsed_us{0.0};   ///< Duration in microseconds

    void reset() noexcept {
        limb_ops       = 0;
        bit_shifts     = 0;
        max_depth      = 0;
        alloc_count    = 0;
        peak_aux_bytes = 0;
        elapsed_us     = 0.0;
    }

    void print(std::ostream& os = std::cout) const {
        os << "--- Multiplication Metrics ---\n"
           << "  Limb Operations: " << limb_ops << "\n"
           << "  Bit Shifts:      " << bit_shifts << "\n"
           << "  Max Depth:       " << max_depth << "\n"
           << "  Heap Allocs:     " << alloc_count << "\n"
           << "  Peak Aux Memory: " << peak_aux_bytes << " B\n"
           << "  Elapsed Time:    " << std::fixed << std::setprecision(2)
           << elapsed_us << " us\n";
    }
};

/// @brief Tracks sorting and merging operations.
struct SortMetrics {
    // 1. Hardware-Independent Operation Counters
    uint64_t comparisons{0};   ///< Key-to-key comparison operations
    uint64_t element_swaps{0}; ///< In-place swaps between indices
    uint64_t buffer_moves{0};  ///< Element assignments to/from auxiliary memory

    // 2. Memory Footprint and Allocations
    size_t alloc_count{0};     ///< Dynamic allocations for temporary scratchpads
    size_t peak_aux_bytes{0};  ///< Peak scratchpad buffer capacity in bytes

    // 3. Wall-Clock Execution Time
    double elapsed_us{0.0};    ///< Duration in microseconds

    void reset() noexcept {
        comparisons    = 0;
        element_swaps  = 0;
        buffer_moves   = 0;
        alloc_count    = 0;
        peak_aux_bytes = 0;
        elapsed_us     = 0.0;
    }

    void print(std::ostream& os = std::cout) const {
        os << "--- Sort Metrics ---\n"
           << "  Comparisons:     " << comparisons << "\n"
           << "  Element Swaps:   " << element_swaps << "\n"
           << "  Buffer Moves:    " << buffer_moves << "\n"
           << "  Heap Allocs:     " << alloc_count << "\n"
           << "  Peak Aux Memory: " << peak_aux_bytes << " B\n"
           << "  Elapsed Time:    " << std::fixed << std::setprecision(2)
           << elapsed_us << " us\n";
    }
};

/// @brief Tracks search tree operations.
struct TreeMetrics {
    // 1. Hardware-Independent Operation Counters
    uint64_t key_compares{0}; ///< Search/insert key comparisons
    uint64_t rotations{0};    ///< Rebalancing rotations or structural splays
    size_t   max_depth{0};    ///< Maximum traversal or tree depth reached

    // 2. Memory Footprint and Allocations
    uint64_t node_allocs{0};  ///< Total node structures allocated on the heap
    size_t peak_aux_bytes{0}; ///< Auxiliary memory for non-recursive traversals

    // 3. Wall-Clock Execution Time
    double elapsed_us{0.0};   ///< Duration in microseconds

    void reset() noexcept {
        key_compares   = 0;
        rotations      = 0;
        max_depth      = 0;
        node_allocs    = 0;
        peak_aux_bytes = 0;
        elapsed_us     = 0.0;
    }

    void print(std::ostream& os = std::cout) const {
        os << "--- Tree Metrics ---\n"
           << "  Key Compares:    " << key_compares << "\n"
           << "  Rotations:       " << rotations << "\n"
           << "  Max Depth:       " << max_depth << "\n"
           << "  Node Allocs:     " << node_allocs << "\n"
           << "  Peak Aux Memory: " << peak_aux_bytes << " B\n"
           << "  Elapsed Time:    " << std::fixed << std::setprecision(2)
           << elapsed_us << " us\n";
    }
};

/// @brief RAII timer for strict benchmark isolation.
/// Measures wall-clock time between construction and destruction using steady_clock.
class ScopedTimer {
public:
    explicit ScopedTimer(double& output_target_us) noexcept
        : target_(output_target_us),
          start_(std::chrono::steady_clock::now()) {}

    ~ScopedTimer() noexcept {
        const auto finish = std::chrono::steady_clock::now();
        const std::chrono::duration<double, std::micro> elapsed = finish - start_;
        target_ += elapsed.count();
    }

    ScopedTimer(const ScopedTimer&)            = delete;
    ScopedTimer& operator=(const ScopedTimer&) = delete;
    ScopedTimer(ScopedTimer&&)                 = delete;
    ScopedTimer& operator=(ScopedTimer&&)      = delete;

private:
    double& target_;
    std::chrono::time_point<std::chrono::steady_clock> start_;
};

} // namespace heritage