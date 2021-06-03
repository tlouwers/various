
# HelperThread
Simple thread wrapper to generate events after a set interval.

## Description
This header file provides an easy means to start and stop a thread. It generates an event after a given interval.

## Requirements
- C++11

## Example
```cpp
// For instance in main.cpp
#include <iostream>
#include "windows.h"            // For Sleep()
#include "HelperThread.hpp"

// The callback
void MyHandler()
{
    static int i = 1;
    std::cout << "Handler called: " << i++ << std::endl;
}

int main(void)
{
    // Create the HelperThread
    HelperThread expl;

    // Set a handler to call after each interval
    expl.SetHandler( &MyHandler );

    // Show the thread is not running yet
    Sleep(3000);

    // Start the thread, use an interval of 1500 milliseconds
    expl.Start(1500);

    // Show the thread is running, the main application is not.
    // During this time 'MyHandler' will be called 4x
    Sleep(5000);

    // Stop the thread
    expl.Stop();

    // Wait for user input: this prevents closing the application so we can see the output
    char c;
    std::cin >> c;

    return 0;
}
```