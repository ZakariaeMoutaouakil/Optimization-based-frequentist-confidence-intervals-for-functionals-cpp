#include "bin_second_largest_values.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<double>> vectors = {
        {0.1, 0.2, 0.3, 0.4},
        {0.25, 0.25, 0.25, 0.25},
        {0.4, 0.3, 0.2, 0.1},
        {0.05, 0.05, 0.05, 0.85}
    };
    double width = 0.1;

    std::vector<double> results = bin_second_largest_values(vectors, width);
    std::cout << "Binned second largest values: ";
    for (const auto& value : results) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
