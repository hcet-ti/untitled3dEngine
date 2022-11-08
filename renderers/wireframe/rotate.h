#ifndef ROTATE_H
#define ROTATE_H

#include "vector3.h"
#include <math.h>

Vector3 rotatePointX(Vector3 point, float angle, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    /* formulas: 
    x′ = x × cos(β) − y × sin(β)
    y′ = y × cos(β) + x × sin(β) */
    float sinAngle = sin(angle);
    float cosAngle = cos(angle);

    // subract the origins transformation
    point -= origin;

    // actual rotation
    point.y = point.y * cosAngle - point.z * sinAngle;
    point.z = point.z * cosAngle + point.y * sinAngle;

    // add the origins transformation
    point += origin;

    return point;
}

Vector3 rotatePointY(Vector3 point, float angle, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    /* formulas: 
    x′ = x × cos(β) − y × sin(β)
    y′ = y × cos(β) + x × sin(β) */
    float sinAngle = sin(angle);
    float cosAngle = cos(angle);

    // subract the origins transformation
    point -= origin;

    // actual rotation
    point.x = point.x * cosAngle - point.z * sinAngle;
    point.z = point.z * cosAngle + point.x * sinAngle;

    // add the origins transformation
    point += origin;

    return point;
}

Vector3 rotatePointZ(Vector3 point, float angle, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    /* formulas: 
    x′ = x × cos(β) − y × sin(β)
    y′ = y × cos(β) + x × sin(β) */
    float sinAngle = sin(angle);
    float cosAngle = cos(angle);

    // subract the origins transformation
    point -= origin;

    // actual rotation
    point.x = point.x * cosAngle - point.y * sinAngle;
    point.y = point.y * cosAngle + point.x * sinAngle;

    // add the origins transformation
    point += origin;

    return point;
}

Vector3 rotatePoint(Vector3 point, Vector3 rotation, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    point = rotatePointX(point, rotation.x, origin);
    point = rotatePointY(point, rotation.y, origin);
    point = rotatePointZ(point, rotation.z, origin);

    return point;
}

#endif