#include <iostream>
#include <chrono>
#include "normalized_sample_space.h" // Include the source file directly


using namespace std;

int main() {
    constexpr int k = 3;
    constexpr int n = 5;

    const auto start_time = chrono::high_resolution_clock::now();

    vector<vector<double> > normalized_vectors = normalized_sample_space(k, n);

    const auto end_time = chrono::high_resolution_clock::now();

    cout << "Normalized vectors:" << endl;
    for (const auto &vec: normalized_vectors) {
        for (const double num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    const chrono::duration<double, std::nano> diff = end_time - start_time;

    cout << "Time taken: " << diff.count() / 1e9 << " seconds" << endl;

    return 0;
}
