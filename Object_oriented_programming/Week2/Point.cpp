#include "Point.hpp"
#include <cmath>

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::GetX () const
{
    return x;
}

int Point::GetY () const
{
    return y;
}

double Point::DistanceFrom (const Point& other) const
{
    return std::sqrt (
        (GetX () - other.GetX()) * (GetX () - other.GetX()) + 
        (GetY () - other.GetY()) * (GetY () - other.GetY())
    );
}
std::ostream& operator<< (std::ostream& os, const Point& p)
{
    os << "(" << p.GetX () << ", " << p.GetY () << ")";
    return os;
}