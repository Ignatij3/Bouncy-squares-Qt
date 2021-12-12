#include "rectangle.hpp"

double shape::MyRectangle::LeftX() const noexcept
{
    return centre.x - width;
}

double shape::MyRectangle::RightX() const noexcept
{
    return centre.x + width;
}

double shape::MyRectangle::UpperY() const noexcept
{
    return centre.y - height;
}

double shape::MyRectangle::LowerY() const noexcept
{
    return centre.y + height;
}

void shape::MyRectangle::SetSides() noexcept
{
    double lx = LeftX();
    double rx = RightX();
    double uy = UpperY();
    double ly = LowerY();

    sides[0]->SetVectors(lx, uy, width * 2, 0);  // top side
    sides[1]->SetVectors(rx, uy, 0, height * 2); // right side
    sides[2]->SetVectors(lx, uy, 0, height * 2); // left side
    sides[3]->SetVectors(lx, ly, width * 2, 0);  // bottom side
}

void shape::MyRectangle::SetSidesSetAngle() noexcept
{
    SetSides();
    sides[0]->setAngle();
    sides[1]->setAngle();
    sides[2]->setAngle();
    sides[3]->setAngle();
}

shape::MyRectangle::MyRectangle(Movement move, Point coords, double width, double height, double alpha) :
    Shape(move, coords, width, height, alpha),
    width((width < 0) ? 0 : width / 2),
    height((height < 0) ? 0 : height / 2)
{
    for (int i = 0; i < SIDE_AMOUNT; i++)
        sides.push_back(new Vector);

    SetDirection();
    SetSidesSetAngle();
}

shape::MyRectangle::MyRectangle(Movement move, double centreX, double centreY, double width, double height, double alpha) :
    MyRectangle(move, Point(centreX, centreY), width, height, alpha) { }

shape::MyRectangle::~MyRectangle()
{
    delete sides[0];
    delete sides[1];
    delete sides[2];
    delete sides[3];
}

std::vector<shape::Vector*> shape::MyRectangle::GetSides() const noexcept
{
    return sides;
}

const int shape::MyRectangle::sideAmount() const noexcept
{
    return SIDE_AMOUNT;
}

void shape::MyRectangle::Move() noexcept
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