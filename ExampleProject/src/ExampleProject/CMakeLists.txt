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


# If user indicates LinkTimeOptimizations should be used
if( LINK_TIME_OPTIMIZATION )
    # Check if the compiler supports it
    include(CheckIPOSupported)
    check_ipo_supported(RESULT lto_supported OUTPUT error)

    # If it is supported, enable it
    if( lto_supported )
        message(STATUS "IPO / LTO enabled for " ${PROJECT_NAME})
        set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    else()
        message(STATUS "IPO / LTO not supported: <${error}>")
    endif()
endif()
