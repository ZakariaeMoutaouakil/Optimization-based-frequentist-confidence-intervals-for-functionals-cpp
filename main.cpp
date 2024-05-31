#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cmath>
#include <cassert>
#include <algorithm>

#include "distribution/final_filter/final_filter.h"
#include "distribution/find_closest_indices/find_closest_indices.h"
#include "distribution/quantile_1_minus_alpha/quantile_1_minus_alpha.h"
#include "distribution/bin_second_largest_values/bin_second_largest_values.h"
#include "optimization/log_likelihood_grid/log_likelihood_grid.h"
#include "utils/discrete_simplex/discrete_simplex.h"
#include "utils/FactorialList/FactorialList.h"
#include "utils/FilterVectors/FilterVectors.h"
#include "utils/MultinomialCoefficient/MultinomialCoefficient.h"
#include "utils/Multinomial/Multinomial.h"
#include "utils/unique_vectors/unique_vectors.h"

// Function to convert seconds to minutes and leftover seconds
std::pair<int, float> seconds_to_minutes(float seconds) {
    int minutes = static_cast<int>(seconds / 60);
    float leftover_seconds = std::fmod(seconds, 60);
    return {minutes, leftover_seconds};
}

int main() {
    int n = 35;
    int m = 3;

    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<double>> sample_space = discrete_simplex(m, n, false);

    float threshold = 0.9;
    int precision = 103;
    float bin_width = 0.001;

    std::vector<std::vector<double>> simplex = discrete_simplex(m, precision, true);
    // std::cout << "simplex: " << simplex << std::endl;

    std::vector<std::vector<float>> filtered_simplex = filter_vectors_by_max_value(()simplex, threshold);
    // std::cout << "filtered_simplex: " << filtered_simplex << std::endl;

    std::vector<std::vector<float>> constraint_set = unique_vectors(filtered_simplex);
    // std::cout << "constraint_set: " << constraint_set << std::endl;

    std::vector<float> fixed_p2s = bin_second_largest_values(constraint_set, bin_width);
    // std::cout << "fixed_p2s: " << fixed_p2s << std::endl;

    std::vector<std::vector<double>> likelihood = log_likelihood_grid(sample_space, threshold, fixed_p2s);
    assert(likelihood.size() == fixed_p2s.size());
    // std::cout << "likelihood: " << likelihood << std::endl;
    // std::cout << "length of likelihood: " << likelihood.size() << std::endl;

    std::vector<unsigned long long> factorials = factorial_list(n);
    std::vector<int> multinomial_coefficients = multinomial_coefficient(sample_space, factorials);
    std::vector<std::vector<double>> probabilities = calculate_multinomial_probability_grid(multinomial_coefficients, constraint_set, sample_space);
    // std::cout << "probabilities: " << probabilities << std::endl;
    // std::cout << "length of probabilities: " << probabilities.size() << std::endl;

    std::vector<int> indices = find_closest_indices(constraint_set, fixed_p2s);
    // std::cout << "indices: " << indices << std::endl;
    assert(indices.size() == probabilities.size());

    float alpha = 0.05;
    std::vector<double> quantiles;
    for (size_t i = 0; i < probabilities.size(); ++i) {
        quantiles.push_back(quantile_1_minus_alpha(likelihood[indices[i]], probabilities[i], alpha));
    }
    // std::cout << "quantiles: " << quantiles << std::endl;

    std::vector<int> observation = {n - 2, 1, 1};
    auto it = std::find(sample_space.begin(), sample_space.end(), observation);
    assert(it != sample_space.end());
    int index_of_observation = std::distance(sample_space.begin(), it);
    // std::cout << "observation: " << observation << std::endl;
    assert(observation.size() == static_cast<size_t>(m));

    std::vector<double> sample_probability;
    for (int value : observation) {
        sample_probability.push_back(static_cast<double>(value) / n);
    }
    // std::cout << "sample_probability: " << sample_probability << std::endl;
    assert(*std::max_element(sample_probability.begin(), sample_probability.end()) >= threshold);

    double final_result = final_filter(constraint_set, quantiles, observation, multinomial_coefficients, index_of_observation, threshold);
    std::cout << "final result: " << final_result << std::endl;

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> time_taken = end_time - start_time;

    if (time_taken.count() > 60) {
        auto [minutes_taken, seconds_taken] = seconds_to_minutes(time_taken.count());
        std::cout << "Time taken: " << minutes_taken << " minutes and " << seconds_taken << " seconds" << std::endl;
    } else {
        std::cout << "Time taken: " << time_taken.count() << " seconds" << std::endl;
    }

    std::string file_path = "results.txt";
    std::ofstream file;
    if (!std::ifstream(file_path)) {
        file.open(file_path, std::ios::out);
        file << "n\tm\tthreshold\tprecision\tbin_width\talpha\tobservation\tfinal_result\ttime_taken\n";
        std::cout << file_path << " has been created." << std::endl;
    } else {
        std::cout << file_path << " already exists." << std::endl;
    }

    file.open(file_path, std::ios::app);
    file << n << '\t' << m << '\t' << threshold << '\t' << precision << '\t' << bin_width << '\t' << alpha << '\t';
    for (const auto& val : observation) file << val << ',';
    file << '\t' << final_result << '\t' << time_taken.count() << '\n';
    file.close();

    return 0;
}