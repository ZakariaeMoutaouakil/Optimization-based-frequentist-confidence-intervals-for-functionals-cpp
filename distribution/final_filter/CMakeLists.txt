add_library(final_filter final_filter.cpp)

# Link final_filter with maximize_product
target_link_libraries(final_filter PRIVATE maximize_product)

# Optionally add an executable for testing purposes
add_executable(final_filter_example example.cpp)
target_link_libraries(final_filter_example final_filter ${GMP_LIBRARIES})
target_include_directories(final_filter_example PRIVATE ${GMP_INCLUDE_DIRS})
