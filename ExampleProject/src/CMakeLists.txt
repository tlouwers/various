# Define the minimum CMake version to use
cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

# Define the toplevel project
project(ExampleProjectAndTests LANGUAGES CXX)

# Define the C++ standard to use
set(CMAKE_CXX_STANDARD 14)              # Be able to compile C++14.
set(CMAKE_CXX_STANDARD_REQUIRED ON)     # That C++14 is required.
set(CMAKE_CXX_EXTENSIONS OFF)           # Do not enable compiler-specific extensions -- this means that GCC will be given -std=c++14 rather than -std=gnu++14.

# Include Google Test
enable_testing()
add_subdirectory(3rd-party/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Unit tests
add_subdirectory(tests)

# Projects
add_subdirectory(ExampleProject)

# The ExampleLibrary is used by ExampleProject - see that CMakeLists.txt
