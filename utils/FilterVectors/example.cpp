#include "FilterVectors.h"
#include <iostream>

int main() {
    std::vector<std::vector<float>> vecs = {
        {0.1f, 0.2f, 0.3f},
        {0.5f, 0.4f, 0.6f},
        {0.7f, 0.8f, 0.9f},
        {0.2f, 0.3f, 0.1f}
    };
    float thresh = 0.5f;

    std::vector<std::vector<float>> filtered_vectors = filter_vectors_by_max_value(vecs, thresh);

    std::cout << "Filtered vectors:" << std::endl;
    for (const auto& vector : filtered_vectors) {
        for (float value : vector) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
