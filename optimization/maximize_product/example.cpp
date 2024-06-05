#include "maximize_product.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

int main() {
    // Example usage for fixed p_2
    std::vector x = {0, 4, 1};
    constexpr double fixed_p2 = 0.05;

    auto start = std::chrono::high_resolution_clock::now();
    const auto [optimal_value, optimal_p] = maximize_product(x, fixed_p2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Optimal value with fixed p_2: " << optimal_value << std::endl;
    std::cout << "Optimal p values with fixed p_2: ";
    for (const auto &p: optimal_p) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    auto n = std::accumulate(optimal_p.begin(), optimal_p.end(), 0.);
    std::cout << "Sum of optimal p values: " << n << std::endl;

    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;
    std::cout << std::endl;

    // Example usage without fixed p_2
    x = {2, 1, 1, 1, 0, 1};

    start = std::chrono::high_resolution_clock::now();
    const auto [optimal_value2, optimal_p2] = maximize_product(x);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;

    std::cout << "Optimal value without fixed p_2: " << optimal_value2 << std::endl;
    std::cout << "Optimal p values without fixed p_2: ";
    for (const auto &p: optimal_p2) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
    n = std::accumulate(optimal_p2.begin(), optimal_p2.end(), 0.);
    std::cout << "Sum of optimal p values: " << n << std::endl;
    std::cout << "Time taken without fixed p_2: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
