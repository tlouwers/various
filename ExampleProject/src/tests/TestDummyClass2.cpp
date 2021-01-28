#include "gtest/gtest.h"

#include <string>

// Test subject
#include "../ExampleLibrary/DummyClass2.hpp"

// Mock
// ...


namespace {


// Test fixture for DummyClass2
class TEST_DummyClass2 : public ::testing::Test
{
protected:

    TEST_DummyClass2() :
        mSubject()
    {
        // Initialize test matter
    }

    DummyClass2 mSubject;
};


TEST_F(TEST_DummyClass2, simple_division_positive)
{
    constexpr int INP_A = 30;
    constexpr int INP_B = 6;
    constexpr int EXP   = 5;

    EXPECT_EQ(EXP, mSubject.Divide(INP_A, INP_B));
}

TEST_F(TEST_DummyClass2, simple_division_negative)
{
    constexpr int INP_A = -30;
    constexpr int INP_B =   5;
    constexpr int EXP   =  -6;

    EXPECT_EQ(EXP, mSubject.Divide(INP_A, INP_B));
}

TEST_F(TEST_DummyClass2, divide_by_null)
{
    constexpr int INP_A = 6;
    constexpr int INP_B = 0;
    constexpr int EXP   = 0;

    EXPECT_EQ(EXP, mSubject.Divide(INP_A, INP_B));
}


} // namespace
