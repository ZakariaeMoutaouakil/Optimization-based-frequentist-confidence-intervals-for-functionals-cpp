#ifndef MAXIMIZE_PRODUCT_H
#define MAXIMIZE_PRODUCT_H

#include <vector>
#include <utility>

// Function declaration for sum_constraint
double sum_constraint(const std::vector<double> &p, std::vector<double> &grad, void *data);

// Function declaration for maximize_product
std::pair<double, std::vector<double> > maximize_product(const std::vector<int> &x,
                                                         double threshold,
                                                         double fixed_p2 = -1.);

#endif // MAXIMIZE_PRODUCT_H
