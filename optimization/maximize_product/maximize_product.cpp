#include "maximize_product.h"
#include <iostream>
#include <nlopt.hpp>
#include <cmath>
#include <vector>

// Constraint for the sum of probabilities to be less than or equal to 1
double sum_constraint(const std::vector<double>& p, std::vector<double>& grad, void* data) {
    double sum = 0;
    for (double pi : p) {
        sum += pi;
    }
    return sum - 1.0;
}

// Constraint for ensuring p[i] >= p[i+1] for all i
double non_increasing_constraint(const std::vector<double>& p, std::vector<double>& grad, void* data) {
    for (size_t i = 0; i < p.size() - 1; ++i) {
        if (p[i] < p[i + 1]) {
            return p[i + 1] - p[i];
        }
    }
    return 0.0;
}

std::pair<double, std::vector<double>> maximize_product(const std::vector<double>& x, double threshold, double fixed_p2) {
    int n = x.size();
    nlopt::opt opt(nlopt::LN_COBYLA, n); // Using the COBYLA algorithm for optimization

    std::vector<double> lb(n, 0); // lower bounds for p
    lb[0] = threshold; // p_1 must be at least the threshold
    opt.set_lower_bounds(lb);

    if (fixed_p2 > 0) {
        opt.add_equality_constraint([](const std::vector<double>& p, std::vector<double>& grad, void* data) {
            if (!grad.empty()) {
                grad[1] = 1;
            }
            return p[1] - *(double*)data;
        }, &fixed_p2, 1e-8);
    }

    opt.add_inequality_constraint(sum_constraint, nullptr, 1e-8);
    opt.add_inequality_constraint(non_increasing_constraint, nullptr, 1e-8);

    opt.set_min_objective([](const std::vector<double>& p, std::vector<double>& grad, void* f_data) {
        const std::vector<double>& x = *(std::vector<double>*)f_data;
        double result = 0;
        for (int i = 0; i < p.size(); i++) {
            result -= x[i] * log(p[i]);
        }
        if (!grad.empty()) {
            for (int i = 0; i < p.size(); i++) {
                grad[i] = -x[i] / p[i];
            }
        }
        return result;
    }, (void*)&x);

    // Tighter tolerance levels for better numerical stability
    opt.set_xtol_rel(1e-6);
    opt.set_ftol_rel(1e-6);

    // Improved initial guess
    std::vector<double> p(n, 1.0 / n);
    p[0] = threshold + 1e-3;
    if (fixed_p2 > 0) {
        p[1] = fixed_p2;
        for (int i = 2; i < n; ++i) {
            p[i] = (1.0 - threshold - fixed_p2) / (n - 2);
        }
    } else {
        for (int i = 1; i < n; ++i) {
            p[i] = (1.0 - threshold) / (n - 1);
        }
    }

    double minf;
    try {
        nlopt::result result = opt.optimize(p, minf);
        std::cout << "Found minimum at f = " << minf << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "NLopt failed: " << e.what() << std::endl;
    }

    return {-minf, p}; // Return negative because we were minimizing the negative log-product
}
