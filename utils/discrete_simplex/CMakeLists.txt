add_library(discrete_simplex discrete_simplex.cpp)

# Optionally add an executable for testing purposes
add_executable(discrete_simplex_example example.cpp)
target_link_libraries(discrete_simplex_example discrete_simplex ${GMP_LIBRARIES})
target_include_directories(discrete_simplex_example PRIVATE ${GMP_INCLUDE_DIRS})
