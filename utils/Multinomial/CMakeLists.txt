add_library(Multinomial Multinomial.cpp)

# Optionally add an executable for testing purposes
add_executable(Multinomial_example example.cpp)
target_link_libraries(Multinomial_example Multinomial)