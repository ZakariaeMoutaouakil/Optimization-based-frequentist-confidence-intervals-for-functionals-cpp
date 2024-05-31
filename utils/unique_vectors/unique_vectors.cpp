#include "unique_vectors.h"
#include <set>
#include <vector>

std::vector<std::vector<double>> unique_vectors(const std::vector<std::vector<double>>& vectors) {
    std::set<std::set<double>> seen;
    std::vector<std::vector<double>> unique_list;

    for (const auto& vector : vectors) {
        std::set<double> vector_set(vector.begin(), vector.end());
        if (seen.find(vector_set) == seen.end()) {
            seen.insert(vector_set);
            unique_list.push_back(vector);
        }
    }

    return unique_list;
}
