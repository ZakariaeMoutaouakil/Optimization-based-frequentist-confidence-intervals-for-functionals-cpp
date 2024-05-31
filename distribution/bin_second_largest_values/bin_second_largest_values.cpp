#include "bin_second_largest_values.h"
#include <vector>
#include <algorithm>
#include <set>

std::vector<double> bin_second_largest_values(const std::vector<std::vector<double>>& prob_vectors, double bin_width) {
    std::vector<double> second_largest_values;
    for (const auto& vector : prob_vectors) {
        std::vector<double> sorted_vector = vector;
        std::sort(sorted_vector.begin(), sorted_vector.end());
        second_largest_values.push_back(sorted_vector[sorted_vector.size() - 2]);
    }

    std::set<double> binned_values_set;
    for (const auto& value : second_largest_values) {
        double binned_value = (static_cast<int>(value / bin_width)) * bin_width;
        if (binned_value != 0) {
            binned_values_set.insert(binned_value);
        }
    }

    std::vector<double> binned_values(binned_values_set.begin(), binned_values_set.end());
    std::sort(binned_values.begin(), binned_values.end());

    return binned_values;
}
