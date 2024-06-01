#ifndef FINAL_FILTER_H
#define FINAL_FILTER_H

#include <gmpxx.h>
#include <vector>

double final_filter(const std::vector<std::vector<double>>& vectors, const std::vector<double>& quantiles,
                    const std::vector<double>& x, const std::vector<mpz_class>& multinomial_coefficients,
                    int index_of_sample, double threshold);

#endif // FINAL_FILTER_H
