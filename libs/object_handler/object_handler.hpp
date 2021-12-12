#ifndef BOUNCY_SQUARE_SCREEN_H
#define BOUNCY_SQUARE_SCREEN_H

#include "rectangle.hpp"
#include "shape.hpp"

#include <QColor>
#include <exception>
#include <string>

std::pair<double, double> ConvertToNormalCoords(double x, double y);
shape::Point ConvertToNormalCoords(shape::Point a);

class ObjectHandler {
  private:
    std::vector<shape::Shape*> objects;
    shape::MyRectangle window_frame;

  public:
    int fps;
    inline static int window_width;
    inline static int window_height;

    ObjectHandler(int fps_);

    void AddObject(shape::Shape* figure);
    void AddObject(shape::Shape* figure, QColor col);
    void SetColor(shape::Shape* figure, QColor col) noexcept;
    void ManageCollisions() const noexcept;
    void MoveAll() noexcept;
    void run() noexcept;
};

#endif // !BOUNCY_SQUARE_SCREEN_H