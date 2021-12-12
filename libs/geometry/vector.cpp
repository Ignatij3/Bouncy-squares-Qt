
#include "vector.hpp"

#include "float.hpp"

#include <cmath>

shape::Vector::Vector() { }

shape::Vector::Vector(Point point, Point vector) noexcept :
    a(point),
    b(vector)
{
    set_angle();
}

shape::Vector::Vector(double x1, double y1, double x2, double y2) noexcept :
    Vector(Point(x1, y1), Point(x2, y2))
{
    set_angle();
}

shape::Vector::Vector(const Vector& rhs) noexcept
{
    a     = rhs.a;
    b     = rhs.b;
    angle = rhs.angle;
}

double shape::Vector::slope() const noexcept
{
    return (almost_equal(a.x_diff(b), 0, 1)) ? 0 : a.y_diff(b) / a.x_diff(b);
}

bool shape::Vector::lies_between(const Vector& outsideVector) const noexcept
{
    double lowY  = outsideVector.lowest_y();
    double highY = outsideVector.highest_y();
    double lowX  = outsideVector.lowest_x();
    double highX = outsideVector.highest_x();

    bool secondX = (highX > this->b.x || almost_equal(highX, this->b.x, 1)) && (this->b.x > lowX || almost_equal(this->b.x, lowX, 1));
    bool secondY = (highY > this->b.y || almost_equal(highY, this->b.y, 1)) && (this->b.y > lowY || almost_equal(this->b.y, lowY, 1));
    return secondX && secondY;
}

void shape::Vector::set_angle() noexcept
{
    angle = atan2(a.y_diff(b), a.x_diff(b)) * (180 / PI);
    angle = (angle < 0) ? 360 + angle : angle;
}

void shape::Vector::set_vectors(Point point, Point vector) noexcept
{
    a.x = point.x;
    a.y = point.y;
    b.x = point.x + vector.x;
    b.y = point.y + vector.y;
}

void shape::Vector::set_vectors(double x1, double y1, double x2, double y2) noexcept
{
    a.x = x1;
    a.y = y1;
    b.x = x1 + x2;
    b.y = y1 + y2;
}

bool shape::Vector::cross(const Vector& lineb) const noexcept
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

double shape::Vector::magnitude() const noexcept
{
    double x_diff_squared = a.x_diff(b) * a.x_diff(b);
    double y_diff_squared = a.y_diff(b) * a.y_diff(b);

    return sqrt(x_diff_squared + y_diff_squared);
}

// calculates determinant
int shape::Vector::operator^(Vector& rhs) const noexcept
{
    int x1 = b.x_diff(a);
    int y1 = b.y_diff(a);
    int x2 = rhs.b.x_diff(rhs.a);
    int y2 = rhs.b.y_diff(rhs.a);

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