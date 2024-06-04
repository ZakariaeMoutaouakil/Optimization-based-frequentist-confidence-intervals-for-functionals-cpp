#include "maximize_product_list.h"
#include "../compute_optimal_probabilities/compute_optimal_probabilities.h"
#include <vector>

std::vector<double> maximize_product_list(const std::vector<std::vector<int> > &x) {
    std::vector<double> result;
    for (const auto &x_i: x) {
        const double optimal_value = 2 * compute_optimal_probabilities(x_i).first;
        result.push_back(optimal_value);
    }
    return result;
}
