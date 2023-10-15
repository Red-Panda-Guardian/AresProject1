/**
 * @file ClockTest.cpp
 * @author linja
 */
#include "gtest/gtest.h"
#include <Clock.h>

/**
 * Test if Clock Object constructs
 */
TEST(ClockTest, Construct)
{
    Clock clock;
}

/**
 * Test if Clock outputs correct time
 */
TEST(ClockTest, TestTimes)
{
    Clock clock;

    // Time at 0 milliseconds
    clock.SetTime(0);
    ASSERT_EQ(clock.GetMinutes(), "0");
    ASSERT_EQ(clock.GetSeconds(), "00");

    // Time at 30 seconds or 30000 milliseconds
    clock.SetTime(30000);
    ASSERT_EQ(clock.GetMinutes(), "0");
    ASSERT_EQ(clock.GetSeconds(), "30");

    // Time at 6 minutes or 360000 milliseconds
    clock.SetTime(360000);
    ASSERT_EQ(clock.GetMinutes(), "6");
    ASSERT_EQ(clock.GetSeconds(), "00");
}