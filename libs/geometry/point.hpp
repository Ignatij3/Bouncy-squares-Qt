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

        T subx(const Point& rhs) const noexcept;
        T suby(const Point& rhs) const noexcept;
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
inline T shape::Point<T>::subx(const Point<T>& rhs) const noexcept
{
    return x - rhs.x;
}

template <class T>
inline T shape::Point<T>::suby(const Point<T>& rhs) const noexcept
{
    return y - rhs.y;
}

template <class T>
inline bool shape::Point<T>::operator==(const Point<T>& rhs) const noexcept
{
    return almost_equal<T>(x, rhs.x, 0.4) && almost_equal<T>(y, rhs.y, 0.4);
}

template <>
inline bool shape::Point<short>::operator==(const Point<short>& rhs) const noexcept
{
    return x == rhs.x && y == rhs.y;
}

template <>
inline bool shape::Point<int>::operator==(const Point<int>& rhs) const noexcept
{
    return x == rhs.x && y == rhs.y;
}

template <>
inline bool shape::Point<long>::operator==(const Point<long>& rhs) const noexcept
{
    return x == rhs.x && y == rhs.y;
}

template <>
inline bool shape::Point<long long>::operator==(const Point<long long>& rhs) const noexcept
{
    return x == rhs.x && y == rhs.y;
}

template <class T>
inline const shape::Point<T> shape::Point<T>::operator-(const Point<T>& rhs) const noexcept
{
    return shape::Point<T>(subx(rhs), suby(rhs));
}

template <class T>
inline const shape::Point<T> shape::Point<T>::operator+(const Point<T>& rhs) const noexcept
{
    return shape::Point<T>(x + rhs.x, y + rhs.y);
}

#endif // BOUNCY_SQUARE_LIBS_GEOMETRY_POINT_HPP