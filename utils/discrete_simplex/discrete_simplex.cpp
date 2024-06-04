#include "discrete_simplex.h"
#include <functional>

// Helper function to generate combinations with replacement that sum to n
void combinations_with_replacement(int n, int k, std::vector<std::vector<int> > &combs) {
    if (k == 0) {
        if (n == 0) {
            combs.emplace_back();
        }
        return;
    }

    if (k == 1) {
        combs.push_back({n});
        return;
    }

    for (int i = 0; i <= n; ++i) {
        std::vector<std::vector<int> > subcombs;
        combinations_with_replacement(n - i, k - 1, subcombs);
        for (auto &subcomb: subcombs) {
            subcomb.insert(subcomb.begin(), i);
            combs.push_back(subcomb);
        }
    }
}

std::vector<std::vector<int> > discrete_simplex(const int k, const int n) {
    std::vector<std::vector<int> > simplex;
    std::vector<std::vector<int> > combs;

    combinations_with_replacement(n, k, combs);

    for (const auto &comb: combs) {
        simplex.emplace_back(comb.begin(), comb.end());
    }

    return simplex;
}
