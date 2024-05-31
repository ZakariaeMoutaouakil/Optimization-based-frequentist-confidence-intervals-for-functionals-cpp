//
// Created by pc on 31/05/24.
//
#include <iostream>
#include <vector>
#include <chrono>
#include "discrete_simplex.h"

int main() {
    int k = 5;
    int n = 40;

    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<double> > example_simplex = discrete_simplex(k, n);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end_time - start_time;

    for (const auto &p: example_simplex) {
        for (double val: p) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
