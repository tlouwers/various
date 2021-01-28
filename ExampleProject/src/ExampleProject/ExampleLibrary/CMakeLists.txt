# Define the minimum CMake version to use
cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

# Define the name and version of the project
project(ExampleLibrary VERSION 0.0.1)

# Define the project source files
set(project_sources DummyClass2.cpp)

# Define the project include files
set(project_includes DummyClass2.hpp)

# Specify the library compiled with the given source files
add_library(${PROJECT_NAME} STATIC ${project_sources})      # Static library
#add_library(${PROJECT_NAME} SHARED ${project_sources})     # Shared library

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${project_includes} DESTINATION include)


# Enable LinkTimeOptimizations, if requested
link_time_optimization(LINK_TIME_OPTIMIZATION ${PROJECT_NAME})
