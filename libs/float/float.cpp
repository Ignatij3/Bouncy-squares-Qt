#include <cmath>
bool AlmostEqual(double a, double b, double epsilon)
{
    return std::abs(b - a) <= epsilon;
}