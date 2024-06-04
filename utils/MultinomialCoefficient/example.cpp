#include "MultinomialCoefficient.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <gmpxx.h>

mpz_class factorial(const int n) {
    mpz_class result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    const std::vector<std::vector<int> > vecs = {
        {2, 1, 1},
        {3, 2, 1},
        {1, 1, 1, 1}
    };

    // Precompute factorials up to the maximum value needed
    int max_value = 0;
    for (const auto &vec: vecs) {
        if (const int sum_value = std::accumulate(vec.begin(), vec.end(), 0); sum_value > max_value) {
            max_value = sum_value;
        }
    }
    std::vector<mpz_class> factorial_list(max_value + 1);
    for (int i = 0; i <= max_value; ++i) {
        factorial_list[i] = factorial(i);
    }

    const auto start_time = std::chrono::high_resolution_clock::now();
    const std::vector<mpz_class> results = multinomial_coefficient(vecs, factorial_list);
    const auto end_time = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> elapsed = end_time - start_time;

    for (const auto &result: results) {
        std::cout << result.get_str() << " ";
    }
    std::cout << std::endl;
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
