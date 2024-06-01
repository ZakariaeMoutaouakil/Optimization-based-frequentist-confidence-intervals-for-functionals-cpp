add_library(FactorialList FactorialList.cpp)

# Optionally add an executable for testing purposes
add_executable(FactorialList_example example.cpp)
target_link_libraries(FactorialList_example FactorialList ${GMP_LIBRARIES})
target_include_directories(FactorialList_example PRIVATE ${GMP_INCLUDE_DIRS})