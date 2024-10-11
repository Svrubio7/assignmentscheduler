cmake_minimum_required(VERSION 3.10)
project(AssignmentScheduler)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for headers
include_directories(include)

# Add source files from the src directory
set(SRC_FILES
    src/assignmentcreator.cpp
    src/planner.cpp
    src/Classfinal.cpp
    src/displayfunctions.cpp
)

# Add test files from the test directory
set(TEST_FILES
    test/test_assignmentcreator.cpp
    test/test_planner.cpp
    test/test_displayfunctions.cpp
    test/test_Classfinal.cpp
)

# Find and include GoogleTest (assuming it's installed)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create the executable for running tests
add_executable(runTests ${SRC_FILES} ${TEST_FILES})

# Link the GoogleTest library with your tests
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
