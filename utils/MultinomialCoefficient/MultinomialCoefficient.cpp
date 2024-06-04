#include "MultinomialCoefficient.h"
#include <numeric> // For std::accumulate
#include <vector>
#include <iostream>

std::vector<mpz_class> multinomial_coefficient(const std::vector<std::vector<int> > &vectors,
                                               const std::vector<mpz_class> &factorials) {
    auto multinomial = [&factorials](const std::vector<int> &vector) -> mpz_class {
        const int n = std::accumulate(vector.begin(), vector.end(), 0);
        std::cout << "n: " << n << std::endl;
        const mpz_class &numerator = factorials[n];
        mpz_class denominator = 1;
        for (const int k: vector) {
            denominator *= factorials[k];
        }
        return numerator / denominator;
    };

    std::vector<mpz_class> result;
    result.reserve(vectors.size());
    for (const auto &vector: vectors) {
        result.push_back(multinomial(vector));
    }
    return result;
}
