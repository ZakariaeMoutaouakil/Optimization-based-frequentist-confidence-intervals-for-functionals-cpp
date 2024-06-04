#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

#include "distribution/final_filter/final_filter.h"
#include "distribution/find_closest_indices/find_closest_indices.h"
#include "distribution/quantile_1_minus_alpha/quantile_1_minus_alpha.h"
#include "distribution/bin_second_largest_values/bin_second_largest_values.h"
#include "optimization/log_likelihood_grid/log_likelihood_grid.h"
#include "utils/discrete_simplex/discrete_simplex.h"
#include "utils/enlarge_matrix/enlarge_matrix.h"
#include "utils/FactorialList/FactorialList.h"
#include "utils/FilterVectors/FilterVectors.h"
#include "utils/MultinomialCoefficient/MultinomialCoefficient.h"
#include "utils/Multinomial/Multinomial.h"
#include "utils/normalize_vectors/normalize_vectors.h"
#include "utils/sample_space/sample_space.h"
#include "utils/unique_vectors/unique_vectors.h"
#include "utils/unique_vector_indices/unique_vector_indices.h"

int main() {
    using namespace std::chrono;
    using namespace std;

    constexpr int n = 10;
    constexpr int m = 3;
    constexpr int precision = 20;
    constexpr double threshold = 0.8;
    constexpr double bin_width = 0.01;

    const auto start_time = high_resolution_clock::now();

    // Generate constraint set
    const auto simplex = discrete_simplex(m, precision);
    const auto probability_simplex = normalize_vectors(simplex);
    const auto filtered_probability_simplex = filter_vectors_by_max_value(
        probability_simplex, threshold
    );
    const auto constraint_set = unique_vectors(filtered_probability_simplex);

    // Generate fixed p2s
    const auto fixed_p2s = bin_second_largest_values(constraint_set, bin_width);

    // Generate ordered sample space
    const auto ordered_x = sample_space(m, n);

    // Generate likelihood
    const auto likelihood = log_likelihood_grid(ordered_x, threshold, fixed_p2s);
    const auto full_x = discrete_simplex(m, n);
    const auto x_indices = unique_vector_indices(full_x, ordered_x);
    const auto full_likelihood = enlarge_matrix(likelihood, x_indices);

    // Generate probability grid
    const auto factorials = factorial_list(n);
    const auto multinomial_coefficients = multinomial_coefficient(full_x, factorials);
    const auto probability_grid = calculate_multinomial_probability_grid(
        multinomial_coefficients, constraint_set, full_x
    );

    // Calculate quantiles
    const auto indices = find_closest_indices(constraint_set, fixed_p2s);
    vector<double> quantiles;
    for (size_t i = 0; i < probability_grid.size(); ++i) {
        constexpr double alpha = 0.05;
        quantiles.push_back(
            quantile_1_minus_alpha(likelihood[indices[i]], probability_grid[i], alpha)
        );
    }

    const vector observation = {n - 2, 1, 1};
    const auto final_result = final_filter(
        constraint_set, quantiles, observation, threshold
    );
    cout << "final_result: " << final_result << endl;

    const auto end_time = high_resolution_clock::now();
    const duration<double> elapsed = end_time - start_time;
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
