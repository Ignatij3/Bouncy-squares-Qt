#ifndef BOUNCY_SQUARE_SHAPES_RECTANGLE_H
#define BOUNCY_SQUARE_SHAPES_RECTANGLE_H

#include "point.hpp"
#include "shape.hpp"
#include "vector.hpp"

#include <QObject>
#include <QPointF>
#include <QtQml/qqmlregistration.h>
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
        MyRectangle(Movement move, Point centreCoords, double width, double height, double alpha);
        MyRectangle(Movement move, double centreX, double centreY, double width, double height, double alpha);
        MyRectangle() noexcept;
        ~MyRectangle();

        MyRectangle static InitFromStdin();
        std::vector<Vector*> GetSides() const noexcept override;
        const int sideAmount() const noexcept override;

        void Move() noexcept override;
        MyRectangle& operator=(const MyRectangle& rhs) noexcept;

      signals:
        void centreChanged();
    };
}

#endif // BOUNCY_SQUARE_SHAPES_RECTANGLE_H
