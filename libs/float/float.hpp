#ifndef BOUNCY_SQUARE_LIBS_FLOAT_FLOAT_HPP
#define BOUNCY_SQUARE_LIBS_FLOAT_FLOAT_HPP

#include <cmath>

const double PI = 3.14159265;

template <class T>
inline bool almost_equal(T a, T b, double epsilon)
{
    return std::abs(b - a) <= epsilon;
}

#endif // BOUNCY_SQUARE_LIBS_FLOAT_FLOAT_HPP