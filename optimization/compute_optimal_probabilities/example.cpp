#include "compute_optimal_probabilities.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

int main() {
    // Example usage
    const std::vector x = {2, 1, 1, 1, 0, 3};

    const auto start = std::chrono::high_resolution_clock::now();
    const auto [optimal_value, optimal_p] = compute_optimal_probabilities(x);
    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed = end - start;

    std::cout << "Optimal value without fixed p_2: " << optimal_value << std::endl;
    std::cout << "Optimal p values without fixed p_2: ";
    for (auto& p : optimal_p) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    const auto n = std::accumulate(optimal_p.begin(), optimal_p.end(), 0.);
    std::cout << "Sum of optimal p values: " << n << std::endl;

    std::cout << std::endl;
    std::cout << "Time taken without fixed p_2: " << elapsed.count() / 1e9 << " seconds" << std::endl;

    return 0;
}