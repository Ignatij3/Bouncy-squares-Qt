#ifndef BOUNCY_SQUARE_LIBS_GEOMETRY_VECTOR_HPP
#define BOUNCY_SQUARE_LIBS_GEOMETRY_VECTOR_HPP

#include "point.hpp"

// vector defined with starting Point<double>and vector going from that point
namespace shape
{
    class Vector {
        double angle;

      public:
        Point<double> a;
        Point<double> b;

        Vector();
        Vector(Point<double> point, Point<double> vector) noexcept;
        Vector(double x1, double y1, double x2, double y2) noexcept;
        Vector(const Vector& rhs) noexcept;

        void set_angle() noexcept;
        double get_angle() const noexcept;
        double magnitude() const noexcept;
        double slope() const noexcept;
        bool lies_between(const Vector& outsideVector) const noexcept;
        void set_vectors(Point<double> point, Point<double> vector) noexcept;
        void set_vectors(double x1, double y1, double x2, double y2) noexcept;
        bool cross(const Vector& lineb) const noexcept;

        double highest_x() const noexcept;
        double lowest_x() const noexcept;
        double highest_y() const noexcept;
        double lowest_y() const noexcept;

        int operator^(Vector& rhs) const noexcept;
        Vector& operator=(const Vector& rhs) noexcept;
        Vector& operator=(Vector&& rhs) noexcept;
        bool operator==(const Vector& rhs) const noexcept;
    };
}

inline double shape::Vector::get_angle() const noexcept
{
    return angle;
}

inline double shape::Vector::highest_x() const noexcept
{
    return (a.x > b.x) ? a.x : b.x;
}

inline double shape::Vector::lowest_x() const noexcept
{
    return (a.x < b.x) ? a.x : b.x;
}

inline double shape::Vector::highest_y() const noexcept
{
    return (a.y > b.y) ? a.y : b.y;
}

inline double shape::Vector::lowest_y() const noexcept
{
    return (a.y < b.y) ? a.y : b.y;
}

inline bool shape::Vector::operator==(const Vector& rhs) const noexcept
{
    return (a == rhs.a && b == rhs.b);
}

#endif // BOUNCY_SQUARE_LIBS_GEOMETRY_VECTOR_HPP