#ifndef LOG_LIKELIHOOD_GRID_H
#define LOG_LIKELIHOOD_GRID_H

#include <vector>

std::vector<std::vector<double> > log_likelihood_grid(const std::vector<std::vector<int> > &xs,
                                                      double threshold,
                                                      const std::vector<double> &fixed_p2s);

#endif // LOG_LIKELIHOOD_GRID_H
