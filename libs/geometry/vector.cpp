#include "vector.hpp"

#include "float.hpp"

#include <cmath>

shape::Vector::Vector() { }

shape::Vector::Vector(Point point, Point vector) noexcept :
    a(point),
    b(vector)
{
    setAngle();
}

shape::Vector::Vector(double x1, double y1, double x2, double y2) noexcept :
    Vector(Point(x1, y1), Point(x2, y2))
{
    setAngle();
}

shape::Vector::Vector(const Vector& rhs) noexcept
{
    a     = rhs.a;
    b     = rhs.b;
    angle = rhs.angle;
}

double shape::Vector::Slope() const noexcept
{
    return (AlmostEqual(a.XDiff(b), 0, 1)) ? 0 : a.YDiff(b) / a.XDiff(b);
}

bool shape::Vector::LiesBetween(const Vector& outsideVector) const noexcept
{
    double lowY  = outsideVector.LowestY();
    double highY = outsideVector.HighestY();
    double lowX  = outsideVector.LowestX();
    double highX = outsideVector.HighestX();

    bool secondX = (highX > this->b.x || AlmostEqual(highX, this->b.x, 1)) && (this->b.x > lowX || AlmostEqual(this->b.x, lowX, 1));
    bool secondY = (highY > this->b.y || AlmostEqual(highY, this->b.y, 1)) && (this->b.y > lowY || AlmostEqual(this->b.y, lowY, 1));
    return secondX && secondY;
}

void shape::Vector::setAngle() noexcept
{
    angle = atan2(a.YDiff(b), a.XDiff(b)) * (180 / PI);
    angle = (angle < 0) ? 360 + angle : angle;
}

void shape::Vector::SetVectors(Point point, Point vector) noexcept
{
    a.x = point.x;
    a.y = point.y;
    b.x = point.x + vector.x;
    b.y = point.y + vector.y;
}

void shape::Vector::SetVectors(double x1, double y1, double x2, double y2) noexcept
{
    a.x = x1;
    a.y = y1;
    b.x = x1 + x2;
    b.y = y1 + y2;
}

double shape::Vector::getAngle() const noexcept
{
    return angle;
}

bool shape::Vector::Cross(const Vector& lineb) const noexcept
{
    auto sign = [](int x) -> char { return ((x > 0) ? '+' : ((x < 0) ? '-' : '0')); };
    int cross1, cross2, cross3, cross4;

    Vector ac(a, lineb.a);
    Vector ad(a, lineb.b);
    cross1 = *this ^ ac;
    cross2 = *this ^ ad;

    if (sign(cross1) == sign(cross2))
        return false;

    Vector ca(lineb.a, a);
    Vector cb(lineb.a, b);
    cross3 = lineb ^ ca;
    cross4 = lineb ^ cb;

    if (cross1 == 0 && cross2 == 0 && cross3 == 0 && cross4 == 0) // lies on same line
        return true;

    return !((sign(cross3) == sign(cross4)) || cross1 == 0 || cross2 == 0);
}

double shape::Vector::Magnitude() const noexcept
{
    double x_diff_squared = a.XDiff(b) * a.XDiff(b);
    double y_diff_squared = a.YDiff(b) * a.YDiff(b);

    return sqrt(x_diff_squared + y_diff_squared);
}

double shape::Vector::HighestX() const noexcept
{
    return (a.x > b.x) ? a.x : b.x;
}

double shape::Vector::LowestX() const noexcept
{
    return (a.x < b.x) ? a.x : b.x;
}

double shape::Vector::HighestY() const noexcept
{
    return (a.y > b.y) ? a.y : b.y;
}

double shape::Vector::LowestY() const noexcept
{
    return (a.y < b.y) ? a.y : b.y;
}

// calculates determinant
int shape::Vector::operator^(Vector& rhs) const noexcept
{
    int x1 = b.XDiff(a);
    int y1 = b.YDiff(a);
    int x2 = rhs.b.XDiff(rhs.a);
    int y2 = rhs.b.YDiff(rhs.a);

    return x1 * y2 - x2 * y1;
}

shape::Vector& shape::Vector::operator=(const Vector& rhs) noexcept
{
    a     = rhs.a;
    b     = rhs.b;
    angle = rhs.angle;

    return *this;
}

shape::Vector& shape::Vector::operator=(Vector&& rhs) noexcept
{
    a     = rhs.a;
    b     = rhs.b;
    angle = rhs.angle;

    return *this;
}

bool shape::Vector::operator==(const Vector& rhs) const noexcept
{
    return (a == rhs.a && b == rhs.b);
}