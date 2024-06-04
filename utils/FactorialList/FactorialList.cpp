#include "FactorialList.h"

std::vector<mpz_class> factorial_list(const int n) {
    std::vector<mpz_class> factorials(n + 1, 1); // Initialize factorials list with 1s
    for (int i = 2; i <= n; ++i) {
        factorials[i] = factorials[i - 1] * i;
    }
    return factorials;
}
