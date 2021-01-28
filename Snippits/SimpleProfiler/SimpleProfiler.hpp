/**
 * https://github.com/sonnt174/Common/blob/master/time_measure.h
 *
 * Use as scoped segments:
 * {
 *     SimpleProfiler<std::chrono::nanoseconds> prof;     // Starts time measurement
 *     mMyClass.MyMethodToProfile();
 * }                                                      // Stops measurements when going out-of-scope and print to std::cout.
 * 
 * Note: use 'default' durations: nanoseconds, microseconds, milliseconds, seconds, minutes, hours.
 * If nothing is used, then the default of milliseconds is taken.
 */

#ifndef SIMPLE_PROFILER_HPP_
#define SIMPLE_PROFILER_HPP_


#include <chrono>
#include <iostream>
#include <ratio>
#include <string>


// Use a conditional to ensure a steady_clock.
using perf_clock = std::conditional<
    std::chrono::high_resolution_clock::is_steady,
    std::chrono::high_resolution_clock,
    std::chrono::steady_clock
    >::type;


template <typename TimeUnit = std::chrono::milliseconds>
class SimpleProfiler final {
public:
    SimpleProfiler()  { mStart = perf_clock::now(); }
    ~SimpleProfiler() { PrintElapsed(); }

    TimeUnit Elapsed();
    std::string ElapsedStr();
    void PrintElapsed();

private:
    std::string DurationExpr();
    std::chrono::time_point<perf_clock> mStart;
};


template <typename TimeUnit>
TimeUnit SimpleProfiler<TimeUnit>::Elapsed() {
    return std::chrono::duration_cast<TimeUnit>(perf_clock::now() - mStart);
}

template <typename TimeUnit>
std::string SimpleProfiler<TimeUnit>::ElapsedStr() {
    auto elap = Elapsed();

    std::string str("Time elapsed = ");
    str.append(std::to_string(elap.count()));
    str.append(" ");
    str.append(DurationExpr());
    str.append("\n");

    return str;
}

template <typename TimeUnit>
void SimpleProfiler<TimeUnit>::PrintElapsed() {
    std::cout << ElapsedStr();
}

// Private ------------------------------------------------

template <typename TimeUnit>
std::string SimpleProfiler<TimeUnit>::DurationExpr() {
           if (std::ratio_equal<typename TimeUnit::period, std::nano>::value ) {
      return "nano seconds";
    } else if (std::ratio_equal<typename TimeUnit::period, std::micro>::value) {
      return "micro seconds";
    } else if (std::ratio_equal<typename TimeUnit::period, std::milli>::value) {
      return "milli seconds";
    } else if (std::ratio_equal<typename TimeUnit::period, std::chrono::seconds::period>::value) {
      return "seconds";
    } else if (std::ratio_equal<typename TimeUnit::period, std::chrono::minutes::period>::value) {
      return "minutes";
    } else if (std::ratio_equal<typename TimeUnit::period, std::chrono::hours::period>::value) {
      return "hours";
    } else {
      return "";        // Note: since C++20 also days, weeks, months, years
    }
}


#endif  // SIMPLE_PROFILER_HPP_
