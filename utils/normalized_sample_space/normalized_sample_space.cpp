#include <vector>
#include "../sample_space/sample_space.h"
#include "normalized_sample_space.h"

std::vector<std::vector<double> > normalized_sample_space(const int k, const int n) {
    // Use sample_space to generate integer vectors
    std::vector<std::vector<int> > integer_vectors = sample_space(k, n);

    // Normalize integer vectors to floats in [0, 1] range
    std::vector<std::vector<double> > normalized_vectors;
    normalized_vectors.reserve(integer_vectors.size());
    for (const auto &vec: integer_vectors) {
        std::vector<double> normalized_vec;
        normalized_vec.reserve(vec.size());
        for (const int num: vec) {
            normalized_vec.push_back(static_cast<double>(num) / n);
        }
        normalized_vectors.push_back(std::move(normalized_vec));
    }

    return normalized_vectors;
}
