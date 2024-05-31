#include "maximize_product.h"
#include <iostream>
#include <chrono>
#include <vector>
int main() {
    std::vector<double> x = {0, 4, 1};
    double threshold = 0.9;
    double fixed_p2 = 0.05;

    auto start = std::chrono::high_resolution_clock::now();
    auto [optimal_value, optimal_p] = maximize_product(x, threshold, fixed_p2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Optimal value with fixed p_2: " << optimal_value << std::endl;
    std::cout << "Optimal p values with fixed p_2: ";
    for (auto& p : optimal_p) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
    std::cout << "Time taken with fixed p_2: " << elapsed.count() << " seconds" << std::endl;

    // Example usage without fixed p_2
    x = {2, 1.5, 1.2, 1, 0.5, 0.1};
    threshold = 0.8;

    start = std::chrono::high_resolution_clock::now();
    auto [optimal_value2, optimal_p2] = maximize_product(x, threshold);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;

    std::cout << "Optimal value without fixed p_2: " << optimal_value2 << std::endl;
    std::cout << "Optimal p values without fixed p_2: ";
    for (auto& p : optimal_p2) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
    std::cout << "Time taken without fixed p_2: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
