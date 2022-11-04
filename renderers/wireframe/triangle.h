#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector.h"

class Triangle
{
private:
    /* data */
public:
    Triangle();
    Triangle(Vector3 point1, Vector3 point2, Vector3 point3);
    ~Triangle();
    Vector3 point1;
    Vector3 point2;
    Vector3 point3;
};

Triangle::Triangle(Vector3 pointOne, Vector3 pointTwo, Vector3 pointThree)
{
    point1 = pointOne;
    point2 = pointTwo;
    point3 = pointThree;
}

Triangle::~Triangle()
{
}

#endif