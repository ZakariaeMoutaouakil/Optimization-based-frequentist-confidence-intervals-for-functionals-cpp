#include "FactorialList.h"
#include <iostream>
#include <chrono>

int main() {
    const std::vector limits = {1, 5, 10, 20};

    for (const int limit : limits) {
        const auto start = std::chrono::high_resolution_clock::now(); // Start time
        const std::vector<mpz_class> factorials_list = factorial_list(limit);
        const auto end = std::chrono::high_resolution_clock::now(); // End time

        const std::chrono::duration<double> elapsed = end - start; // Calculate elapsed time

        std::cout << "Factorials from 0! to " << limit << "! are: ";
        for (const auto& fact : factorials_list) {
            std::cout << fact.get_str() << " ";
        }
        std::cout << std::endl;
        std::cout << "Time taken to compute: " << elapsed.count() << " seconds" << std::endl;
    }

    return 0;
}
