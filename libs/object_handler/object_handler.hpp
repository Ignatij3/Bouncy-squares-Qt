#ifndef BOUNCY_SQUARE_LIBS_OBJECT_HANDLER_OBJECT_HANDLER_HPP
#define BOUNCY_SQUARE_LIBS_OBJECT_HANDLER_OBJECT_HANDLER_HPP

#include "rectangle.hpp"
#include "shape.hpp"

#include <QColor>
#include <exception>
#include <initializer_list>
#include <string>

std::pair<double, double> convert_to_cartesian(double x, double y);
shape::Point<double> convert_to_cartesian(shape::Point<double> a);

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
class ObjectHandler {
  private:
    std::vector<shape::Shape*> objects;
    shape::MyRectangle window_frame;

  public:
    int fps;

    ObjectHandler(int fps_);

    void add_object(shape::Shape* figure);
    void add_object(shape::Shape* figure, QColor col);
    void add_object(std::initializer_list<std::pair<shape::Shape*, QColor>> il);
    void set_color(shape::Shape* figure, QColor col) noexcept;
    void manage_collisions() const noexcept;
    void move_all() noexcept;
    void run() noexcept;
};

inline std::pair<double, double> convert_to_cartesian(double x, double y)
{
    return { x, WINDOW_HEIGHT - y };
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

inline void ObjectHandler::add_object(shape::Shape* figure, QColor col)
{
    set_color(figure, col);
    add_object(figure);
}

inline void ObjectHandler::set_color(shape::Shape* figure, QColor col) noexcept
{
    figure->color = col;
}

#endif // BOUNCY_SQUARE_LIBS_OBJECT_HANDLER_OBJECT_HANDLER_HPP