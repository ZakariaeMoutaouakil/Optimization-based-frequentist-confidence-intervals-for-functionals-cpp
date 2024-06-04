#ifndef DISCRETE_SIMPLEX_H
#define DISCRETE_SIMPLEX_H

#include <vector>

void combinations_with_replacement(int n, int k, std::vector<std::vector<int>>& combs);

std::vector<std::vector<double>> discrete_simplex(int k, int n);

#endif // DISCRETE_SIMPLEX_H
