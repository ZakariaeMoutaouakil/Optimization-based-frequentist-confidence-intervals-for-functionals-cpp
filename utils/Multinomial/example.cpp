#include "Multinomial.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <gmpxx.h>

int main() {
    std::vector<mpz_class> coefficients = {12, 60, 24};
    std::vector<std::vector<double>> vectors = {
        {0.2, 0.3, 0.5},
        {0.1, 0.1, 0.8},
        {0.4, 0.4, 0.2}
    };
    std::vector<std::vector<int>> xs = {
        {2, 1, 1},
        {3, 2, 1},
        {1, 1, 1}
    };

    auto start_time = std::chrono::high_resolution_clock::now();
    auto res = calculate_multinomial_probability_grid(coefficients, vectors, xs);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

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
