#include "maximize_product_list.h"
#include "../maximize_product/maximize_product.h"
#include <vector>

std::vector<double> maximize_product_list(const std::vector<std::vector<double>>& x, double threshold) {
    std::vector<double> result;
    for (const auto& x_i : x) {
        double optimal_value = 2 * maximize_product(x_i, threshold).first;
        result.push_back(optimal_value);
    }
    return result;
}
