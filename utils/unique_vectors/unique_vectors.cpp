#include "unique_vectors.h"
#include <set>
#include <vector>
#include <algorithm>

std::vector<std::vector<float>> unique_vectors(const std::vector<std::vector<float>>& vectors) {
    std::set<std::set<float>> seen;
    std::vector<std::vector<float>> unique_list;

    for (const auto& vector : vectors) {
        std::set<float> vector_set(vector.begin(), vector.end());
        if (seen.find(vector_set) == seen.end()) {
            seen.insert(vector_set);
            unique_list.push_back(vector);
        }
    }

    return unique_list;
}
