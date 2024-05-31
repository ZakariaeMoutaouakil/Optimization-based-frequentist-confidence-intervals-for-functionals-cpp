#include <iostream>
#include <vector>
#include "final_filter.h"

int main() {
    std::vector<std::vector<double>> vectors = {
        {0.2, 0.3, 0.5},
        {0.1, 0.6, 0.3},
        {0.4, 0.4, 0.2}
    };
    std::vector<double> quantiles = {0.1, 0.2, 0.3};
    std::vector<double> x = {1.0, 2.0, 3.0};
    std::vector<int> multinomial_coefficients = {10, 20, 30};
    int index_of_sample = 1;
    double threshold = 0.8;

    double result = final_filter(vectors, quantiles, x, multinomial_coefficients, index_of_sample, threshold);
    std::cout << "Final filter result: " << result << std::endl;

    return 0;
}
