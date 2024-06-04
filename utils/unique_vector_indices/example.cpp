#include <iostream>
#include "unique_vector_indices.h"
#include <set>
#include <chrono>

std::vector<std::vector<double> > unique_vectors(const std::vector<std::vector<double> > &vectors) {
    std::set<std::set<double> > seen;
    std::vector<std::vector<double> > unique_list;

    for (const auto &vector: vectors) {
        if (std::set vector_set(vector.begin(), vector.end()); seen.find(vector_set) == seen.end()) {
            seen.insert(vector_set);
            unique_list.push_back(vector);
        }
    }

    return unique_list;
}

int main() {
    const std::vector<std::vector<double> > raw_vectors = {
        {1.0, 2.0, 3.0},
        {3.0, 2.0, 1.0},
        {4.0, 5.0, 6.0},
        {1.0, 2.0, 3.0}
    };

    const std::vector<std::vector<double> > unique_vectors_list = unique_vectors(raw_vectors);

    const auto start_time = std::chrono::high_resolution_clock::now();

    const std::vector<int> indices = unique_vector_indices(raw_vectors, unique_vectors_list);

    const auto end_time = std::chrono::high_resolution_clock::now();

    std::cout << "Indices: ";
    for (const int index: indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    const std::chrono::duration<double, std::nano> diff = end_time - start_time;

    std::cout << "Time taken: " << diff.count() / 1e9 << " seconds" << std::endl;

    return 0;
}
