#include "maximize_product_grid.h"
#include "../maximize_product/maximize_product.h" // For the `maximize_product` function

std::vector<std::vector<double> > maximize_product_grid(const std::vector<std::vector<int> > &xs,
                                                        const double threshold,
                                                        const std::vector<double> &fixed_p2s) {
    std::vector<std::vector<double> > results;
    for (const auto &fixed_p2: fixed_p2s) {
        std::vector<double> result_row;
        for (const auto &x: xs) {
            const double optimal_value = -2.0 * maximize_product(x, threshold, fixed_p2).first;
            result_row.push_back(optimal_value);
        }
        results.push_back(result_row);
    }
    return results;
}
