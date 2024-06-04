#ifndef FILTERVECTORS_H
#define FILTERVECTORS_H

#include <vector>

std::vector<std::vector<double> > filter_vectors_by_max_value(const std::vector<std::vector<double> > &vectors,
                                                              double threshold);

#endif // FILTERVECTORS_H
