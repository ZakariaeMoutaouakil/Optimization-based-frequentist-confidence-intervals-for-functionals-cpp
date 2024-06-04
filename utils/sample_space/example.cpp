#include <iostream>
#include <chrono>
#include "sample_space.h" // Include the source file directly

using namespace std;

int main() {
    int k = 3;
    int n = 5;

    auto start_time = chrono::high_resolution_clock::now();

    vector<vector<int>> vectors = sample_space(k, n);

    auto end_time = chrono::high_resolution_clock::now();

    cout << "Vectors:" << endl;
    for (const auto& vec : vectors) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    chrono::duration<double, std::nano> diff = end_time - start_time;

    cout << "Time taken: " << diff.count() / 1e9 << " seconds" << endl;

    return 0;
}
