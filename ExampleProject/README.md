# ExampleProject
A C++ example project useful as base structure. It is based upon GCC (Mingw64), CMake and Google Test. It is intended to be used in Visual Studio Code. Note: for code coverage, install python, then GCov (pip install gcov).

It features:
 - A DummyClass as regular class/code.
 - A DummyClass2 as class/code in a library.
 - Unit tests, provided by Google Test.
 - Code coverage, provided with GCov.
 - A SimpleProfile code showcase, to measure performance of a scoped section, or a single method.
 - LinkTimeOptimization: default enable when building a Release.