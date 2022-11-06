#ifndef ROTATE_H
#define ROTATE_H

#include "vector3.h"
#include <math.h>

Vector3 rotatePointX(Vector3 point, float angle, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    /* formulas: 
    x′ = x × cos(β) − y × sin(β)
    y′ = y × cos(β) + x × sin(β)        */
    float sinAngle = sin(angle);
    float cosAngle = cos(angle);
    Vector3 rotatedPoint = point;

    // subract the origins transformation
    rotatedPoint.x -= origin.x;
    rotatedPoint.y -= origin.y;
    rotatedPoint.z -= origin.z;

    rotatedPoint = {
        rotatedPoint.x,
        rotatedPoint.y * cosAngle - rotatedPoint.z * sinAngle,
        rotatedPoint.z * cosAngle + rotatedPoint.y * sinAngle
    };

    // add the origins transformation
    rotatedPoint.x += origin.x;
    rotatedPoint.y += origin.y;
    rotatedPoint.z += origin.z;

    return rotatedPoint;
}

Vector3 rotatePointY(Vector3 point, float angle, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    /* formulas: 
    x′ = x × cos(β) − y × sin(β)
    y′ = y × cos(β) + x × sin(β)        */
    float sinAngle = sin(angle);
    float cosAngle = cos(angle);
    Vector3 rotatedPoint = point;

    // subract the origins transformation
    rotatedPoint.x -= origin.x;
    rotatedPoint.y -= origin.y;
    rotatedPoint.z -= origin.z;

    rotatedPoint = {
        rotatedPoint.x * cosAngle - rotatedPoint.z * sinAngle,
        rotatedPoint.y,
        rotatedPoint.z * cosAngle + rotatedPoint.x * sinAngle
    };

    // add the origins transformation
    rotatedPoint.x += origin.x;
    rotatedPoint.y += origin.y;
    rotatedPoint.z += origin.z;

    return rotatedPoint;
}

Vector3 rotatePointZ(Vector3 point, float angle, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    /* formulas: 
    x′ = x × cos(β) − y × sin(β)
    y′ = y × cos(β) + x × sin(β)        */
    float sinAngle = sin(angle);
    float cosAngle = cos(angle);
    Vector3 rotatedPoint = point;

    // subract the origins transformation
    rotatedPoint.x -= origin.x;
    rotatedPoint.y -= origin.y;
    rotatedPoint.z -= origin.z;

    rotatedPoint = {
        rotatedPoint.x * cosAngle - rotatedPoint.y * sinAngle,
        rotatedPoint.y * cosAngle + rotatedPoint.x * sinAngle,
        rotatedPoint.z
    };

    // add the origins transformation
    rotatedPoint.x += origin.x;
    rotatedPoint.y += origin.y;
    rotatedPoint.z += origin.z;

    return rotatedPoint;
}

Vector3 rotatePoint(Vector3 point, Vector3 rotation, Vector3 origin = {0.0f, 0.0f, 0.0f})
{
    Vector3 rotatedPoint = rotatePointX(point, rotation.x, origin);
    rotatedPoint = rotatePointY(rotatedPoint, rotation.y, origin);
    rotatedPoint = rotatePointZ(rotatedPoint, rotation.z, origin);

    return rotatedPoint;
}

#endif