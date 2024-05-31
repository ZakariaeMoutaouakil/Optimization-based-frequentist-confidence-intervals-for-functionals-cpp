#include "quantile_1_minus_alpha.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<float> vals = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::vector<float> probas = {0.1f, 0.2f, 0.3f, 0.2f, 0.2f};
    float risk = 0.5f;

    float quantile = quantile_1_minus_alpha(vals, probas, risk);
    std::cout << "The quantile of order " << (1 - risk) * 100 << "% is: " << quantile << std::endl;

    return 0;
}
