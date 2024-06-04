#include <iostream>
#include <chrono>
#include "sample_space.h" // Include the source file directly

using namespace std;

int main() {
    constexpr int k = 3;
    constexpr int n = 5;

    const auto start_time = chrono::high_resolution_clock::now();

    vector<vector<int> > vectors = sample_space(k, n);

    const auto end_time = chrono::high_resolution_clock::now();

    cout << "Vectors:" << endl;
    for (const auto &vec: vectors) {
        for (const int num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    const chrono::duration<double, std::nano> diff = end_time - start_time;

    cout << "Time taken: " << diff.count() / 1e9 << " seconds" << endl;

    return 0;
}
