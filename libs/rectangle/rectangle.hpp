#ifndef BOUNCY_SQUARE_LIBS_RECTANGLE_RECTANGLE_HPP
#define BOUNCY_SQUARE_LIBS_RECTANGLE_RECTANGLE_HPP

#include "point.hpp"
#include "shape.hpp"
#include "vector.hpp"

#include <QObject>
#include <QPointF>
#include <QtQml/qqmlregistration.h>
#include <memory>
#include <vector>

namespace shape
{
    class MyRectangle : public QObject, public Shape {
      private:
        Q_OBJECT
        QML_ELEMENT
        Q_PROPERTY(QPointF centre MEMBER q_centre NOTIFY centreChanged)
        Q_PROPERTY(QColor color MEMBER color)
        Q_PROPERTY(double width MEMBER width NOTIFY centreChanged)
        Q_PROPERTY(double height MEMBER height NOTIFY centreChanged)

      protected:
        double width, height;
        const short SIDE_AMOUNT = 4;
        std::vector<Vector*> sides;

        double LeftX() const noexcept override;
        double UpperY() const noexcept override;
        double RightX() const noexcept override;
        double LowerY() const noexcept override;
        void SetSides() noexcept override;
        void SetSidesSetAngle() noexcept override;

      public:
        MyRectangle(Movement move, Point<double> centreCoords, double width, double height, double alpha);
        MyRectangle(Movement move, double centreX, double centreY, double width, double height, double alpha);
        ~MyRectangle();

        MyRectangle static InitFromStdin();
        std::vector<Vector*> get_sides() const noexcept override;
        const int side_amount() const noexcept override;

        void move() noexcept override;
        MyRectangle& operator=(const MyRectangle& rhs) noexcept;

      signals:
        void centreChanged();
    };
}

inline double shape::MyRectangle::LeftX() const noexcept
{
    return centre.x - width;
}

inline double shape::MyRectangle::RightX() const noexcept
{
    return centre.x + width;
}

inline double shape::MyRectangle::UpperY() const noexcept
{
    return centre.y - height;
}

inline double shape::MyRectangle::LowerY() const noexcept
{
    return centre.y + height;
}

inline std::vector<shape::Vector*> shape::MyRectangle::get_sides() const noexcept
{
    return sides;
}

inline const int shape::MyRectangle::side_amount() const noexcept
{
    return SIDE_AMOUNT;
}

#endif // BOUNCY_SQUARE_LIBS_RECTANGLE_RECTANGLE_HPP
