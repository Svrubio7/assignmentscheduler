cmake_minimum_required(VERSION 3.10)
project(AssignmentScheduler)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for headers
include_directories(include)

# Source files for the main program
set(SRC_FILES
    src/assignmentcreator.cpp
    src/planner.cpp
    src/Classfinal.cpp
    src/displayfunctions.cpp
)

# Test source files
set(TEST_FILES
    test/test_assignmentcreator.cpp
    test/test_planner.cpp
    test/test_displayfunctions.cpp
    test/test_Classfinal.cpp
)

# Find and include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create the test executable
add_executable(runTests ${SRC_FILES} ${TEST_FILES})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Create the main program executable
add_executable(main_program ${SRC_FILES} src/main.cpp)
