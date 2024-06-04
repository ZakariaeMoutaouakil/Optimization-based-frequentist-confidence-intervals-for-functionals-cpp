#include <iostream>
#include <vector>
#include <chrono>
#include <gmpxx.h>
#include "discrete_simplex.h"

// Function to compute binomial coefficient
mpz_class binomial_coefficient(const int n, const int k) {
    mpz_class result = 1;
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int main() {
    constexpr int k = 5;
    constexpr int n = 10;

    const auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<double>> example_simplex = discrete_simplex(k, n);
    const auto end_time = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> elapsed = end_time - start_time;

    // Calculate the expected size of the output using binomial coefficient
    const mpz_class expected_size = binomial_coefficient(n + k - 1, k - 1);
    std::cout << "Expected number of combinations: " << expected_size.get_str() << std::endl;
    std::cout << "Actual number of combinations: " << example_simplex.size() << std::endl;

    if (example_simplex.size() == expected_size) {
        std::cout << "The size of the output matches the expected binomial coefficient." << std::endl;
    } else {
        std::cout << "The size of the output does not match the expected binomial coefficient." << std::endl;
    }

    // Print the generated combinations
    for (const auto& p : example_simplex) {
        for (const double val : p) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
