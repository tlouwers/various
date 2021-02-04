/*
 * \file    DummyClass2.hpp
 *
 * \class   DummyClass2
 *
 * \brief   Example class to showcase regular class inside library usage in
 *          project.
 */

#ifndef DUMMYCLASS2_HPP_
#define DUMMYCLASS2_HPP_

/******************************************************************************
 * Includes                                                                   *
 *****************************************************************************/
#include <cstdint>


/************************************************************************/
/* Class declaration                                                    */
/************************************************************************/
/**
 * \brief   Dummy2 class.
 */
class DummyClass2
{
public:
    DummyClass2() {}
    virtual ~DummyClass2() {}

    int Divide(int a, int b);
};


#endif  // DUMMYCLASS2_HPP_
