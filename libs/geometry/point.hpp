#ifndef BOUNCY_SQUARE_LIBS_GEOMETRY_POINT_HPP
#define BOUNCY_SQUARE_LIBS_GEOMETRY_POINT_HPP

#include "float.hpp"
   
namespace shape
{
    struct Point {
        double x, y;

        Point() noexcept;
        Point(double x, double y) noexcept;

        double x_diff(const Point& rhs) const noexcept;
        double y_diff(const Point& rhs) const noexcept;
        bool operator==(const Point& rhs) const noexcept;
        const Point operator-(const Point& rhs) const noexcept;
        const Point operator+(const Point& rhs) const noexcept;
    };
}

inline double shape::Point::x_diff(const Point& rhs) const noexcept
{
    return this->x - rhs.x;
}

inline double shape::Point::y_diff(const Point& rhs) const noexcept
{
    return this->y - rhs.y;
}

inline bool shape::Point::operator==(const Point& rhs) const noexcept
{
    return almost_equal(x, rhs.x, 0.4) && almost_equal(y, rhs.y, 0.4);
}

inline const shape::Point shape::Point::operator-(const Point& rhs) const noexcept
{
    return shape::Point(this->x_diff(rhs), this->y_diff(rhs));
}

inline const shape::Point shape::Point::operator+(const Point& rhs) const noexcept
{
    return shape::Point(this->x + rhs.x, this->y + rhs.y);
}

#endif // BOUNCY_SQUARE_LIBS_GEOMETRY_POINT_HPP