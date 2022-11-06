#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
private:
    /* data */
public:
    Vector3(float xCoordinate, float yCoordinate, float zCoordinate);
    ~Vector3();
    float x;
    float y;
    float z;
};

Vector3::Vector3(float xCoordinate = 0.0f, float yCoordinate = 0.0f, float zCoordinate = 0.0f)
{
    x = xCoordinate;
    y = yCoordinate;
    z = zCoordinate;
}

Vector3::~Vector3()
{
}

#endif