#include "final_filter.h"
#include "../../optimization/maximize_product/maximize_product.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <numeric> // For std::accumulate
#include <gmpxx.h>

double second_largest(const std::vector<double> &numbers) {
    if (numbers.size() < 2) {
        throw std::invalid_argument("List must contain at least two elements");
    }

    double first = -std::numeric_limits<double>::infinity();
    double second = -std::numeric_limits<double>::infinity();
    for (const double number: numbers) {
        if (number > first) {
            second = first;
            first = number;
        } else if (number > second && number < first) {
            second = number;
        }
    }

    if (second == -std::numeric_limits<double>::infinity()) {
        throw std::invalid_argument("All elements are the same in the list");
    }

    return second;
}

std::vector<double> second_largest_of_vectors(const std::vector<std::vector<double> > &vectors) {
    std::vector<double> results;
    for (const auto &vector: vectors) {
        results.push_back(second_largest(vector));
    }
    return results;
}

double final_filter(const std::vector<std::vector<double> > &vectors,
                    const std::vector<double> &quantiles,
                    const std::vector<int> &x,
                    const double threshold) {
    const double maximum_likelihood = -2 * maximize_product(x, threshold).first;
    std::cout << "maximum_likelihood: " << maximum_likelihood << std::endl;
    std::vector<std::vector<double> > final_candidates;

    for (size_t i = 0; i < vectors.size(); ++i) {
        const auto likelihood = std::accumulate(
            vectors[i].begin(), vectors[i].end(), 1.0,
            [&x](const double product, const double pi) {
                static size_t index = 0; // Static variable to keep track of index
                const double contribution = (pi != 0) ? std::pow(pi, x[index]) : 0.0;
                // Return 0 if pi is 0
                index++;
                return product * contribution;
            });
        std::cout << "likelihood: " << likelihood << std::endl;
        std::cout << exp((quantiles[i] + maximum_likelihood) / 2) << std::endl;
        if (exp((quantiles[i] + maximum_likelihood) / 2) <= likelihood) {
            std::cout << "Candidate: " << i << std::endl;
            final_candidates.push_back(vectors[i]);
        }
    }

    std::cout << "final_candidates: " << final_candidates.size() << std::endl;
    const std::vector<double> second_largest_values = second_largest_of_vectors(final_candidates);
    return *std::max_element(second_largest_values.begin(), second_largest_values.end());
}
