#include "shape.hpp"

#include "float.hpp"
#include "object_handler.hpp"

#include <cmath>
#include <vector>

shape::Shape::Shape(Movement move, Point centreCoords, double width, double height, double alpha) noexcept :
    centre(centreCoords),
    angle((alpha < 0) ? 0
                      : ((alpha > 360) ? 360 : alpha)),
    sides(1, nullptr)
{
    double half_width  = width / 2;
    double half_height = height / 2;

    centre.x = (centre.x < half_width) ? half_width
                                       : ((centre.x > (ObjectHandler::window_width - half_width)) ? (ObjectHandler::window_width - half_width) : centre.x);
    centre.y = (centre.y < half_height) ? half_height
                                        : ((centre.y > (ObjectHandler::window_height - half_height)) ? (ObjectHandler::window_height - half_height) : centre.y);

    centre   = convert_to_cartesian(centre);
    q_centre = QPointF(centre.x, centre.y);
    movement_toggle(move);
}

shape::Shape::Shape() noexcept { }

void shape::Shape::reflect(double otherVectorAngle) noexcept
{
    if (dynamic)
    {
        angle = -360 + (2 * otherVectorAngle) - angle;
        angle = (angle < 0) ? 360 + angle : angle;
        set_direction();
    }
}

// setDirection sets shape's direction in degrees, where 0 points right and goes anticlockwise
// if alpha is smaller than 0 or greater than 360, direction is set to 0
void shape::Shape::set_direction() noexcept
{
    direction.first  = cos(angle * PI / 180); // converting degrees to radians
    direction.second = sin(angle * PI / 180); // converting degrees to radians
}

std::pair<bool, std::pair<const shape::Vector*, const shape::Vector*>> shape::Shape::collide_with(Shape* other) noexcept
{
    std::vector<Vector*> sides       = get_sides();
    std::vector<Vector*> other_sides = other->get_sides();

    for (int i = 0; i < side_amount(); ++i)
    {
        for (int j = 0; j < other->side_amount(); ++j)
        {
            if (sides[i]->cross(*other_sides[j]))
            {
                return std::make_pair(true, FindSidesToReflect(sides, other_sides, i, j));
            }
        }
    }

    return std::make_pair(false, std::make_pair(reinterpret_cast<Vector*>(0xffffffffffffffff), nullptr));
}

std::pair<shape::Vector*, shape::Vector*> shape::Shape::FindSidesToReflect(std::vector<Vector*>& shapeSides, std::vector<Vector*>& otherShapeSides, int sideIndex, int otherSideIndex) const noexcept
{
    std::pair<Vector*, Vector*> resulting_vectors; // first vector - side of first shape, second - of second shape

    if (std::pair<bool, Vector*> res = LiesOnLine(shapeSides, otherShapeSides[otherSideIndex]->a); res.first) // check whether and which side does first angle of first collided vector touch
        resulting_vectors.first = res.second;
    else if (std::pair<bool, Vector*> res = LiesOnLine(shapeSides, otherShapeSides[otherSideIndex]->b); res.first) // second angle of first vector
        resulting_vectors.first = res.second;
    else
    {
        resulting_vectors.first = shapeSides[sideIndex];
    }

    if (std::pair<bool, Vector*> res = LiesOnLine(otherShapeSides, shapeSides[sideIndex]->a); res.first) // first angle of second vector
        resulting_vectors.second = res.second;
    else if (std::pair<bool, Vector*> res = LiesOnLine(otherShapeSides, shapeSides[sideIndex]->b); res.first) // second angle of second vector
        resulting_vectors.second = res.second;
    else // side is too big or touched angle
    {
        resulting_vectors.second = otherShapeSides[otherSideIndex];
    }

    return resulting_vectors;
}

std::pair<bool, shape::Vector*> shape::Shape::LiesOnLine(std::vector<Vector*>& sides, const Point& angle) const noexcept
{

    std::size_t sideAmt = sides.size();
    for (int i = 0; i < sideAmt; ++i) // find vector which is touched by angle
    {
        Vector* otherVec = sides[i];
        Vector temp(otherVec->a, angle);
        if (sides[i]->a == angle) // angle touches angle of line
        {
            return std::make_pair(true, otherVec); // vector, perpendicular to incoming angle
        }

        if (almost_equal(otherVec->slope(), temp.slope(), 0.01) && temp.lies_between(*otherVec)) // lies on the same line as the vector does and is between endpoints
        {
            return std::make_pair(true, otherVec);
        }
    }

    return std::make_pair(false, nullptr);
}