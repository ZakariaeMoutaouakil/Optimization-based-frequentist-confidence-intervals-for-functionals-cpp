#ifndef MAXIMIZE_PRODUCT_GRID_H
#define MAXIMIZE_PRODUCT_GRID_H

#include <vector>

std::vector<std::vector<double> > maximize_product_grid(const std::vector<std::vector<int> > &xs,
                                                        double threshold,
                                                        const std::vector<double> &fixed_p2s);

#endif // MAXIMIZE_PRODUCT_GRID_H
