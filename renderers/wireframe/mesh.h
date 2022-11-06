#ifndef MESH_H
#define MESH_H

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
    Mesh(std::vector<Vector3> vertices, std::vector<Edge> edges, Vector3 scale, Vector3 position, Vector3 rotation);
    ~Mesh();
    std::vector<Vector3> vertexTable;
    std::vector<Edge> edgeTable;
    Vector3 scale;
    Vector3 position;
    Vector3 rotation;
};

Mesh::Mesh(std::vector<Vector3> vertices = {}, std::vector<Edge> edges = {}, Vector3 scale = {1, 1, 1}, Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0})
{
    vertexTable = vertices;
    edgeTable = edges;
    this->scale = scale;
    this->position = position;
    this->rotation = rotation;
}

Mesh::~Mesh()
{
}

#endif