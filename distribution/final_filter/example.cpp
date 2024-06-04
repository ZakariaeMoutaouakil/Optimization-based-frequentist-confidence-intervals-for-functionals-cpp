#include "final_filter.h"
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    const std::vector<std::vector<double> > vectors = {
        {0.2, 0.3, 0.5},
        {0.1, 0.6, 0.3},
        {0.4, 0.4, 0.2}
    };
    const std::vector quantiles = {0.1, 0.2, 0.3};
    const std::vector x = {1, 2, 3};
    constexpr double threshold = 0.8;

    const auto start_time = std::chrono::high_resolution_clock::now();
    const double result = final_filter(
        vectors, quantiles, x, threshold
    );
    const auto end_time = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> duration = end_time - start_time;

    std::cout << "Final filter result: " << result << std::endl;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}
