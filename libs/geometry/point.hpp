#ifndef BOUNCY_SQUARE_LIBS_GEOMETRY_POINT_HPP
#define BOUNCY_SQUARE_LIBS_GEOMETRY_POINT_HPP

#include "float.hpp"

namespace shape
{
    template <class T>
    struct Point {
        T x, y;

        Point() noexcept;
        Point(T x, T y) noexcept;

        T x_diff(const Point& rhs) const noexcept;
        T y_diff(const Point& rhs) const noexcept;
        bool operator==(const Point& rhs) const noexcept;
        const Point operator-(const Point& rhs) const noexcept;
        const Point operator+(const Point& rhs) const noexcept;
    };
}

template <class T>
shape::Point<T>::Point() noexcept :
    x(0), y(0) { }

template <class T>
shape::Point<T>::Point(T x, T y) noexcept :
    x(x), y(y) { }

template <class T>
inline T shape::Point<T>::x_diff(const Point<T>& rhs) const noexcept
{
    return this->x - rhs.x;
}

template <class T>
inline T shape::Point<T>::y_diff(const Point<T>& rhs) const noexcept
{
    return this->y - rhs.y;
}

template <class T>
inline bool shape::Point<T>::operator==(const Point<T>& rhs) const noexcept
{
    return x == rhs.x && y == rhs.y;
}

template <>
inline bool shape::Point<float>::operator==(const Point<float>& rhs) const noexcept
{
    return almost_equal(x, rhs.x, 0.4) && almost_equal(y, rhs.y, 0.4);
}

template <>
inline bool shape::Point<double>::operator==(const Point<double>& rhs) const noexcept
{
    return almost_equal(x, rhs.x, 0.4) && almost_equal(y, rhs.y, 0.4);
}

template <>
inline bool shape::Point<long double>::operator==(const Point<long double>& rhs) const noexcept
{
    return almost_equal(x, rhs.x, 0.4) && almost_equal(y, rhs.y, 0.4);
}

template <class T>
inline const shape::Point<T> shape::Point<T>::operator-(const Point<T>& rhs) const noexcept
{
    return shape::Point<T>(this->x_diff(rhs), this->y_diff(rhs));
}

template <class T>
inline const shape::Point<T> shape::Point<T>::operator+(const Point<T>& rhs) const noexcept
{
    return shape::Point<T>(this->x + rhs.x, this->y + rhs.y);
}

#endif // BOUNCY_SQUARE_LIBS_GEOMETRY_POINT_HPP