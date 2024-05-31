#include "find_closest_indices.h"
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

double second_largest_value(const std::vector<double> &numbers) {
    double first = -std::numeric_limits<double>::infinity();
    double second = -std::numeric_limits<double>::infinity();
    for (const auto &number: numbers) {
        if (number > first) {
            second = first;
            first = number;
        } else if (number > second && number < first) {
            second = number;
        }
    }
    return second;
}

int closest_index(double target, const std::vector<double> &floats) {
    int closest_idx = 0;
    double min_diff = std::abs(floats[0] - target);
    for (size_t i = 1; i < floats.size(); ++i) {
        double diff = std::abs(floats[i] - target);
        if (diff < min_diff) {
            closest_idx = static_cast<int>(i);
            min_diff = diff;
        }
    }
    return closest_idx;
}

std::vector<int> find_closest_indices(const std::vector<std::vector<double> > &vectors,
                                      const std::vector<double> &values) {
    std::vector<int> result;
    for (const auto &vector: vectors) {
        double sec_largest = second_largest_value(vector);
        int index = closest_index(sec_largest, values);
        result.push_back(index);
    }
    return result;
}
