add_library(find_closest_indices find_closest_indices.cpp)

# Optionally add an executable for testing purposes
add_executable(find_closest_indices_example example.cpp)
target_link_libraries(find_closest_indices_example find_closest_indices)
