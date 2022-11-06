#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"

class Camera
{
private:
    /* data */
public:
    Camera(Vector3 position, Vector3 rotation, float focalLength);
    ~Camera();
    float focalLength;
    Vector3 position;
    Vector3 rotation;
};

Camera::Camera(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0}, float focalLength = 1)
{
    this->position = position;
    this->rotation = rotation;
    this->focalLength = focalLength;
}

Camera::~Camera()
{
}


#endif