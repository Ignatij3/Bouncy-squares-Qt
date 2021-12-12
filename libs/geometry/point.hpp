#ifndef BOUNCY_SQUARE_LIBS_GEOMETRY_POINT_HPP
#define BOUNCY_SQUARE_LIBS_GEOMETRY_POINT_HPP

namespace shape
{
    struct Point {
        double x, y;

        Point() noexcept;
        Point(double x, double y) noexcept;

        double x_diff(const Point& rhs) const noexcept;
        double y_diff(const Point& rhs) const noexcept;
        bool operator==(const Point& rhs) const noexcept;
    };
}

#endif // BOUNCY_SQUARE_LIBS_GEOMETRY_POINT_HPP