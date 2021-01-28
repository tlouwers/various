# SimpleProfiler
Reference: https://github.com/sonnt174/Common/blob/master/time_measure.h

This header file provides an easy means to measure execution time of a method or a scoped block. Output is written to std::cout.

Usage:
```cpp
// For instance in main.cpp
#include "SimpleProfiler.hpp"
#include <iostream>

// Example method which takes some time to execute
int LongMethod(int a) {
    // long stuff
}

void main() {
	int result = 0;
    {
	    // Inside a scoped block, create a profiler instance and specify the desired unit to express the elapsed time in (milliseconds here)
        SimpleProfiler<std::chrono::milliseconds> prof;
        // Execute the method to profile
        result = LongMethod(12);
    }
    // At the end of the scoped section the duration is printed to std::cout
    // Ex: "Time elapsed = 234 milliseconds\n"

	// The result of the long method is printed here
    std::cout << "Long method result: " << result << std::endl;
}
```