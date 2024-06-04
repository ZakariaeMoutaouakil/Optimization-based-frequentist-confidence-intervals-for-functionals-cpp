#include <iostream>
#include "normalize_vectors.cpp" // Include source file directly
#include <vector>
#include <chrono>

using namespace std;

int main() {
    vector<vector<int>> data = {{1, 2, 3}, {4, 0, 6}, {5, 1, 0}};

    const auto start_time = chrono::high_resolution_clock::now();

    vector<vector<double>> normalized_data = normalize_vectors(data);

    const auto end_time = chrono::high_resolution_clock::now();

    cout << "Original data:" << endl;
    for (const auto& vec : data) {
        for (const int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << endl << "Normalized data:" << endl;
    for (const auto& vec : normalized_data) {
        for (const double num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    const chrono::duration<double, std::nano> diff = end_time - start_time;

    cout << "Time taken: " << diff.count() / 1e9 << " seconds" << endl;

    return 0;
}
