add_library(discrete_simplex discrete_simplex.cpp)

# Optionally add an executable for testing purposes
add_executable(discrete_simplex_example example.cpp)
target_link_libraries(discrete_simplex_example discrete_simplex)
