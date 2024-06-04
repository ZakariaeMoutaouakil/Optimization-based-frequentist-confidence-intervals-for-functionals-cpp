cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

# Include custom cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

# Find NLopt
find_package(NLopt REQUIRED)

# Find GMP
find_package(GMP REQUIRED)

# Add subdirectories
add_subdirectory(utils/discrete_simplex)
add_subdirectory(utils/FactorialList)
add_subdirectory(utils/FilterVectors)
add_subdirectory(utils/MultinomialCoefficient)
add_subdirectory(utils/Multinomial)
add_subdirectory(utils/unique_vectors)
add_subdirectory(utils/unique_vector_indices)
add_subdirectory(utils/enlarge_matrix)
add_subdirectory(utils/sample_space)
add_subdirectory(utils/normalize_vectors)
add_subdirectory(optimization/maximize_product)
add_subdirectory(optimization/maximize_product_list)
add_subdirectory(optimization/maximize_product_grid)
add_subdirectory(optimization/log_likelihood_grid)
add_subdirectory(distribution/find_closest_indices)
add_subdirectory(distribution/quantile_1_minus_alpha)
add_subdirectory(distribution/bin_second_largest_values)
add_subdirectory(distribution/final_filter)

# Create the main executable
add_executable(main main.cpp)

# Link the subpackages to the main executable
target_link_libraries(main discrete_simplex maximize_product FactorialList FilterVectors MultinomialCoefficient Multinomial unique_vectors find_closest_indices quantile_1_minus_alpha bin_second_largest_values maximize_product_list maximize_product_grid log_likelihood_grid final_filter unique_vector_indices enlarge_matrix sample_space normalize_vectors)

# Link GMP libraries to the main executable
target_link_libraries(main ${GMP_LIBRARIES})
target_include_directories(main PRIVATE ${GMP_INCLUDE_DIRS})