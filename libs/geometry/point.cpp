#include "point.hpp"

#include "float.hpp"

shape::Point::Point() noexcept :
    x(0), y(0) { }

shape::Point::Point(double x, double y) noexcept :
    x(x), y(y) { }

double shape::Point::x_diff(const Point& rhs) const noexcept
{
    return this->x - rhs.x;
}

double shape::Point::y_diff(const Point& rhs) const noexcept
{
    return this->y - rhs.y;
}

bool shape::Point::operator==(const Point& rhs) const noexcept
{
    return (almost_equal(x, rhs.x, 0.4) && almost_equal(y, rhs.y, 0.4));
}