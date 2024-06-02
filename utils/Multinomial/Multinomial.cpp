#include "Multinomial.h"
#include <vector>
#include <iostream>
#include <cmath>
// Function to compute power of an mpq_class rational number
// mpq_class pow(const mpq_class &base, int exp) {
//     mpq_class result = 1;
//     for (int i = 0; i < exp; ++i) {
//         result *= base;
//     }
//     return result;
// }

std::vector<std::vector<double>> calculate_multinomial_probability_grid(
    const std::vector<mpz_class> &multinomial_coefficients,
    const std::vector<std::vector<double>> &probability_vectors,
    const std::vector<std::vector<int>> &x_values) {

    std::vector<std::vector<double>> results;
    for (const auto &prob_vector : probability_vectors) {
        std::vector<double> row_results;
        for (size_t i = 0; i < multinomial_coefficients.size(); ++i) {
            const mpz_class &c = multinomial_coefficients[i];
            const auto &x = x_values[i];

            // Start with the mpq_class term
            mpq_class term = c;
            // std::cout << "term = " << term << std::endl;
            // Multiply term by the probabilities raised to the power of x
            for (size_t j = 0; j < prob_vector.size(); ++j) {
                if (prob_vector[j] != 0) {
                    // std::cout << "prob_vector[j] = " << prob_vector[j] << std::endl;
                    // std::cout << "x[j] = " << x[j] << std::endl;
                    term *= std::pow(prob_vector[j], x[j]);
            // std::cout << "term after multiplication 1  = " << term << std::endl;
                }
            }
            // std::cout << "term after multiplication= " << term.get_d() << std::endl;
            row_results.push_back(term.get_d());
        }
        results.push_back(row_results);
    }
    return results;
}
