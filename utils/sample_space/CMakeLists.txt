add_library(sample_space sample_space.cpp)

# Optionally add an executable for testing purposes
add_executable(sample_space_example example.cpp)
target_link_libraries(sample_space_example sample_space)