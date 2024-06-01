#include "final_filter.h"
#include "../../optimization/maximize_product/maximize_product.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <numeric> // For std::accumulate

double second_largest(const std::vector<double>& numbers) {
    if (numbers.size() < 2) {
        throw std::invalid_argument("List must contain at least two elements");
    }

    double first = -std::numeric_limits<double>::infinity();
    double second = -std::numeric_limits<double>::infinity();
    for (double number : numbers) {
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

std::vector<double> second_largest_of_vectors(const std::vector<std::vector<double>>& vectors) {
    std::vector<double> results;
    for (const auto& vector : vectors) {
        results.push_back(second_largest(vector));
    }
    return results;
}

double final_filter(const std::vector<std::vector<double>>& vectors, const std::vector<double>& quantiles,
                    const std::vector<double>& x, const std::vector<mpz_class>& multinomial_coefficients,
                    int index_of_sample, double threshold) {
    double maximum_likelihood = -2 * maximize_product(x, threshold).first;
    std::vector<std::vector<double>> final_candidates;

    for (size_t i = 0; i < vectors.size(); ++i) {
        std::cout << "vectors[i]: " << vectors[i].size() << std::endl;
        std::cout << "multinomial_coefficients[index_of_sample]: " << -2 * std::log(multinomial_coefficients[index_of_sample].get_d()) << std::endl;
        double likelihood = -2 * std::log(multinomial_coefficients[index_of_sample].get_d()) - 2 * std::accumulate(vectors[i].begin(), vectors[i].end(), 0.0,
        [&x, &vectors, i](double sum, double pi) {
            static size_t index = 0; // Static variable to keep track of index
            double contribution = pi != 0 ? x[index] * std::log(pi) : 0.0;
            index++;
            return sum + contribution;
        });
        std::cout << "likelihood: " << likelihood << std::endl;

        if (likelihood <= quantiles[i] + maximum_likelihood) {
            std::cout << "Candidate: " << i << std::endl;
            final_candidates.push_back(vectors[i]);
        }
    }

    std::cout << "final_candidates: " << final_candidates.size() << std::endl;
    std::vector<double> second_largest_values = second_largest_of_vectors(final_candidates);
    return *std::max_element(second_largest_values.begin(), second_largest_values.end());
}
