#include "final_filter.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <gmpxx.h>

int main() {
    std::vector<std::vector<double>> vectors = {
        {0.2, 0.3, 0.5},
        {0.1, 0.6, 0.3},
        {0.4, 0.4, 0.2}
    };
    std::vector<double> quantiles = {0.1, 0.2, 0.3};
    std::vector<double> x = {1.0, 2.0, 3.0};
    std::vector<mpz_class> multinomial_coefficients = {10, 20, 30};
    int index_of_sample = 1;
    double threshold = 0.8;

    auto start_time = std::chrono::high_resolution_clock::now();
    double result = final_filter(vectors, quantiles, x, multinomial_coefficients, index_of_sample, threshold);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

    std::cout << "Final filter result: " << result << std::endl;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}
