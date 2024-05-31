#include "find_closest_indices.h"
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

float second_largest(const std::vector<float>& numbers) {
    float first = -std::numeric_limits<float>::infinity();
    float second = -std::numeric_limits<float>::infinity();
    for (const auto& number : numbers) {
        if (number > first) {
            second = first;
            first = number;
        } else if (number > second && number < first) {
            second = number;
        }
    }
    return second;
}

int closest_index(float target, const std::vector<float>& floats) {
    int closest_idx = 0;
    float min_diff = std::abs(floats[0] - target);
    for (size_t i = 1; i < floats.size(); ++i) {
        float diff = std::abs(floats[i] - target);
        if (diff < min_diff) {
            closest_idx = i;
            min_diff = diff;
        }
    }
    return closest_idx;
}

std::vector<int> find_closest_indices(const std::vector<std::vector<float>>& vectors, const std::vector<float>& values) {
    std::vector<int> result;
    for (const auto& vector : vectors) {
        float sec_largest = second_largest(vector);
        int index = closest_index(sec_largest, values);
        result.push_back(index);
    }
    return result;
}
