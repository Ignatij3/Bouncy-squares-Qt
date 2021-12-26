#ifndef BOUNCY_SQUARE_TESTS_SRC_VECTOR_TESTS_HPP
#define BOUNCY_SQUARE_TESTS_SRC_VECTOR_TESTS_HPP

#include "vector.hpp"

#include <cmath>
#include <gtest/gtest.h>

TEST(VectorClassTest, DefaultConstructorWorks)
{
    shape::Vector vec1;

    ASSERT_EQ(vec1.a.x, 0);
    ASSERT_EQ(vec1.a.y, 0);
    ASSERT_EQ(vec1.b.x, 0);
    ASSERT_EQ(vec1.b.y, 0);
}

TEST(VectorClassTest, ConstructorFromPointsWorks)
{
    shape::Vector vec2(shape::Point<double>(15, 34), shape::Point<double>(1, -1));

    ASSERT_EQ(vec2.a.x, 15);
    ASSERT_EQ(vec2.a.y, 34);
    ASSERT_EQ(vec2.b.x, 1);
    ASSERT_EQ(vec2.b.y, -1);
}

TEST(VectorClassTest, ConstructorFromValuesWorks)
{
    shape::Vector vec3(15, 34, 1, -1);

    ASSERT_EQ(vec3.a.x, 15);
    ASSERT_EQ(vec3.a.y, 34);
    ASSERT_EQ(vec3.b.x, 1);
    ASSERT_EQ(vec3.b.y, -1);
}

TEST(VectorClassTest, ConstructorFromVectorWorks)
{
    shape::Vector vec3(15, 34, 1, -1);
    shape::Vector vec4(vec3);

    ASSERT_EQ(vec4.a.x, 15);
    ASSERT_EQ(vec4.a.y, 34);
    ASSERT_EQ(vec4.b.x, 1);
    ASSERT_EQ(vec4.b.y, -1);
}

TEST(VectorClassTest, GetsLowestHighestCorrectly)
{
    shape::Vector vec(-13, 0, 1, 2);

    ASSERT_NEAR(vec.highest_x(), 1, 1e-5);
    ASSERT_NEAR(vec.lowest_x(), -13, 1e-5);
    ASSERT_NEAR(vec.highest_y(), 2, 1e-5);
    ASSERT_NEAR(vec.lowest_y(), 0, 1e-5);
}

TEST(VectorClassTest, AssignsCorrectly)
{
    shape::Vector vec1;
    shape::Vector vec2(1, 2, 3, 4);

    vec1 = vec2;

    ASSERT_EQ(vec1.a.x, 1);
    ASSERT_EQ(vec1.a.y, 2);
    ASSERT_EQ(vec1.b.x, 3);
    ASSERT_EQ(vec1.b.y, 4);
}

TEST(VectorClassTest, AssignsRValueCorrectly)
{
    shape::Vector vec1;

    vec1 = shape::Vector(1, 2, 3, 4);

    ASSERT_EQ(vec1.a.x, 1);
    ASSERT_EQ(vec1.a.y, 2);
    ASSERT_EQ(vec1.b.x, 3);
    ASSERT_EQ(vec1.b.y, 4);
}

TEST(VectorClassTest, SetsVectorsCorrectly)
{
    shape::Vector vec;

    vec.set_vectors(1, 2, 2, 2);

    ASSERT_EQ(vec.a.x, 1);
    ASSERT_EQ(vec.a.y, 2);
    ASSERT_EQ(vec.b.x, 3);
    ASSERT_EQ(vec.b.y, 4);
}

TEST(VectorClassTest, SetsVectorsFromPointsCorrectly)
{
    shape::Vector vec;

    vec.set_vectors(shape::Point<double>(1, 2), shape::Point<double>(2, 2));

    ASSERT_EQ(vec.a.x, 1);
    ASSERT_EQ(vec.a.y, 2);
    ASSERT_EQ(vec.b.x, 3);
    ASSERT_EQ(vec.b.y, 4);
}

TEST(VectorClassTest, CorrectlyCalculatesDeterminant)
{
    shape::Vector vec1;
    shape::Vector vec2;

    ASSERT_NEAR(vec1 ^ vec2, 0, 1e-5) << "Incorrect determinant with null vectors";

    vec1.set_vectors(0, 0, 1, 1);
    vec2.set_vectors(0, 0, 1, 1);
    ASSERT_NEAR(vec1 ^ vec2, 0, 1e-5) << "Incorrect determinant with same vectors";

    vec1.set_vectors(0, 0, 3, 5);
    vec2.set_vectors(0, 0, 1, -3);
    ASSERT_NEAR(vec1 ^ vec2, -14, 1e-5) << "Incorrect determinant with misc vectors";
}

TEST(VectorClassTest, CorrectlyCalculatesSlope)
{
    shape::Vector vec;

    ASSERT_NEAR(vec.slope(), 0, 1e-5) << "Incorrect slope with null vector";

    vec.set_vectors(0, 0, 1, 1);
    ASSERT_NEAR(vec.slope(), 1, 1e-5) << "Incorrect slope with same vector";

    vec.set_vectors(0, 0, 3, 5);
    ASSERT_NEAR(vec.slope(), 5.0 / 3.0, 1e-5) << "Incorrect slope with misc vector";

    vec.set_vectors(0, 0, 0.000000000001, 5);
    ASSERT_NEAR(vec.slope(), 5.0 / 0.000000000001, 1e-5) << "Incorrect slope with small vector";

    vec.set_vectors(0, 0, 5, 100000000000);
    ASSERT_NEAR(vec.slope(), 100000000000.0 / 5.0, 1e-5) << "Incorrect slope with huge vector";
}

