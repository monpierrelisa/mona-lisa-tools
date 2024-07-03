##
# Mona Lisa Tools
##

# Conf
cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 23)
set(MLT_PROJECT_NAME list)

include_directories(/usr/include)
link_directories(/usr/lib)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

project(libmlt-${MLT_PROJECT_NAME} C)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -pedantic-errors")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O3 -march=native")

# Lib
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC "src/*.c")

add_library(libmlt_lib_a STATIC ${SRC})
set_target_properties(libmlt_lib_a PROPERTIES OUTPUT_NAME "mlt-${MLT_PROJECT_NAME}")

add_library(libmlt_lib_so SHARED ${SRC})
set_target_properties(libmlt_lib_so PROPERTIES OUTPUT_NAME "mlt-${MLT_PROJECT_NAME}")

# Test
set(TEST_EXEC_NAME libmlt-${MLT_PROJECT_NAME}.test)
enable_testing()
find_package(CUnit REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/test/include)
file(GLOB SRC_TEST "test/src/*.c")

add_executable(${TEST_EXEC_NAME} ${SRC_TEST})
target_link_libraries(${TEST_EXEC_NAME}  libmlt_lib_a ${CUNIT_LIBRARIES})
add_test(NAME ${TEST_EXEC_NAME}  COMMAND ${TEST_EXEC_NAME})
set_tests_properties(${TEST_EXEC_NAME}  PROPERTIES PASS_REGULAR_EXPRESSION ".*")