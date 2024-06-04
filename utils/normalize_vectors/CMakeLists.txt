add_library(normalize_vectors normalize_vectors.cpp)

# Optionally add an executable for testing purposes
add_executable(normalize_vectors_example example.cpp)
target_link_libraries(normalize_vectors_example normalize_vectors)