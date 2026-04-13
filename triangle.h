#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

class Triangle {
private:
    Point A, B, C;

    double sideLength(const Point &p1, const Point &p2) const;

public:
    Triangle(Point a, Point b, Point c);

    double areaHeron() const;       
    double areaVector() const;      

    bool isDegenerate() const;      
    string pointPosition(const Point &P) const; 
};

#endif
