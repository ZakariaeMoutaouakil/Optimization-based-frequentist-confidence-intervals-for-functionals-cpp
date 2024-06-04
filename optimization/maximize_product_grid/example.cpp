#include <iostream>
#include <vector>
#include <chrono>
#include "maximize_product_grid.h"

int main() {
    const std::vector<std::vector<int> > x_values = {
        {2, 5, 2, 1, 5},
        {1, 2, 5, 3, 7}
    };
    const std::vector p2_values = {0.1, 0.09};
    constexpr double threshold = 0.8;

    const auto start_time = std::chrono::high_resolution_clock::now();
    const std::vector<std::vector<double> > final_results = maximize_product_grid(x_values, threshold, p2_values);
    const auto end_time = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed = end_time - start_time;

    for (size_t i = 0; i < final_results.size(); ++i) {
        for (size_t j = 0; j < final_results[i].size(); ++j) {
            std::cout << "Result for xs[" << i << "] and fixed_p2s[" << j << "]:" << std::endl;
            std::cout << "  Optimal value: " << final_results[i][j] << std::endl;
        }
    }

    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
