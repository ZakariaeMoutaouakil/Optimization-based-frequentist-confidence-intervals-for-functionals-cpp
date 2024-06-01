#include "Multinomial.h"
#include <cmath>
#include <vector>

std::vector<std::vector<double>> calculate_multinomial_probability_grid(
    const std::vector<mpz_class> &multinomial_coefficients,
    const std::vector<std::vector<double>> &probability_vectors,
    const std::vector<std::vector<int>> &x_values) {
    std::vector<std::vector<double> > results;
    for (const auto &prob_vector: probability_vectors) {
        std::vector<double> row_results;
        for (size_t i = 0; i < multinomial_coefficients.size(); ++i) {
            const mpz_class &c = multinomial_coefficients[i];
            const auto &x = x_values[i];
            double term = c.get_d(); // Convert mpz_class to double for calculations
            for (size_t j = 0; j < prob_vector.size(); ++j) {
                term *= std::pow(prob_vector[j], x[j]);
            }
            row_results.push_back(term);
        }
        results.push_back(row_results);
    }
    return results;
}
