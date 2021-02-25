/**
 * \file    SimpleProfiler.hpp
 *
 * \licence None mentioned, ask origional author?
 *
 * \class   SimpleProfiler
 *
 * \brief   Convenience template to be able to quickly measure a duration of a\
 *          specific code section or method.
 *
 * \note    https://github.com/tlouwers/various/tree/master/Snippits/SimpleProfiler
 *
 * \author  Sirn Nguyen Truong (?)
 * \author  Terry Louwers (terry.louwers@fourtress.nl)
 * \version 1.0
 * \date    02-2021
 */

#ifndef SIMPLE_PROFILER_HPP_
#define SIMPLE_PROFILER_HPP_

/************************************************************************/
/* Includes                                                             */
/************************************************************************/
#include <chrono>
#include <iostream>
#include <ratio>
#include <string>


/**
 * \brief   Use a conditional to ensure a steady_clock.
 */
using perf_clock = std::conditional<
    std::chrono::high_resolution_clock::is_steady,
    std::chrono::high_resolution_clock,
    std::chrono::steady_clock
    >::type;


/******************************************************************************
 * Template Class                                                             *
 *****************************************************************************/
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


/**
 * \brief   Stop point, calculates the time between the start of the profiling
 *          section and this method call.
 * \returns Elapsed time, expressed in the given TimeUnit (as number).
 */
template <typename TimeUnit>
TimeUnit SimpleProfiler<TimeUnit>::Elapsed() {
    return std::chrono::duration_cast<TimeUnit>(perf_clock::now() - mStart);
}

/**
 * \brief   Stop point, calculates the time between the start of the profiling
 *          section and this method call.
 * \returns Elapsed time, expressed in the given TimeUnit (as string).
 */
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

/**
 * \brief   Create the duration expression string based upon the chosen TimeUnit.
 * \returns Duration expression string.
 */
template <typename TimeUnit>
void SimpleProfiler<TimeUnit>::PrintElapsed() {
    std::cout << ElapsedStr();
}


/************************************************************************/
/* Private Methods                                                      */
/************************************************************************/
/**
 * \brief   Create the duration expression string based upon the chosen TimeUnit.
 * \returns Duration expression string.
 */
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
