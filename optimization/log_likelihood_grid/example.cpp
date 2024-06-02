#include <iostream>
#include <vector>
#include <chrono>
#include "log_likelihood_grid.h"

int main() {
    const std::vector<std::vector<double>> x_values = {
        {2, 1.5, 1.2, 1, 0.5},
        {1, 2, 1.5, 1.3, 0.7}
    };
    const std::vector fixed_p2_values = {0.1, 0.05, 0.01};
    constexpr double threshold = 0.8;

    const auto start_time = std::chrono::high_resolution_clock::now();
    const std::vector<std::vector<double>> results = log_likelihood_grid(x_values, threshold, fixed_p2_values);
    const auto end_time = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed = end_time - start_time;

    for (size_t i = 0; i < results.size(); ++i) {
        for (size_t j = 0; j < results[i].size(); ++j) {
            std::cout << "Result for xs[" << i << "] and fixed_p2s[" << j << "]: " << results[i][j] << std::endl;
        }
    }

    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
