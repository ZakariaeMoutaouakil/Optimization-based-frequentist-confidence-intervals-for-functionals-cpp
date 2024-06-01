#ifndef MULTINOMIALCOEFFICIENT_H
#define MULTINOMIALCOEFFICIENT_H

#include <gmpxx.h>
#include <vector>

std::vector<mpz_class> multinomial_coefficient(const std::vector<std::vector<int>>& vectors, const std::vector<mpz_class>& factorials);

#endif // MULTINOMIALCOEFFICIENT_H
