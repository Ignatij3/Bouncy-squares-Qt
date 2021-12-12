#include "object_handler.hpp"

#include "point.hpp"

#include <chrono>
#include <string>
#include <thread>
#include <vector>

ObjectHandler::ObjectHandler(int fps) :
    window_frame(shape::Movement::STATIC, ObjectHandler::window_width / 2, ObjectHandler::window_height / 2, ObjectHandler::window_width, ObjectHandler::window_height, 0),
    fps(fps)
{
    objects.insert(objects.begin(), &window_frame);
}

// check for collisions between objects
void ObjectHandler::manage_collisions() const noexcept
{
    if (objects.size() > 1)
        for (int i = 0; i < objects.size(); ++i)
            for (int j = i + 1; j < objects.size(); ++j)
            {
                auto res = objects[i]->collide_with(objects[j]);
                if (res.first)
                {
                    objects[i]->reflect(res.second.second->get_angle());
                    objects[j]->reflect(res.second.first->get_angle());

                    std::pair<bool, std::pair<const shape::Vector*, const shape::Vector*>> new_res;
                    do
                    {
                        new_res = objects[i]->collide_with(objects[j]);
                        objects[i]->move();
                        objects[j]->move();
                    } while (new_res.first && new_res.second.first == res.second.first && new_res.second.second == res.second.second);
                    return;
                }
            }
}

void ObjectHandler::move_all() noexcept
{
    for (auto obj = objects.begin(); obj != objects.end(); ++obj)
        (*obj)->move();
}

void ObjectHandler::run() noexcept
{
    auto next_frame = std::chrono::steady_clock::now();

    while (true)
    {
        next_frame += std::chrono::microseconds(1000000 / fps);
        manage_collisions();
        move_all();
        std::this_thread::sleep_until(next_frame);
    }
}