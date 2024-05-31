#include "bin_second_largest_values.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<float>> vectors = {
        {0.1f, 0.2f, 0.3f, 0.4f},
        {0.25f, 0.25f, 0.25f, 0.25f},
        {0.4f, 0.3f, 0.2f, 0.1f},
        {0.05f, 0.05f, 0.05f, 0.85f}
    };
    float width = 0.1f;

    std::vector<float> results = bin_second_largest_values(vectors, width);
    std::cout << "Binned second largest values: ";
    for (const auto& value : results) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
