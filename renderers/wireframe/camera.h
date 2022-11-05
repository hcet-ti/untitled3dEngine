#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"

class Camera
{
private:
    /* data */
public:
    Camera();
    Camera(Vector3 position, Vector3 rotation, float focalLength);
    ~Camera();
    float focalLength;
    Vector3 position;
    Vector3 rotation;
};

Camera::Camera(Vector3 position, Vector3 rotation, float focalLength)
{
    this->position = position;
    this->rotation = rotation;
    this->focalLength = focalLength;
}

Camera::~Camera()
{
}


#endif