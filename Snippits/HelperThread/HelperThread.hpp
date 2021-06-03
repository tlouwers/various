/**
 * \file    HelperThread.hpp
 *
 * \licence "THE BEER-WARE LICENSE" (Revision 42):
 *          <terry.louwers@fourtress.nl> wrote this file. As long as you retain
 *          this notice you can do whatever you want with this stuff. If we
 *          meet some day, and you think this stuff is worth it, you can buy me
 *          a beer in return.
 *                                                                Terry Louwers
 * \class   HelperThread
 *
 * \brief   Simple thread class to generate an event after a certain time interval.
 *
 * \note    https://github.com/tlouwers/various/tree/master/Snippits/HelperThread
 *
 * \author  T. Louwers <terry.louwers@fourtress.nl>
 * \version 1.0
 * \date    06-2021
 */

#ifndef HELPER_THREAD_HPP_
#define HELPER_THREAD_HPP_

/************************************************************************/
/* Includes                                                             */
/************************************************************************/
#include <atomic>
#include <chrono>
#include <cstdint>
#include <functional>
#include <thread>


/************************************************************************/
/* Class declaration                                                    */
/************************************************************************/
class HelperThread
{
public:
    HelperThread() :
        mShouldRun(false),
        mIntervalInMs(0),
        mHandler(nullptr)
    {}
    virtual ~HelperThread() { Stop(); }

    /**
     * \brief   Set handler to call when interval has passed.
     * \param   handler  Handler to call when interval has passed.
     */
    void SetHandler(const std::function<void()>& handler)
    {
        mHandler = handler;
    }

    /**
     * \brief   Start the tread, call handler after specified interval.
     * \param   intervalInMs    The interval in milliseconds.
     * \returns True if the thread could be started, else false.
     */
    bool Start(uint16_t intervalInMs)
    {
        if (!mShouldRun)
        {
            mShouldRun    = true;	        // Set before creating the thread, as the thread will immediately start running
            mIntervalInMs = intervalInMs;
            mThread       = std::thread(&HelperThread::WorkerMethod, this);
            return true;
        }
        // Else: already running thread
        return false;
    }

    /**
     * \brief   Stops the thread.
     * \returns True if the thread could be stopped, else false.
     */
    bool Stop()
    {
        if (mShouldRun)
        {
            mShouldRun = false;
            if (mThread.joinable())
            {
                mThread.join();
            }
            return true;
        }
        // Else: already stopped thread
        return false;
    }

private:
    std::atomic<bool> mShouldRun;
    uint16_t          mIntervalInMs;
    std::thread       mThread;

    std::function<void()> mHandler;

    /**
     * \brief   Sleep for the specified interval, then call handler (if configured).
     */
    void WorkerMethod()
    {
        while (mShouldRun)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(mIntervalInMs));

            if (mHandler)
            {
                mHandler();
            }
        }
    }
};


#endif  // HELPER_THREAD_HPP_
