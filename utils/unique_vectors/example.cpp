#include "unique_vectors.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<float>> vecs = {
        {0.1f, 0.2f, 0.3f},
        {0.3f, 0.2f, 0.1f},
        {0.5f, 0.4f, 0.6f},
        {0.7f, 0.8f, 0.9f},
        {0.2f, 0.1f, 0.3f}
    };

    std::vector<std::vector<float>> unique_vectors_list = unique_vectors(vecs);

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
