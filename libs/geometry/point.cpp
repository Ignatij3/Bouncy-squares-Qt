#include "point.hpp"

shape::Point::Point() noexcept :
    x(0), y(0) { }

shape::Point::Point(double x, double y) noexcept :
    x(x), y(y) { }