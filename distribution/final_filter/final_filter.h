#ifndef FINAL_FILTER_H
#define FINAL_FILTER_H

#include <vector>

double second_largest(const std::vector<double>& numbers);
std::vector<double> second_largest_of_vectors(const std::vector<std::vector<double>>& vectors);
double final_filter(const std::vector<std::vector<double>>& vectors, const std::vector<double>& quantiles,
                    const std::vector<double>& x, const std::vector<int>& multinomial_coefficients,
                    int index_of_sample, double threshold);

#endif // FINAL_FILTER_H
