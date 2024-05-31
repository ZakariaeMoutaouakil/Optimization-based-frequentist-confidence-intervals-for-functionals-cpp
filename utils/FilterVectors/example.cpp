#include "FilterVectors.h"
#include <iostream>

int main() {
    std::vector<std::vector<double>> vecs = {
        {0.1, 0.2, 0.3},
        {0.5, 0.4, 0.6},
        {0.7, 0.8, 0.9},
        {0.2, 0.3, 0.1}
    };
    float thresh = 0.5f;

    std::vector<std::vector<double>> filtered_vectors = filter_vectors_by_max_value(vecs, thresh);

    std::cout << "Filtered vectors:" << std::endl;
    for (const auto& vector : filtered_vectors) {
        for (double value : vector) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
