# The executable, starting point for the unit tests
add_executable(TestRunner TestRunner.cpp)

# Add flags to retrieve test coverage later
add_compile_options(--coverage)

# List of the sources and unit-test files
target_sources(TestRunner
    PRIVATE
        # Unit test files
        TestRunner.cpp
        TestDummyClass.cpp
        TestDummyClass2.cpp
        # Mocks and Fakes
            # ...
        # Test subjects
        ../ExampleProject/DummyClass.cpp
        ../ExampleProject/ExampleLibrary/DummyClass2.cpp
        # Used sources (not part of unit tests)
            # ...
)

# Include the real and Fake source directories
target_include_directories(TestRunner PRIVATE
    ../ExampleProject
    ../ExampleProject/ExampleLibrary
    ./Fake
)

# Link in Google Mock (which also includes Google Test)
target_link_libraries(TestRunner gmock_main)
