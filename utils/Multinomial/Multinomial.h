#ifndef MULTINOMIAL_H
#define MULTINOMIAL_H

#include <vector>

std::vector<std::vector<double>> calculate_multinomial_probability_grid(
    const std::vector<int>& multinomial_coefficients,
    const std::vector<std::vector<double>>& probability_vectors,
    const std::vector<std::vector<int>>& x_values);

#endif // MULTINOMIAL_H
