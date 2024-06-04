#include "quantile_1_minus_alpha.h"
#include <iostream>
#include <vector>

int main() {
    const std::vector vals = {1.0, 2.0, 3.0, 4.0, 5.0};
    const std::vector probas = {0.1, 0.2, 0.3, 0.2, 0.2};
    constexpr double risk = 0.5;

    const double quantile = quantile_1_minus_alpha(vals, probas, risk);
    std::cout << "The quantile of order " << (1 - risk) * 100 << "% is: " << quantile << std::endl;

    return 0;
}
