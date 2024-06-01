# - Try to find GMP
# Once done, this will define
#  GMP_FOUND - system has GMP
#  GMP_INCLUDE_DIRS - the GMP include directories
#  GMP_LIBRARIES - the libraries needed to use GMP

find_path(GMP_INCLUDE_DIR gmp.h)
find_library(GMP_LIBRARY NAMES gmp libgmp)
find_library(GMPXX_LIBRARY NAMES gmpxx libgmpxx)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GMP DEFAULT_MSG GMP_LIBRARY GMP_INCLUDE_DIR GMPXX_LIBRARY)

if(GMP_FOUND)
    set(GMP_LIBRARIES ${GMP_LIBRARY} ${GMPXX_LIBRARY})
    set(GMP_INCLUDE_DIRS ${GMP_INCLUDE_DIR})
endif()
