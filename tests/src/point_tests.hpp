#ifndef BOUNCY_SQUARE_TESTS_SRC_POINT_TESTS_HPP
#define BOUNCY_SQUARE_TESTS_SRC_POINT_TESTS_HPP

#include "point.hpp"

#include <gtest/gtest.h>

TEST(PointClassTest, DoubleUninitializedEqualsZero)
{
    shape::Point<double> pt;

    ASSERT_EQ(pt.x, 0);
    ASSERT_EQ(pt.y, 0);
}

TEST(PointClassTest, DoubleHandlesZeroCoords)
{
    shape::Point<double> a;
    shape::Point<double> b;
    shape::Point<double> c(0, 0);

    ASSERT_EQ(a.x, 0);
    ASSERT_EQ(a.y, 0);

    ASSERT_EQ(a + b, c);
    ASSERT_EQ(a - b, c);
    ASSERT_TRUE(a == b);

    ASSERT_EQ(a.subx(b), 0);
    ASSERT_EQ(a.suby(b), 0);
}

TEST(PointClassTest, DoubleHandlesNegativeCoords)
{
    shape::Point<double> a(-5, 2);
    shape::Point<double> b(-10, -1);

    ASSERT_EQ(a.subx(b), 5);
    ASSERT_EQ(a.suby(b), 3);

    ASSERT_EQ(a + b, shape::Point<double>(-15, 1));
    ASSERT_EQ(a - b, shape::Point<double>(5, 3));
}

TEST(PointClassTest, IntUninitializedEqualsZero)
{
    shape::Point<int> pt;

    ASSERT_EQ(pt.x, 0);
    ASSERT_EQ(pt.y, 0);
}

TEST(PointClassTest, IntHandlesZeroCoords)
{
    shape::Point<int> a;
    shape::Point<int> b;
    shape::Point<int> c(0, 0);

    ASSERT_EQ(a.x, 0);
    ASSERT_EQ(a.y, 0);

    ASSERT_EQ(a + b, c);
    ASSERT_EQ(a - b, c);
    ASSERT_TRUE(a == b);

    ASSERT_EQ(a.subx(b), 0);
    ASSERT_EQ(a.suby(b), 0);
}

TEST(PointClassTest, IntHandlesMixedCoords)
{
    shape::Point<int> a(-5, 2);
    shape::Point<int> b(-10, -1);

    ASSERT_EQ(a.subx(b), 5);
    ASSERT_EQ(a.suby(b), 3);

    ASSERT_EQ(a + b, shape::Point<int>(-15, 1));
    ASSERT_EQ(a - b, shape::Point<int>(5, 3));
}

#endif // BOUNCY_SQUARE_TESTS_SRC_POINT_TESTS_HPP