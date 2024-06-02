add_library(enlarge_matrix enlarge_matrix.cpp)

# Link maximize_product_list with maximize_product
target_link_libraries(enlarge_matrix PRIVATE unique_vector_indices)

# Optionally add an executable for testing purposes
add_executable(enlarge_matrix_example example.cpp)
target_link_libraries(enlarge_matrix_example enlarge_matrix)
