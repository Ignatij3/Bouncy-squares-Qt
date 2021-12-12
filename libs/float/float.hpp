#ifndef BOUNCY_SQUARE_LIBS_FLOAT_FLOAT_HPP
#define BOUNCY_SQUARE_LIBS_FLOAT_FLOAT_HPP

#include <cmath>

const double PI = 3.14159265;
inline bool almost_equal(double a, double b, double epsilon)
{
    return std::abs(b - a) <= epsilon;
}

#endif // BOUNCY_SQUARE_LIBS_FLOAT_FLOAT_HPP