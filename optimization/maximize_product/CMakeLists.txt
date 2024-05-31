add_library(maximize_product maximize_product.cpp)

# Optionally add an executable for testing purposes
add_executable(maximize_product_example example.cpp)
target_link_libraries(maximize_product_example maximize_product)
target_link_libraries(maximize_product PRIVATE nlopt)
