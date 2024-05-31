add_library(unique_vectors unique_vectors.cpp)

# Optionally add an executable for testing purposes
add_executable(unique_vectors_example example.cpp)
target_link_libraries(unique_vectors_example unique_vectors)