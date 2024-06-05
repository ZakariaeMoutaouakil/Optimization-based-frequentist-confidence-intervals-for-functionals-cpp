#include "compute_optimal_probabilities.h"
#include "../maximize_product/maximize_product.h"
#include <iostream>
#include <nlopt.hpp>
#include <cmath>
#include <chrono>

std::pair<double, std::vector<double> > compute_optimal_probabilities(const std::vector<int> &x) {
    const std::vector<double>::size_type n = x.size();
    nlopt::opt opt(nlopt::LN_COBYLA, n); // Using the COBYLA algorithm for optimization

    const std::vector<double> lb(n, 0); // lower bounds for p (all non-negative)
    opt.set_lower_bounds(lb);

    // Constraint for ensuring p[i] >= p[i+1] for all i
    opt.add_inequality_constraint(sum_constraint, nullptr, 1e-8);

    opt.set_min_objective([](const std::vector<double> &p, std::vector<double> &grad, void *f_data) {
        const std::vector<double> &vector = *static_cast<std::vector<double> *>(f_data);
        double result = 0;
        for (int i = 0; i < p.size(); i++) {
            result -= vector[i] * log(p[i]);
        }
        if (!grad.empty()) {
            for (int i = 0; i < p.size(); i++) {
                grad[i] = -vector[i] / p[i];
            }
        }
        return result;
    }, (void *) &x);

    // Tighter tolerance levels for better numerical stability
    opt.set_xtol_rel(1e-6);
    opt.set_ftol_rel(1e-6);

    // Improved initial guess (assuming all probabilities have equal weight)
    // std::vector p(n, 1.0 / static_cast<double>(n));
    std::vector p(n, 1.0);

    double minf;
    try {
        opt.optimize(p, minf);
    } catch (const std::exception &e) {
        std::cerr << "NLopt failed: " << e.what() << std::endl;
    }

    std::cout << "Found infimum at f = " << minf << std::endl;

    return {-minf, p}; // Return negative because we were minimizing the negative log-product
}
