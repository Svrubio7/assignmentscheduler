# Assignment Scheduler Project

## Introduction

The C++ project **Assignment Scheduler** was created to help in the planning and management of assignments for use in professional or academic contexts. It has tools for organizing, displaying, and manipulating different assignments. Unit tests are included to make sure the code is operating as intended.

The project is organized with a clear division of source code, headers, and tests in line with best standards for software engineering. It makes use of CMake as the build system and GoogleTest as the testing framework.

## Repository Layout

The project is organized into the following directories:
```bash
AssignmentScheduler/
├── assignmentscheduler-improved_class/ 
│   ├── .vscode/
│   │   └── settings.json
│   ├── Data/ #User data files
│   │   ├── Ron.json
│   │   ├── Trinidad.json
│   │   └──  Shahaf.jason
├── include/ # Header files
│   ├── assignmentcreator.hpp
│   ├── planner.hpp
│   ├── Assignment.hpp
│   ├── json.hpp
│   └── displayfunctions.hpp
├── src/    # Source files
│   ├── assignmentcreator.cpp
│   ├── planner.cpp
│   ├── main.cpp
│   ├── Classfinal.cpp
│   └── displayfunctions.cpp
├── test/   # Test files using GoogleTest framework
│   ├── test_assignmentcreator.cpp
│   ├── test_planner.cpp
│   ├── test_displayfunctions.cpp
│   └── test_Classfinal.cpp
├── build/  # Generated build files 
├── CMakeLists.txt     # CMake configuration file
└── README.md          # Project documentation 
```

## Installation

To build and test the project, you'll need the following installed on your system:

- **CMake** (version 3.10 or higher)
- **GCC** or another C++ compiler that supports C++17 or later
- **GoogleTest** library (GTest)

### Steps to Build and Run Tests

1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/AssignmentScheduler.git
    cd AssignmentScheduler
    ```

2. Create a build directory and navigate to it:
    ```bash
    mkdir build
    cd build
    ```

3. Run CMake to configure the build system:
    ```bash
    cmake ..
    ```

4. Compile the project:
    ```bash
    make
    ```

5. Run the tests:
    ```bash
    ./runTests
    ```

## Explanation of Key Files

### `CMakeLists.txt`
This file specifies the CMake build system for the project. It includes all source files, sets the C++ standard to C++17, and indicates the minimum version of CMake that must be used. Additionally, it connects the test executable to the GoogleTest library.

### `src/`
This folder contains the core implementation files:
- `assignmentcreator.cpp`: Implements methods for creating and managing assignments.
- `planner.cpp`: Contains our algorithem for planning and organizing assignments.
- `Classfinal.cpp`: Encapsulate functionality for creating, managing, and organizing assignments within the Assignment Scheduler system.
- `displayfunctions.cpp`: Handles output & visualization of the assignment data.

### `include/`
This folder holds the header files for the source code. Each `.cpp` file has a matching `.h` file that declares the necessary classes and functions.

### `test/`
This folder includes unit tests written using the GoogleTest framework. Each test file corresponds to a source file in the `src/` folder and tests its functionality:
- `test_assignmentcreator.cpp`: Tests the `assignmentcreator` functionality.
- `test_planner.cpp`: Verifies the behavior of the `planner` logic.
- `test_displayfunctions.cpp`: Ensures the `displayfunctions` output is correct.
- `test_Classfinal.cpp`: Tests the finalizing operations in `Classfinal`.

## Future Work

The project can be expanded with more features or improvements, such as:
- Enhancing the planner to support more complex scheduling algorithms.
- Adding more unit tests to improve code coverage.
- Introducing a graphical user interface (GUI) for easier interaction.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.
