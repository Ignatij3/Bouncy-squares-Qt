#ifndef BOUNCY_SQUARE_LIBS_SHAPE_SHAPE_HPP
#define BOUNCY_SQUARE_LIBS_SHAPE_SHAPE_HPP

#include "vector.hpp"

#include <QColor>
#include <QPointF>
#include <utility>
#include <vector>

namespace shape
{
    enum Movement : bool {
        DYNAMIC = true,
        STATIC  = false
    };

    class Shape {
      private:
        std::pair<bool, Vector*> LiesOnLine(std::vector<Vector*>& sides, const Point& angle) const noexcept;
        std::pair<Vector*, Vector*> FindSidesToReflect(std::vector<Vector*>& shapeSides, std::vector<Vector*>& otherShapeSides, int sideIndex, int otherSideIndex) const noexcept;

      protected:
        bool dynamic;
        std::vector<Vector*> sides;
        std::pair<double, double> direction;

        virtual double LeftX() const    = 0;
        virtual double UpperY() const   = 0;
        virtual double RightX() const   = 0;
        virtual double LowerY() const   = 0;
        virtual void SetSides()         = 0;
        virtual void SetSidesSetAngle() = 0;

      public:
        double angle;
        Point centre;
        QPointF q_centre;
        QColor color = "black";

        virtual std::vector<Vector*> get_sides() const  = 0;
        virtual const int constexpr side_amount() const = 0;
        virtual void move()                             = 0;

        Shape(Movement move, Point coords, double width, double height, double alpha) noexcept;
        Shape() noexcept;

        void set_direction() noexcept;
        void reflect(double otherVectorAngle) noexcept;
        void movement_toggle() noexcept;
        void movement_toggle(Movement move) noexcept;
        std::pair<bool, std::pair<const Vector*, const Vector*>> collide_with(Shape* other) noexcept;
    };
}

#endif // BOUNCY_SQUARE_LIBS_SHAPE_SHAPE_HPP