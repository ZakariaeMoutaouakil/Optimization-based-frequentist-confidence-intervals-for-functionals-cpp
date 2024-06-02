#include <iostream>
#include "../unique_vector_indices/unique_vector_indices.h"
#include "enlarge_matrix.h"

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
    std::vector<std::vector<double>> raw_vectors = {
        {1.0, 2.0, 3.0},
        {3.0, 2.0, 1.0},
        {4.0, 5.0, 6.0},
        {1.0, 2.0, 3.0}
    };

    std::vector<std::vector<double>> unique_vectors_list = unique_vectors(raw_vectors);
    std::vector<int> indices = unique_vector_indices(raw_vectors, unique_vectors_list);

    // Example unique matrix where each unique vector has associated values
    std::vector<std::vector<double>> unique_matrix = {
        {10.0, 20.0},
        {30.0, 40.0},
        {50.0, 60.0}
    };

    std::vector<std::vector<double>> enlarged_matrix = enlarge_matrix(unique_matrix, indices);

    std::cout << "Enlarged Matrix:" << std::endl;
    for (const auto& row : enlarged_matrix) {
        for (double value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
