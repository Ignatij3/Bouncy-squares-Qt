
#include "vector.hpp"

#include "float.hpp"

#include <cmath>

shape::Vector::Vector() { }

shape::Vector::Vector(Point<double> point, Point<double> vector) noexcept :
    a(point), b(vector) { SetAngle(); }

shape::Vector::Vector(double x1, double y1, double x2, double y2) noexcept :
    Vector(Point<double>(x1, y1), Point<double>(x2, y2)) { SetAngle(); }

shape::Vector::Vector(const Vector& rhs) noexcept
{
    a     = rhs.a;
    b     = rhs.b;
    angle = rhs.angle;
}

double shape::Vector::slope() const noexcept
{
    return (almost_equal<double>(a.subx(b), 0, 1e-20)) ? 0 : a.suby(b) / a.subx(b);
}

bool shape::Vector::lies_inside(const Vector& outsideVector) const noexcept
{
    double lowY  = outsideVector.lowest_y();
    double highY = outsideVector.highest_y();
    double lowX  = outsideVector.lowest_x();
    double highX = outsideVector.highest_x();

    bool secondX = (highX > b.x || almost_equal(highX, b.x, .4)) && (b.x > lowX || almost_equal(b.x, lowX, .4));
    bool secondY = (highY > b.y || almost_equal(highY, b.y, .4)) && (b.y > lowY || almost_equal(b.y, lowY, .4));
    return secondX && secondY;
}

void shape::Vector::set_vectors(Point<double> point, Point<double> vector) noexcept
{
    a.x = point.x;
    a.y = point.y;
    b.x = point.x + vector.x;
    b.y = point.y + vector.y;
    SetAngle();
}

void shape::Vector::set_vectors(double x1, double y1, double x2, double y2) noexcept
{
    a.x = x1;
    a.y = y1;
    b.x = x1 + x2;
    b.y = y1 + y2;
    SetAngle();
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
    double x_diff_squared = a.subx(b) * a.subx(b);
    double y_diff_squared = a.suby(b) * a.suby(b);

    return sqrt(x_diff_squared + y_diff_squared);
}

// calculates determinant
int shape::Vector::operator^(Vector& rhs) const noexcept
{
    int x1 = b.subx(a);
    int y1 = b.suby(a);
    int x2 = rhs.b.subx(rhs.a);
    int y2 = rhs.b.suby(rhs.a);

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

void shape::Vector::SetAngle() noexcept
{
    angle = atan2(b.suby(a), b.subx(a)) * (180 / PI);
    angle = (angle < 0) ? 360 + angle : angle;
}