#ifndef BOUNCY_SQUARE_LIBS_OBJECT_HANDLER_OBJECT_HANDLER_HPP
#define BOUNCY_SQUARE_LIBS_OBJECT_HANDLER_OBJECT_HANDLER_HPP

#include "rectangle.hpp"
#include "shape.hpp"

#include <QColor>
#include <exception>
#include <string>

std::pair<double, double> convert_to_cartesian(double x, double y);
shape::Point convert_to_cartesian(shape::Point a);

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

#endif // BOUNCY_SQUARE_LIBS_OBJECT_HANDLER_OBJECT_HANDLER_HPP