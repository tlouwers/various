
/************************************************************************/
/* Includes                                                             */
/************************************************************************/
#include "DummyClass.hpp"
#include "ExampleLibrary\DummyClass2.hpp"
#include "SimpleProfiler.hpp"
#include <iostream>


/************************************************************************/
/* Main application entry point                                         */
/************************************************************************/
/**
 * \brief   Main application entry point.
 * \returns Value 0.
 */
int main() {
    DummyClass dummyClass;

    int a = 5;
    int b = 6;
    int result = 0;

    {
        SimpleProfiler<std::chrono::milliseconds> prof;
        result = dummyClass.Multiply(a, b);
    }
    std::cout << "Multiply result: " << result << std::endl;

    // ------------------------------------------------------------------

    DummyClass2 dummyClass2;

    a = 30;
    b = 6;
    result = 0;

    {
        SimpleProfiler<std::chrono::milliseconds> prof;
        result = dummyClass2.Divide(a, b);
    }
    std::cout << "Division result: " << result << std::endl;

    return 0;
}
