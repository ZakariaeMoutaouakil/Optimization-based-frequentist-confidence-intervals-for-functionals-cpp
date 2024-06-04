#include "Multinomial.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <gmpxx.h>

int main() {
    const std::vector<mpz_class> coefficients = {12, 60, 24};
    const std::vector<std::vector<double>> vectors = {
        {0.2, 0.3, 0.5},
        {0.1, 0.1, 0.8},
        {0.4, 0.4, 0.2}
    };
    const std::vector<std::vector<int>> xs = {
        {2, 1, 1},
        {3, 2, 1},
        {1, 1, 1}
    };

    const auto start_time = std::chrono::high_resolution_clock::now();
    const auto res = calculate_multinomial_probability_grid(coefficients, vectors, xs);
    const auto end_time = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> duration = end_time - start_time;

    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << "Results for probability vector " << i << ": ";
        for (const auto& value : res[i]) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}
