# Locate CUnit library
# This module defines
#  CUNIT_INCLUDE_DIR, where to find CUnit.h, etc.
#  CUNIT_LIBRARIES, the libraries to link against to use CUnit.
#  CUNIT_FOUND, If false, do not try to use CUnit.

find_path(CUNIT_INCLUDE_DIR
  NAMES CUnit/CUnit.h
  PATHS /usr/include /usr/local/include
)

find_library(CUNIT_LIBRARY
  NAMES cunit
  PATHS /usr/lib /usr/local/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CUnit DEFAULT_MSG
  CUNIT_INCLUDE_DIR CUNIT_LIBRARY)

if(CUNIT_FOUND)
  set(CUNIT_LIBRARIES ${CUNIT_LIBRARY})
  set(CUNIT_INCLUDE_DIRS ${CUNIT_INCLUDE_DIR})
endif()

mark_as_advanced(CUNIT_INCLUDE_DIR CUNIT_LIBRARY)
