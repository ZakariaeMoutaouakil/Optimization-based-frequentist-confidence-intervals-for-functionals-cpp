#include <vector>
#include "sample_space.h"

void backtrack(int start, int dim, int num, std::vector<int>& path, std::vector<std::vector<int>>& res) {
    if (dim == 0) {
        if (num == 0) {
            res.push_back(path);
        }
        return;
    }
    for (int i = start; i <= num; ++i) {
        path.push_back(i);
        backtrack(i, dim - 1, num - i, path, res);
        path.pop_back();
    }
}

std::vector<std::vector<int>> sample_space(const int k, const int n) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    backtrack(0, k, n, path, result); // Start from 1 for inclusive range
    return result;
}


