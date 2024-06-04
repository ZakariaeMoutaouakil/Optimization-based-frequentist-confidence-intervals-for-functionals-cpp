#include "FilterVectors.h"
#include <algorithm>

std::vector<std::vector<double> > filter_vectors_by_max_value(const std::vector<std::vector<double> > &vectors,
                                                              const double threshold) {
    std::vector<std::vector<double> > filtered_vectors;
    for (const auto &vector: vectors) {
        if (!vector.empty() && *std::max_element(vector.begin(), vector.end()) > threshold) {
            filtered_vectors.push_back(vector);
        }
    }
    return filtered_vectors;
}
