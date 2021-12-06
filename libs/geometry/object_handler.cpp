#include "object_handler.hpp"

#include "point.hpp"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

std::pair<double, double> ConvertToNormalCoords(double x, double y)
{
    return std::make_pair(x, ObjectHandler::window_height - y);
}

shape::Point ConvertToNormalCoords(shape::Point a)
{
    std::pair<double, double> pt = ConvertToNormalCoords(a.x, a.y);
    return shape::Point(pt.first, pt.second);
}

ObjectHandler::ObjectHandler(int fps, int win_width, int win_height) :
    fps(fps)
{
    ObjectHandler::window_width  = win_width;
    ObjectHandler::window_height = win_height;

    window_frame = shape::MyRectangle(shape::Movement::STATIC, window_width / 2, window_height / 2, window_width, window_height, 0);
    objects.insert(objects.begin(), &window_frame);
}

void ObjectHandler::AddObject(shape::Shape* figure)
{
    objects.insert(objects.end(), figure);
}

void ObjectHandler::SetColor(shape::Shape* figure, QColor col) noexcept
{
    figure->color = col;
}

void ObjectHandler::AddObject(shape::Shape* figure, QColor col)
{
    SetColor(figure, col);
    AddObject(figure);
}

// check for collisions between objects
void ObjectHandler::ManageCollisions() const noexcept
{
    if (objects.size() > 1)
        for (int i = 0; i < objects.size(); ++i)
            for (int j = i + 1; j < objects.size(); ++j)
            {
                auto res = objects[i]->CollideWith(objects[j]);
                if (res.first)
                {
                    objects[i]->Reflect(res.second.second->getAngle());
                    objects[j]->Reflect(res.second.first->getAngle());

                    std::pair<bool, std::pair<const shape::Vector*, const shape::Vector*>> new_res;
                    do
                    {
                        new_res = objects[i]->CollideWith(objects[j]);
                        objects[i]->Move();
                        objects[j]->Move();
                    } while (new_res.first && new_res.second.first == res.second.first && new_res.second.second == res.second.second);
                    return;
                }
            }
}

void ObjectHandler::MoveAll() noexcept
{
    for (auto obj = objects.begin(); obj != objects.end(); ++obj)
        (*obj)->Move();
}

void ObjectHandler::run() noexcept
{
    auto next_frame = std::chrono::steady_clock::now();

    while (true)
    {
        next_frame += std::chrono::microseconds(1000000 / fps);
        ManageCollisions();
        MoveAll();
        std::this_thread::sleep_until(next_frame);
    }
}