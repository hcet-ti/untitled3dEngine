#ifndef MESH_H
#define MESH_H

#include "triangle.h"
#include <vector>

class Mesh
{
private:
    /* data */
public:
    Mesh();
    Mesh(std::vector<Vector3> vertices, std::vector<int> edges);
    ~Mesh();
    std::vector<Vector3> vertexTable;
    std::vector<int> edgeTable;
};

Mesh::Mesh(std::vector<Vector3> vertices, std::vector<int> edges)
{
    vertexTable = vertices;
    edgeTable = edges;
}

Mesh::~Mesh()
{
}

#endif