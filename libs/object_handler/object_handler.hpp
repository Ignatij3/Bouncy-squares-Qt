#ifndef BOUNCY_SQUARE_LIBS_OBJECT_HANDLER_OBJECT_HANDLER_HPP
#define BOUNCY_SQUARE_LIBS_OBJECT_HANDLER_OBJECT_HANDLER_HPP

#include "rectangle.hpp"
#include "shape.hpp"

#include <QColor>
#include <exception>
#include <string>

std::pair<double, double> convert_to_cartesian(double x, double y);
shape::Point<double> convert_to_cartesian(shape::Point<double> a);

class ObjectHandler {
  private:
    std::vector<shape::Shape*> objects;
    shape::MyRectangle window_frame;

  public:
    int fps;
    inline static int window_width;
    inline static int window_height;

    ObjectHandler(int fps_);

    void add_object(shape::Shape* figure);
    void add_object(shape::Shape* figure, QColor col);
    void set_color(shape::Shape* figure, QColor col) noexcept;
    void manage_collisions() const noexcept;
    void move_all() noexcept;
    void run() noexcept;
};

inline std::pair<double, double> convert_to_cartesian(double x, double y)
{
    return std::make_pair(x, ObjectHandler::window_height - y);
}

inline shape::Point<double> convert_to_cartesian(shape::Point<double> a)
{
    std::pair<double, double> pt = convert_to_cartesian(a.x, a.y);
    return shape::Point<double>(pt.first, pt.second);
}

inline void ObjectHandler::add_object(shape::Shape* figure)
{
    objects.insert(objects.end(), figure);
}

inline void ObjectHandler::set_color(shape::Shape* figure, QColor col) noexcept
{
    figure->color = col;
}

inline void ObjectHandler::add_object(shape::Shape* figure, QColor col)
{
    set_color(figure, col);
    add_object(figure);
}

#endif // BOUNCY_SQUARE_LIBS_OBJECT_HANDLER_OBJECT_HANDLER_HPP