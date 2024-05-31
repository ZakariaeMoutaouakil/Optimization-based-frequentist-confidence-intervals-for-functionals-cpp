#include "bin_second_largest_values.h"
#include <vector>
#include <algorithm>
#include <set>

std::vector<float> bin_second_largest_values(const std::vector<std::vector<float>>& prob_vectors, float bin_width) {
    std::vector<float> second_largest_values;
    for (const auto& vector : prob_vectors) {
        std::vector<float> sorted_vector = vector;
        std::sort(sorted_vector.begin(), sorted_vector.end());
        second_largest_values.push_back(sorted_vector[sorted_vector.size() - 2]);
    }

    std::set<float> binned_values_set;
    for (const auto& value : second_largest_values) {
        float binned_value = (static_cast<int>(value / bin_width)) * bin_width;
        if (binned_value != 0) {
            binned_values_set.insert(binned_value);
        }
    }

    std::vector<float> binned_values(binned_values_set.begin(), binned_values_set.end());
    std::sort(binned_values.begin(), binned_values.end());

    return binned_values;
}
