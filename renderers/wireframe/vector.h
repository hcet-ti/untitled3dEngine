#ifndef VECTOR_H
#define VECTOR_H

class Vector3
{
private:
    /* data */
public:
    Vector3();
    Vector3(float x, float y, float z);
    ~Vector3();
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

Vector3::Vector3(float xCoordinate, float yCoordinate, float zCoordinate)
{
    x = xCoordinate;
    y = yCoordinate;
    z = zCoordinate;
}

Vector3::~Vector3()
{
}

#endif