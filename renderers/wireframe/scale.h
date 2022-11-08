#ifndef SCALE_H
#define SCALE_H

#include "vector3.h"
#include "move.h"

Vector3 scalePointX(Vector3 point, float scale, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    Vector3 scaledPoint = movePoint(point, -origin);
    scaledPoint.x *= scale;
    return movePoint(scaledPoint, origin);
}

Vector3 scalePointY(Vector3 point, float scale, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    Vector3 scaledPoint = movePoint(point, -origin);
    scaledPoint.y *= scale;
    return movePoint(scaledPoint, origin);
}

Vector3 scalePointZ(Vector3 point, float scale, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    Vector3 scaledPoint = movePoint(point, -origin);
    scaledPoint.z *= scale;
    return movePoint(scaledPoint, origin);
}

Vector3 scalePoint(Vector3 point, Vector3 scale, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    Vector3 scaledPoint = movePoint(point, -origin);
    scaledPoint = scaledPoint * scale;
    return movePoint(scaledPoint, origin);
}

#endif