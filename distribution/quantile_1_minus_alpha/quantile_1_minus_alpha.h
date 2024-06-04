#ifndef QUANTILE_1_MINUS_ALPHA_H
#define QUANTILE_1_MINUS_ALPHA_H

#include <vector>

double quantile_1_minus_alpha(const std::vector<double> &values, const std::vector<double> &probabilities,
                              double alpha);

#endif // QUANTILE_1_MINUS_ALPHA_H
