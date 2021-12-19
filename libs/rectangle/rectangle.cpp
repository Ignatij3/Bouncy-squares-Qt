#include "rectangle.hpp"

void shape::MyRectangle::SetSides() noexcept
{
    double lx = LeftX();
    double rx = RightX();
    double uy = UpperY();
    double ly = LowerY();

    sides[0]->set_vectors(lx, uy, width * 2, 0);  // top side
    sides[1]->set_vectors(rx, uy, 0, height * 2); // right side
    sides[2]->set_vectors(lx, uy, 0, height * 2); // left side
    sides[3]->set_vectors(lx, ly, width * 2, 0);  // bottom side
}

void shape::MyRectangle::SetSidesSetAngle() noexcept
{
    SetSides();
    sides[0]->set_angle();
    sides[1]->set_angle();
    sides[2]->set_angle();
    sides[3]->set_angle();
}

shape::MyRectangle::MyRectangle(Movement move, Point<double> coords, double width, double height, double alpha) :
    Shape(move, coords, width, height, alpha),
    width((width < 0) ? 0 : width / 2),
    height((height < 0) ? 0 : height / 2)
{
    for (int i = 0; i < SIDE_AMOUNT; i++)
        sides.push_back(new Vector);

    set_direction();
    SetSidesSetAngle();
}

shape::MyRectangle::MyRectangle(Movement move, double centreX, double centreY, double width, double height, double alpha) :
    MyRectangle(move, Point<double>(centreX, centreY), width, height, alpha) { }

shape::MyRectangle::~MyRectangle()
{
    delete sides[0];
    delete sides[1];
    delete sides[2];
    delete sides[3];
}

void shape::MyRectangle::move() noexcept
{
    if (dynamic)
    {
        centre.x += direction.first;
        centre.y -= direction.second;
        q_centre.setX(centre.x);
        q_centre.setY(centre.y);
        emit centreChanged();
        SetSides();
    }
}

shape::MyRectangle& shape::MyRectangle::operator=(const MyRectangle& rhs) noexcept
{
    angle   = rhs.angle;
    centre  = rhs.centre;
    color   = rhs.color;
    dynamic = rhs.dynamic;
    height  = rhs.height;
    width   = rhs.width;
    sides   = rhs.sides;

    return *this;
}