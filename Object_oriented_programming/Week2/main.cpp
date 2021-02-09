#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"
#include <vector>

using namespace std;

int main()
{
    Circle circle = Circle ( 1, (Point(0,0)) );

    vector<Point> points;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            points.push_back( Point(i,j) );
        }
    }

    int sum = 0;
    for (unsigned int i = 0; i < points.size(); i++) {
        if ( circle.IsInside(points[i]) ) {
            sum++;
        }
    }

    cout << sum;
    
}