#include "MultinomialCoefficient.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::vector<std::vector<int> > vecs = {
        {2, 1, 1},
        {3, 2, 1},
        {1, 1, 1, 1}
    };

    // Precompute factorials up to the maximum value needed
    int max_value = 0;
    for (const auto &vec: vecs) {
        int sum_value = std::accumulate(vec.begin(), vec.end(), 0);
        if (sum_value > max_value) {
            max_value = sum_value;
        }
    }
    std::vector<int> factorial_list(max_value + 1);
    for (int i = 0; i <= max_value; ++i) {
        factorial_list[i] = factorial(i);
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<int> results = multinomial_coefficient(vecs, factorial_list);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end_time - start_time;

    for (int result: results) {
        std::cout << result << " ";
    }
    std::cout << std::endl;
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
