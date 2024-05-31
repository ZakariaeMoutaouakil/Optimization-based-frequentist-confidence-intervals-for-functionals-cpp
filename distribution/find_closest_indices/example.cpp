#include "find_closest_indices.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<float>> vecs = {
        {4.0f, 2.0f, 5.0f},
        {1.0f, 3.0f, 2.0f},
        {8.0f, 7.0f, 6.0f}
    };
    std::vector<float> vals = {2.5f, 4.1f, 6.0f, 7.5f};

    std::vector<int> indices = find_closest_indices(vecs, vals);

    std::cout << "Closest indices: ";
    for (const auto& index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
