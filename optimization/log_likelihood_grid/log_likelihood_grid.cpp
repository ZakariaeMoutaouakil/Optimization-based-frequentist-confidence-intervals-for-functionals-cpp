#include "log_likelihood_grid.h"
#include "../maximize_product_list/maximize_product_list.h"
#include "../maximize_product_grid/maximize_product_grid.h"

std::vector<std::vector<double>> log_likelihood_grid(const std::vector<std::vector<double>>& xs, double threshold, const std::vector<double>& fixed_p2s) {
    std::vector<std::vector<double>> results;

    // Calculate the maximized product for each input data using the `maximize_product_list` function
    std::vector<double> maximize_product_xs = maximize_product_list(xs, threshold);

    // Calculate the maximized product for each fixed p_2 value using the `maximize_product_grid` function
    std::vector<std::vector<double>> maximize_product_fixed_p2 = maximize_product_grid(xs, threshold, fixed_p2s);

    // Combine the maximized product values for each input data and fixed p_2 value by adding them element-wise
    for (const auto& fixed_p2_list : maximize_product_fixed_p2) {
        std::vector<double> combined_values;
        for (size_t i = 0; i < maximize_product_xs.size(); ++i) {
            combined_values.push_back(maximize_product_xs[i] + fixed_p2_list[i]);
        }
        results.push_back(combined_values);
    }

    return results;
}
