#ifndef MESH_H
#define MESH_H

#include <vector>
#include <algorithm>
#include "scale.h"
#include "move.h"

typedef struct Edge
{
    int p1;
    int p2;
} Edge;

class Mesh
{
private:
    /* data */
public:
    Mesh(std::vector<Vector3> vertices, std::vector<Edge> edges, Vector3 scale, Vector3 location, Vector3 rotationVector);
    ~Mesh();
    std::vector<Vector3> vertexTable;
    std::vector<Edge> edgeTable;
    Vector3 size;
    Vector3 position;
    Vector3 rotation;
    void scale(Vector3 scale);
};

Mesh::Mesh(std::vector<Vector3> vertices = {}, std::vector<Edge> edges = {}, Vector3 scale = {1.0f, 1.0f, 1.0f}, Vector3 location = {0.0f, 0.0f, 0.0f}, Vector3 rotationVector = {0.0f, 0.0f, 0.0f})
{
    vertexTable = vertices;
    edgeTable = edges;
    size = scale;
    position = location;
    rotation = rotationVector;
}

Mesh::~Mesh()
{
}

void Mesh::scale(Vector3 scale)
{
    size = scale;
    
    for (Vector3 &vertex : vertexTable)
    {
        vertex = scalePoint(vertex, scale, position);
    }
    
}

#endif