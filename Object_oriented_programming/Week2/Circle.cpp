#include "Circle.hpp"

Circle::Circle(int r, Point center) : 
    center (center),
    radius (r)
{
}

bool Circle::IsInside(const Point& p) const
{
    return center.DistanceFrom (p) <= radius;
}
