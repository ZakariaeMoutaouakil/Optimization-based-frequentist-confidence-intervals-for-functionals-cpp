#include "MultinomialCoefficient.h"
#include <numeric> // For std::accumulate
#include <vector>
#include <numeric>
#include <cmath>
#include <iostream>
// std::vector<int> multinomial_coefficient(const std::vector<std::vector<int> > &vectors,
//                                          const std::vector<int> &factorials) {
//     auto multinomial = [&factorials](const std::vector<int> &vector) -> int {
//         int n = std::accumulate(vector.begin(), vector.end(), 0);
//         int numerator = factorials[n];
//         int denominator = 1;
//         for (int k: vector) {
//             denominator *= factorials[k];
//         }
//         return numerator / denominator;
//     };
//
//     std::vector<int> result;
//     result.reserve(vectors.size());
//     for (const auto &vector: vectors) {
//         result.push_back(multinomial(vector));
//     }
//     return result;
// }

std::vector<int> multinomial_coefficient(const std::vector<std::vector<int>>& vectors, const std::vector<int>& factorials) {
    std::vector<int> coefficients;
    coefficients.reserve(vectors.size());

    for (const auto& fac : factorials) {
        std::cout << fac << " ";
    }
    for (const auto& vec : vectors) {
        int product = 1;
        for (int val : vec) {
            if (val < factorials.size()) {
                product *= factorials[val];
            } else {
                // Handle error: val is out of bounds
                std::cerr << "Error: value out of bounds for factorials vector." << std::endl;
                return {};
            }
        }
        coefficients.push_back(product);
    }

    return coefficients;
}