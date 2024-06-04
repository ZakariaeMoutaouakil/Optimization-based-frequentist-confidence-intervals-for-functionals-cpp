#include "maximize_product.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

int main() {
    const std::vector x = {0, 4, 1};
    constexpr double threshold = 0.9;
    constexpr double fixed_p2 = 0.05;

    const auto start = std::chrono::high_resolution_clock::now();
    const auto [optimal_value, optimal_p] = maximize_product(x, threshold, fixed_p2);
    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed = end - start;

    std::cout << "Optimal value with fixed p_2: " << optimal_value << std::endl;
    std::cout << "Optimal p values with fixed p_2: ";
    for (auto &p: optimal_p) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    const auto n = std::accumulate(optimal_p.begin(), optimal_p.end(), 0.);
    std::cout << "Sum of optimal p values: " << n << std::endl;

    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}
