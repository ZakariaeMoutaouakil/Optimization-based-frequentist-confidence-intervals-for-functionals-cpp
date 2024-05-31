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

std::pair<int, double> seconds_to_minutes(double seconds) {
    int minutes = static_cast<int>(seconds / 60);
    double leftover_seconds = fmod(seconds, 60);
    return {minutes, leftover_seconds};
}

std::vector<std::vector<int> > convert_to_int(const std::vector<std::vector<double> > &double_vectors) {
    std::vector<std::vector<int> > int_vectors;
    int_vectors.reserve(double_vectors.size()); // Reserve space for efficiency

    for (const auto &double_vector: double_vectors) {
        std::vector<int> int_vector;
        int_vector.reserve(double_vector.size()); // Reserve space for efficiency

        for (double value: double_vector) {
            int_vector.push_back(static_cast<int>(value)); // Use static_cast to convert double to int
        }

        int_vectors.push_back(int_vector);
    }

    return int_vectors;
}


std::vector<double> convert_to_double(const std::vector<int> &int_vector) {
    std::vector<double> double_vector;
    double_vector.reserve(int_vector.size()); // Reserve space for efficiency

    for (int value: int_vector) {
        double_vector.push_back(static_cast<double>(value)); // Use static_cast to convert int to double
    }

    return double_vector;
}

int main() {
    using namespace std::chrono;
    using namespace std;

    int n = 25;
    int m = 3;

    auto start_time = high_resolution_clock::now();

    vector<vector<double>> sample_space = discrete_simplex(m, n, false);
    vector<vector<int>> sample_space_int = convert_to_int(sample_space);

    double threshold = 0.9;
    int precision = 103;
    double bin_width = 0.001;

    vector<vector<double> > simplex = discrete_simplex(m, precision, true);
    cout << "simplex: " << simplex.size() << endl;

    vector<vector<double> > filtered_simplex = filter_vectors_by_max_value(simplex, threshold);
    cout << "filtered_simplex: " << filtered_simplex.size() << endl;

    vector<vector<double> > constraint_set = unique_vectors(filtered_simplex);
    cout << "constraint_set: " << constraint_set.size() << endl;

    vector<double> fixed_p2s = bin_second_largest_values(constraint_set, bin_width);
    cout << "fixed_p2s: " << fixed_p2s.size() << endl;

    vector<vector<double> > likelihood = log_likelihood_grid(sample_space, threshold, fixed_p2s);
    assert(likelihood.size() == fixed_p2s.size());
    cout << "likelihood: " << likelihood.size() << endl;

    cout << "factorials_start: " << endl;
    vector<int> factorials = factorial_list(n);
    cout << "factorials_end: " << endl;

    vector<int> multinomial_coefficients = multinomial_coefficient(sample_space_int, factorials);
    vector<vector<double> > probabilities = calculate_multinomial_probability_grid(
        multinomial_coefficients, constraint_set, sample_space_int);
    cout << "probabilities: " << probabilities.size() << endl;

    vector<int> indices = find_closest_indices(constraint_set, fixed_p2s);
    cout << "indices: " << indices.size() << endl;
    assert(indices.size() == probabilities.size());

    double alpha = 0.05;
    vector<double> quantiles;
    for (size_t i = 0; i < probabilities.size(); ++i) {
        quantiles.push_back(quantile_1_minus_alpha(likelihood[indices[i]], probabilities[i], alpha));
    }
    cout << "quantiles: " << quantiles.size() << endl;

    vector<int> observation = {n - 2, 1, 1};
    vector<double> observation_double = convert_to_double(observation);
    int index_of_observation = static_cast<int>(distance(sample_space_int.begin(),
                                                         find(sample_space_int.begin(), sample_space_int.end(), observation)));
    cout << "observation: ";
    for (int val: observation) {
        cout << val << " ";
    }
    cout << endl;
    assert(observation.size() == static_cast<size_t>(m));
    vector<double> sample_probability;
    for (int x: observation) {
        sample_probability.push_back(static_cast<double>(x) / n);
    }
    cout << "sample_probability: ";
    for (double prob: sample_probability) {
        cout << prob << " ";
    }
    cout << endl;
    assert(*max_element(sample_probability.begin(), sample_probability.end()) >= threshold);

    cout << "index_of_observation: " << index_of_observation << endl;
    double final_result = final_filter(constraint_set, quantiles, observation_double, multinomial_coefficients,
                                       index_of_observation, threshold);
    cout << "final result: " << final_result << endl;

    auto end_time = high_resolution_clock::now();
    double time_taken = duration_cast<duration<double> >(end_time - start_time).count();
    if (time_taken > 60) {
        auto [minutes_taken, seconds_taken] = seconds_to_minutes(time_taken);
        cout << "Time taken: " << minutes_taken << " minutes and " << seconds_taken << " seconds" << endl;
    } else {
        cout << "Time taken: " << time_taken << " seconds" << endl;
    }

    string file_path = "results.tsv";
    ofstream file;
    if (!ifstream(file_path)) {
        file.open(file_path, ios::out);
        file << "n\tm\tthreshold\tprecision\tbin_width\talpha\tobservation\tfinal_result\ttime_taken\n";
        cout << file_path << " has been created." << endl;
    } else {
        file.open(file_path, ios::app);
        cout << file_path << " already exists." << endl;
    }

    file << n << "\t" << m << "\t" << threshold << "\t" << precision << "\t" << bin_width << "\t" << alpha << "\t";
    for (int val: observation) {
        file << val << " ";
    }
    file << "\t" << final_result << "\t" << time_taken << "\n";
    file.close();

    return 0;
}
