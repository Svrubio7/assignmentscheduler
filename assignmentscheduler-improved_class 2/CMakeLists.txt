cmake_minimum_required(VERSION 3.10)
project(AssignmentScheduler)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(include)


set(SRC_FILES
    src/assignmentcreator.cpp
    src/planner.cpp
    src/Classfinal.cpp
    src/displayfunctions.cpp
)


set(TEST_FILES
    test/test_assignmentcreator.cpp
    test/test_planner.cpp
    test/test_displayfunctions.cpp
    test/test_Classfinal.cpp
)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests ${SRC_FILES} ${TEST_FILES})


target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
