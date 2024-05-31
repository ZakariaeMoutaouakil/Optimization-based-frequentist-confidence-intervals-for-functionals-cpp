#include "unique_vectors.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<double>> vecs = {
        {0.1, 0.2, 0.3},
        {0.3, 0.2, 0.1},
        {0.5, 0.4, 0.6},
        {0.7, 0.8, 0.9},
        {0.2, 0.1, 0.3}
    };

    std::vector<std::vector<double>> unique_vectors_list = unique_vectors(vecs);

    std::cout << "Unique vectors:" << std::endl;
    for (const auto& vec : unique_vectors_list) {
        std::cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
