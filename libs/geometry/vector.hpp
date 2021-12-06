#ifndef BOUNCY_SQUARE_SHAPES_VECTOR_H
#define BOUNCY_SQUARE_SHAPES_VECTOR_H

#include "point.hpp"

// vector defined with starting point and vector going from that point
namespace shape
{
    class Vector {
      private:
        double angle;

      public:
        Point a;
        Point b;

        Vector();
        Vector(Point point, Point vector) noexcept;
        Vector(double x1, double y1, double x2, double y2) noexcept;
        Vector(const Vector& rhs) noexcept;

        void setAngle() noexcept;
        double getAngle() const noexcept;
        double Magnitude() const noexcept;
        double Slope() const noexcept;
        bool LiesBetween(const Vector& outsideVector) const noexcept;
        void SetVectors(Point point, Point vector) noexcept;
        void SetVectors(double x1, double y1, double x2, double y2) noexcept;
        bool Cross(const Vector& lineb) const noexcept;

        double HighestX() const noexcept;
        double LowestX() const noexcept;
        double HighestY() const noexcept;
        double LowestY() const noexcept;

        int operator^(Vector& rhs) const noexcept;
        Vector& operator=(const Vector& rhs) noexcept;
        Vector& operator=(Vector&& rhs) noexcept;
        bool operator==(const Vector& rhs) const noexcept;
    };
}

#endif // BOUNCY_SQUARE_SHAPES_VECTOR_H