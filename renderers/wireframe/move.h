#ifndef MOVE_H
#define MOVE_H

#include "vector3.h"

Vector3 movePoint(Vector3 point, Vector3 moveDistance)
{
    return {
        point.x + moveDistance.x,
        point.y + moveDistance.y,
        point.z + moveDistance.z
    };
}

#endif