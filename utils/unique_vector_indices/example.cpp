#include <iostream>
#include "unique_vector_indices.h"

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

int main() {
    const std::vector<std::vector<double>> raw_vectors = {
        {1.0, 2.0, 3.0},
        {3.0, 2.0, 1.0},
        {4.0, 5.0, 6.0},
        {1.0, 2.0, 3.0}
    };

    const std::vector<std::vector<double>> unique_vectors_list = unique_vectors(raw_vectors);

    const std::vector<int> indices = unique_vector_indices(raw_vectors, unique_vectors_list);

    std::cout << "Indices: ";
    for (const int index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
