#include "maximize_product_list.h"
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    const std::vector<std::vector<int> > x = {
        {2, 1, 2, 1, 0, 1},
        {2, 1, 2, 1, 0, 1},
        {2, 1, 2, 1, 0, 1}
    };

    const auto start_time = std::chrono::high_resolution_clock::now();
    const std::vector<double> optimal_values = maximize_product_list(x);
    const auto end_time = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> duration = end_time - start_time;

    for (const auto &value: optimal_values) {
        std::cout << value << std::endl;
    }

    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}