TEST(VectorClassTest, CorrectlyCalculatesMagnitude)
{
    shape::Vector vec;

    ASSERT_NEAR(vec.magnitude(), 0, 1e-5) << "Incorrect magnitude with null vector";

    vec.set_vectors(0, 0, 1, 1);
    ASSERT_NEAR(vec.magnitude(), 1.414213, 1e-5) << "Incorrect magnitude with same vector";

    vec.set_vectors(0, 0, 3, 5);
    ASSERT_NEAR(vec.magnitude(), 5.83095, 1e-5) << "Incorrect magnitude with misc vector";

    vec.set_vectors(0, 0, 0.000000000001, 5);
    ASSERT_NEAR(vec.magnitude(), 5, 1e-5) << "Incorrect magnitude with small vector";

    vec.set_vectors(0, 0, 5, 100000000000);
    ASSERT_NEAR(vec.magnitude(), 1.0000000000000000000012499999999999999999992 * pow(10, 11), 1e-5) << "Incorrect magnitude with huge vector";
}

TEST(VectorClassTest, CorrectlyCalculatesAngle)
{
    shape::Vector vec;

    ASSERT_NEAR(vec.get_angle(), 0, 1e-5) << "Incorrect angle with null vector";

    vec.set_vectors(0, 0, 1, 1);
    ASSERT_NEAR(vec.get_angle(), 45, 1e-5) << "Incorrect angle with same vector";

    vec.set_vectors(0, 0, 3, 5);
    ASSERT_NEAR(vec.get_angle(), 59.04, 1e-2) << "Incorrect angle with misc vector";

    vec.set_vectors(0, 0, 0.000000000001, 5);
    ASSERT_NEAR(vec.get_angle(), 90, 1e-5) << "Incorrect angle with small vector";

    vec.set_vectors(0, 0, 5, 100000000000);
    ASSERT_NEAR(vec.get_angle(), 90, 1e-5) << "Incorrect angle with huge vector";
}

TEST(VectorClassTest, CrossesCorrectly)
{
    shape::Vector vec1;
    shape::Vector vec2;

    ASSERT_FALSE(vec1.cross(vec2)) << "Incorrect crossing signal with null vectors";

    vec1.set_vectors(0, 0, 3, 3);
    vec2.set_vectors(3, 0, -3, 3);
    ASSERT_TRUE(vec1.cross(vec2)) << "Incorrect crossing signal with crossed vectors";

    vec1.set_vectors(2, 2, 3, 5);
    vec2.set_vectors(2.1, 1.9, 3, 5);
    ASSERT_FALSE(vec1.cross(vec2)) << "Incorrect crossing signal with very close vectors";

    vec1.set_vectors(2, 2, 3, 5);
    vec2.set_vectors(2.5, 1.5, 3, 5);
    ASSERT_FALSE(vec1.cross(vec2)) << "Incorrect crossing signal with close vectors";

    vec1.set_vectors(2, 2, 3, 5);
    vec2.set_vectors(2, 2, 7, 5);
    ASSERT_FALSE(vec1.cross(vec2)) << "Incorrect crossing signal with vectors sharing one point";

    vec1.set_vectors(2, 2, 3, 5);
    vec2.set_vectors(2, 2, 3, 5);
    ASSERT_FALSE(vec1.cross(vec2)) << "Incorrect crossing signal with overlaying vectors";

    vec1.set_vectors(2, 2, 3, 5);
    vec2.set_vectors(6, 12, -4, 15);
    ASSERT_FALSE(vec1.cross(vec2)) << "Incorrect crossing signal with not crossed vectors";
}

TEST(VectorClassTest, CheckesIfInsideCorrectly)
{
    shape::Vector vec1;
    shape::Vector vec2;

    ASSERT_TRUE(vec2.lies_inside(vec1)) << "Incorrect lying inside calculations with null vectors";

    vec1.set_vectors(0, 0, 15, 15);
    vec2.set_vectors(5, 5, 1, 1);
    ASSERT_TRUE(vec2.lies_inside(vec1)) << "Incorrect lying inside calculations with vector deeply inside other";

    vec1.set_vectors(0, 0, 15, 15);
    vec2.set_vectors(-5, -5, 1, 1);
    ASSERT_FALSE(vec2.lies_inside(vec1)) << "Incorrect lying inside calculations with vector outside other";

    vec1.set_vectors(0, 0, 15, 15);
    vec2.set_vectors(0, 0, 15, 15);
    ASSERT_TRUE(vec2.lies_inside(vec1)) << "Incorrect lying inside calculations with overlaying vectors";

    vec1.set_vectors(0, 0, 15, 15);
    vec2.set_vectors(5, 0, 10, 0);
    ASSERT_TRUE(vec2.lies_inside(vec1)) << "Incorrect lying inside calculations with vector lying on edge";

    vec1.set_vectors(0, 0, 15, 15);
    vec2.set_vectors(5, 0, 10.5, 0);
    ASSERT_FALSE(vec2.lies_inside(vec1)) << "Incorrect lying inside calculations with vector slightly outside";
}

#endif // BOUNCY_SQUARE_TESTS_SRC_VECTOR_VECTOR_TESTS_HPP