#include "enlarge_matrix.h"

std::vector<std::vector<double> > enlarge_matrix(const std::vector<std::vector<double> > &unique_matrix,
                                                 const std::vector<int> &mapping) {
    if (unique_matrix.empty() || mapping.empty()) {
        return {};
    }

    const size_t num_rows = unique_matrix.size();
    const size_t num_cols = mapping.size();

    std::vector enlarged_matrix(num_rows, std::vector<double>(num_cols));

    for (size_t i = 0; i < num_rows; ++i) {
        for (size_t j = 0; j < num_cols; ++j) {
            enlarged_matrix[i][j] = unique_matrix[i][mapping[j]];
        }
    }

    return enlarged_matrix;
}
