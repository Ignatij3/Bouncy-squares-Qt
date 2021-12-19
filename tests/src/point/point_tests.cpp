#include "point_tests.hpp"

#include "point.hpp"

#include <gtest/gtest.h>

TEST(PointClassTest, HandlesZeroCoords)
{
    shape::Point<double> a;
    shape::Point<double> b;
}

TEST(PointClassTest, HandlesNegativeCoords)
{
}

TEST(PointClassTest, HandlesPositiveCoords)
{
}

TEST(PointClassTest, HandlesMixedCoords)
{
}

TEST(PointClassTest, UninitializedEqualsZero)
{
}