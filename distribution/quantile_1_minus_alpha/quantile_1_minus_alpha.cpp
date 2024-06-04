#include "quantile_1_minus_alpha.h"
#include <vector>
#include <algorithm>

double quantile_1_minus_alpha(const std::vector<double> &values, const std::vector<double> &probabilities,
                              const double alpha) {
    std::vector<std::pair<double, double> > value_prob_pairs;
    for (size_t i = 0; i < values.size(); ++i) {
        value_prob_pairs.emplace_back(values[i], probabilities[i]);
    }

    std::sort(value_prob_pairs.begin(), value_prob_pairs.end());

    double cumulative_probability = 0.0;
    const double quantile_threshold = 1.0 - alpha;

    for (const auto &[fst, snd]: value_prob_pairs) {
        cumulative_probability += snd;
        if (cumulative_probability >= quantile_threshold) {
            return fst;
        }
    }

    // If the loop completes, return the last value
    return value_prob_pairs.back().first;
}
