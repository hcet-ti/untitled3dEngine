#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"

class Camera
{
private:
    /* data */
public:
    Camera();
    Camera(Vector3 position, float focalLength);
    ~Camera();
    float focalLength;
    Vector3 position;
};

Camera::Camera(Vector3 position, float focalLength)
{
    this->position = position;
    this->focalLength = focalLength;
}

Camera::~Camera()
{
}


#endif