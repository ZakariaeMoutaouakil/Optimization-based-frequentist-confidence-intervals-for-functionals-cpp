#include "unique_vector_indices.h"
#include <unordered_map>
#include <functional>
#include <set>

// Custom hash function for std::set<int> (assuming elements are integers)
struct SetHash {
    std::size_t operator()(const std::set<int> &s) const {
        std::size_t hash = 0;
        for (const int &val: s) {
            hash ^= std::hash<int>{}(val) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

std::vector<int> unique_vector_indices(const std::vector<std::vector<int> > &raw_vectors,
                                       const std::vector<std::vector<int> > &unique_vectors) {
    std::unordered_map<std::set<int>, int, SetHash> unique_map;

    for (int i = 0; i < unique_vectors.size(); ++i) {
        std::set<int> vector_set(unique_vectors[i].begin(), unique_vectors[i].end());
        unique_map[vector_set] = i;
    }

    std::vector<int> indices;
    for (const auto &vector: raw_vectors) {
        std::set<int> vector_set(vector.begin(), vector.end());
        indices.push_back(unique_map[vector_set]);
    }

    return indices;
}
