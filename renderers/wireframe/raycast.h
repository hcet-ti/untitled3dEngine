#ifndef RAYCAST_H
#define RAYCAST_H

#include "vector.h"

class Raycast
{
private:
    /* data */
public:
    Raycast(Vector3 startPoint, Vector3 endPoint);
    ~Raycast();
    void intersects();
};

void Raycast::intersects()
{

}

Raycast::Raycast(Vector3 startPoint, Vector3 endPoint)
{
}

Raycast::~Raycast()
{
}

#endif