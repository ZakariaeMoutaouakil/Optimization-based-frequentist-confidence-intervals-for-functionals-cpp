#include "FactorialList.h"

std::vector<int> factorial_list(int n) {
    std::vector<int> factorials(n + 1, 1); // Initialize factorials list with 1s
    for (int i = 2; i <= n; ++i) {
        factorials[i] = factorials[i - 1] * i;
    }
    return factorials;
}
