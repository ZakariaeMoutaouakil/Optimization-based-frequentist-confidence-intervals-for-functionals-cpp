#include "maximize_product_list.h"
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    std::vector<std::vector<double>> x_ = {
        {2, 1.5, 1.2, 1, 0.5, 0.1},
        {2, 1.5, 1.2, 1, 0.5, 0.1},
        {2, 1.5, 1.2, 1, 0.5, 0.1}
    };
    double threshold_ = 0.1;

    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> optimal_values = maximize_product_list(x_, threshold_);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

    for (const auto& value : optimal_values) {
        std::cout << value << std::endl;
    }

    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}
