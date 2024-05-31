cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

# Find Eigen
find_package(NLopt REQUIRED)

# Add subdirectories
add_subdirectory(utils/discrete_simplex)
add_subdirectory(optimization/maximize_product)

# Create the main executable
add_executable(main main.cpp)

# Link the subpackages to the main executable
target_link_libraries(main discrete_simplex maximize_product)