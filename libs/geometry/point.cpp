#include "point.hpp"

#include "float.hpp"

shape::Point::Point() noexcept :
    x(0), y(0) { }

shape::Point::Point(double x, double y) noexcept :
    x(x), y(y) { }

double shape::Point::XDiff(const Point& rhs) const noexcept
{
    return this->x - rhs.x;
}

double shape::Point::YDiff(const Point& rhs) const noexcept
{
    return this->y - rhs.y;
}

bool shape::Point::operator==(const Point& rhs) const noexcept
{
    return (AlmostEqual(x, rhs.x, 0.4) && AlmostEqual(y, rhs.y, 0.4));
}