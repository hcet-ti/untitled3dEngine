#ifndef RAYCAST_H
#define RAYCAST_H

#include "vector3.h"

class Raycast
{
private:
    /* data */
public:
    Raycast(Vector3 location, Vector3 directionVector);
    ~Raycast();
    Vector3 position;
    Vector3 direction;
    void intersects();
};

void Raycast::intersects()
{

}

Raycast::Raycast(Vector3 location, Vector3 directionVector)
{
    position = location;
    direction = directionVector;
}

Raycast::~Raycast()
{
}

#endif