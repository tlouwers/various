
# SimpleProfiler
Convenience template to be able to quickly measure a duration of a specific code section or method.

## Description
This header file provides an easy means to measure execution time of a method or a scoped block. Although other tools may be more accurate, this gives a fair estimate of the duration of a specific item. Output is written to std::cout.

## Requirements
- C++11

## Notes
Code was originally created by <b>Sirn Nguyen Truong</b>, published here: <https://github.com/sonnt174/Common/blob/master/time_measure.h>. I just cleaned up the code a bit, added comments and examples.
Use 'default' durations: nanoseconds, microseconds, milliseconds, seconds, minutes, hours. If nothing is used, then the default of milliseconds is taken.

## Example
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