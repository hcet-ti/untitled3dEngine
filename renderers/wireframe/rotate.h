#ifndef ROTATE_H
#define ROTATE_H

#include "vector3.h"
#include <math.h>

Vector3 rotatePointX(Vector3 point, float angle, Vector3 origin = {0, 0, 0})
{
    /* formulas: 
    x′ = x × cos(β) − y × sin(β)
    y′ = y × cos(β) + x × sin(β)        */
    float sinAngle = sin(angle);
    float cosAngle = cos(angle);

    // subract the origins transformation
    point.x -= origin.x;
    point.y -= origin.y;
    point.z -= origin.z;

    Vector3 rotatedPoint = {
        point.x,
        point.y * cosAngle - point.z * sinAngle,
        point.z * cosAngle + point.y * sinAngle
    };

    // add the origins transformation
    rotatedPoint.x += origin.x;
    rotatedPoint.y += origin.y;
    rotatedPoint.z += origin.z;

    return rotatedPoint;
}

Vector3 rotatePointY(Vector3 point, float angle, Vector3 origin = {0, 0, 0})
{
    /* formulas: 
    x′ = x × cos(β) − y × sin(β)
    y′ = y × cos(β) + x × sin(β)        */
    float sinAngle = sin(angle);
    float cosAngle = cos(angle);

    // subract the origins transformation
    point.x -= origin.x;
    point.y -= origin.y;
    point.z -= origin.z;

    Vector3 rotatedPoint = {
        point.x * cosAngle - point.z * sinAngle,
        point.y,
        point.z * cosAngle + point.x * sinAngle
    };

    // add the origins transformation
    rotatedPoint.x += origin.x;
    rotatedPoint.y += origin.y;
    rotatedPoint.z += origin.z;

    return rotatedPoint;
}

Vector3 rotatePointZ(Vector3 point, float angle, Vector3 origin = {0, 0, 0})
{
    /* formulas: 
    x′ = x × cos(β) − y × sin(β)
    y′ = y × cos(β) + x × sin(β)        */
    float sinAngle = sin(angle);
    float cosAngle = cos(angle);

    // subract the origins transformation
    point.x -= origin.x;
    point.y -= origin.y;
    point.z -= origin.z;

    Vector3 rotatedPoint = {
        point.x * cosAngle - point.y * sinAngle,
        point.y * cosAngle + point.x * sinAngle,
        point.z
    };

    // add the origins transformation
    rotatedPoint.x += origin.x;
    rotatedPoint.y += origin.y;
    rotatedPoint.z += origin.z;

    return rotatedPoint;
}

Vector3 rotatePoint(Vector3 point, Vector3 rotation, Vector3 origin = {0, 0, 0})
{
    Vector3 rotatedPoint = rotatePointX(point, rotation.x, origin);
    rotatedPoint = rotatePointY(rotatedPoint, rotation.y, origin);
    rotatedPoint = rotatePointZ(rotatedPoint, rotation.z, origin);

    return rotatedPoint;
}

#endif