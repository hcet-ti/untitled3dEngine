#ifndef MESH_H
#define MESH_H

#include "triangle.h"
#include <vector>

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
    Mesh();
    Mesh(std::vector<Vector3> vertices, std::vector<Edge> edges);
    ~Mesh();
    std::vector<Vector3> vertexTable;
    std::vector<Edge> edgeTable;
};

Mesh::Mesh(std::vector<Vector3> vertices, std::vector<Edge> edges)
{
    vertexTable = vertices;
    edgeTable = edges;
}

Mesh::~Mesh()
{
}

#endif