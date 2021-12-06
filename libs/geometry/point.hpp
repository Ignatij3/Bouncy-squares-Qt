#ifndef BOUNCY_SQUARE_SHAPES_POINT_H
#define BOUNCY_SQUARE_SHAPES_POINT_H

namespace shape
{
    struct Point {
        double x, y;

        Point() noexcept;
        Point(double x, double y) noexcept;

        double XDiff(const Point& rhs) const noexcept;
        double YDiff(const Point& rhs) const noexcept;
        bool operator==(const Point& rhs) const noexcept;
    };
}

#endif // BOUNCY_SQUARE_SHAPES_POINT_H