#include "find_closest_indices.h"
#include <iostream>
#include <vector>

int main() {
    const std::vector<std::vector<double>> vecs = {
        {4.0, 2.0, 5.0},
        {1.0, 3.0, 2.0},
        {8.0, 7.0, 6.0}
    };
    const std::vector vals = {2.5, 4.1, 6.0, 7.5};

    const std::vector<int> indices = find_closest_indices(vecs, vals);

    std::cout << "Closest indices: ";
    for (const auto& index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
