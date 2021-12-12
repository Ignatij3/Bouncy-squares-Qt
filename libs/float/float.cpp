#include <cmath>
bool almost_equal(double a, double b, double epsilon)
{
    return std::abs(b - a) <= epsilon;
}