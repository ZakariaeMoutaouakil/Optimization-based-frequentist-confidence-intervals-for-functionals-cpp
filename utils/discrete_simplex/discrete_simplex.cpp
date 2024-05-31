#include "discrete_simplex.h"
#include <numeric>
#include <algorithm>
#include <functional>

void combinations_with_replacement(int n, int k, std::vector<std::vector<int>>& combs) {
    std::vector<int> indices(k, 0);
    for (int i = 0; i < k; ++i) {
        indices[i] = i;
    }

    while (true) {
        combs.push_back(indices);
        int i;
        for (i = k - 1; i >= 0; --i) {
            if (indices[i] < n - (k - 1 - i)) {
                ++indices[i];
                for (int j = i + 1; j < k; ++j) {
                    indices[j] = indices[j - 1] + 1;
                }
                break;
            }
        }
        if (i < 0) {
            break;
        }
    }
}

std::vector<std::vector<double>> discrete_simplex(int k, int n, bool normalize) {
    std::vector<std::vector<double>> simplex;
    std::vector<std::vector<int>> combs;

    combinations_with_replacement(n + 1, k - 1, combs);

    for (const auto& comb : combs) {
        std::vector<int> point = {0};
        point.insert(point.end(), comb.begin(), comb.end());
        point.push_back(n);

        std::vector<int> diffs(k);
        std::adjacent_difference(point.begin(), point.end(), diffs.begin());
        diffs.erase(diffs.begin());

        if (normalize) {
            std::vector<double> normalized_point(k);
            std::transform(diffs.begin(), diffs.end(), normalized_point.begin(), [n](int x) {
                return static_cast<double>(x) / n;
            });
            simplex.push_back(normalized_point);
        } else {
            simplex.emplace_back(diffs.begin(), diffs.end());
        }
    }

    return simplex;
}
