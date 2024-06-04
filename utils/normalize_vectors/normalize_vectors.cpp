#include <vector>
#include <numeric>

std::vector<std::vector<double> > normalize_vectors(const std::vector<std::vector<int> > &data) {
    std::vector<std::vector<double> > normalized_data;
    for (const auto &vec: data) {
        // Calculate the sum using std::accumulate

        // Handle zero sum
        if (const double sum = std::accumulate(vec.begin(), vec.end(), 0.0); sum == 0.0) {
            normalized_data.emplace_back(vec.size(), 0.0);
        } else {
            // Normalize each element
            std::vector<double> normalized_vec;
            for (const int num: vec) {
                normalized_vec.push_back(static_cast<double>(num) / sum);
            }
            normalized_data.push_back(normalized_vec);
        }
    }
    return normalized_data;
}
