#ifndef FINAL_FILTER_H
#define FINAL_FILTER_H

#include <vector>

double final_filter(const std::vector<std::vector<double> > &vectors,
                    const std::vector<double> &quantiles,
                    const std::vector<int> &x,
                    double threshold);

#endif // FINAL_FILTER_H
