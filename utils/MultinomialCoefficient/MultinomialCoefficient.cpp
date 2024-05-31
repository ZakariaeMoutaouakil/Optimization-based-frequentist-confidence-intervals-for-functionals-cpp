#include "MultinomialCoefficient.h"
#include <numeric> // For std::accumulate

std::vector<int> multinomial_coefficient(const std::vector<std::vector<int> > &vectors,
                                         const std::vector<int> &factorials) {
    auto multinomial = [&factorials](const std::vector<int> &vector) -> int {
        int n = std::accumulate(vector.begin(), vector.end(), 0);
        int numerator = factorials[n];
        int denominator = 1;
        for (int k: vector) {
            denominator *= factorials[k];
        }
        return numerator / denominator;
    };

    std::vector<int> result;
    result.reserve(vectors.size());
    for (const auto &vector: vectors) {
        result.push_back(multinomial(vector));
    }
    return result;
}
