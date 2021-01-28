# Define the minimum CMake version to use
cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

# Define the name and version of the project
project(ExampleProject VERSION 0.0.1)

# Add directories (libraries) - note: must be subdirectory of project
add_subdirectory(ExampleLibrary)

# Define the project source files
set(project_sources main.cpp
                    DummyClass.cpp)

# Specify the executable compiled with the given source files
add_executable(${PROJECT_NAME} ${project_sources})

# Link the library with the project
target_link_libraries(${PROJECT_NAME} ExampleLibrary)


# Enable LinkTimeOptimizations, if requested
link_time_optimization(LINK_TIME_OPTIMIZATION ${PROJECT_NAME})
