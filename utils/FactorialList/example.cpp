#include "FactorialList.h"
#include <iostream>
#include <chrono>

int main() {
    std::vector<int> limits = {1, 5, 10, 100};

    for (int limit : limits) {
        auto start = std::chrono::high_resolution_clock::now(); // Start time
        std::vector<int> factorials_list = factorial_list(limit);
        auto end = std::chrono::high_resolution_clock::now(); // End time

        std::chrono::duration<double> elapsed = end - start; // Calculate elapsed time

        std::cout << "Factorials from 0! to " << limit << "! are: ";
        for (const auto& fact : factorials_list) {
            std::cout << fact << " ";
        }
        std::cout << std::endl;
        std::cout << "Time taken to compute: " << elapsed.count() << " seconds" << std::endl;
    }

    return 0;
}
