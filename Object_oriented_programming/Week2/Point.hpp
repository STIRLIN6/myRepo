#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point {
public:
    Point (int x, int y);

    int GetX () const;
    int GetY () const;

    double DistanceFrom (const Point& other) const;

private:
    int x;
    int y;
};

std::ostream& operator<< (std::ostream& os, const Point& p);

#endif