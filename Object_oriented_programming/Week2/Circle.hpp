#pragma once

#include "Point.hpp"

class Circle {
public:
    Circle(int r, Point center);

    bool IsInside(const Point& p) const;

private:
    Point center;
    int radius;
};