#include "quantile_1_minus_alpha.h"
#include <vector>
#include <algorithm>

float quantile_1_minus_alpha(const std::vector<float>& values, const std::vector<float>& probabilities, float alpha) {
    std::vector<std::pair<float, float>> value_prob_pairs;
    for (size_t i = 0; i < values.size(); ++i) {
        value_prob_pairs.emplace_back(values[i], probabilities[i]);
    }

    std::sort(value_prob_pairs.begin(), value_prob_pairs.end());

    float cumulative_probability = 0.0f;
    float quantile_threshold = 1.0f - alpha;

    for (const auto& pair : value_prob_pairs) {
        cumulative_probability += pair.second;
        if (cumulative_probability >= quantile_threshold) {
            return pair.first;
        }
    }

    // If the loop completes, return the last value
    return value_prob_pairs.back().first;
}
