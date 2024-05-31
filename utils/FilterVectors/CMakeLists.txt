add_library(FilterVectors FilterVectors.cpp)

# Optionally add an executable for testing purposes
add_executable(FilterVectors_example example.cpp)
target_link_libraries(FilterVectors_example FilterVectors)