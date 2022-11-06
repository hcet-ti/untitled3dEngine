#ifndef RENDER_H
#define RENDER_H

#include "const.h"
#include "camera.h"
#include "mesh.h"
#include "rotate.h"
#include "../../SDL2/include/SDL2/SDL.h"
#include <math.h>
#include <vector>
#include <cstdio>

typedef struct Coordinate2D
{
    int x;
    int y;
} Coordinate2D;

void render(SDL_Renderer *rend, Camera cam, Mesh mesh)
{
    std::vector<Coordinate2D> projectedPoints;

    for (Vector3 vertex : mesh.vertexTable) {
        vertex = rotatePoint(vertex, cam.rotation, cam.position);

        Coordinate2D projectedCoordinates = {
            int(round((cam.focalLength * (vertex.x + cam.position.x + mesh.position.x)) / (cam.focalLength + vertex.z + cam.position.z + mesh.position.z))),
            int(round((cam.focalLength * (vertex.y + cam.position.y + mesh.position.y)) / (cam.focalLength + vertex.z + cam.position.z + mesh.position.z)))
        };
        projectedPoints.push_back(projectedCoordinates);
    }

    for (Edge edge : mesh.edgeTable)
    {
        if (projectedPoints[edge.p1].x >= -(SCREEN_WIDTH / 2) && projectedPoints[edge.p1].x <= SCREEN_WIDTH - SCREEN_WIDTH / 2 &&
            projectedPoints[edge.p1].y >= -(SCREEN_HEIGTH / 2) && projectedPoints[edge.p1].x <= SCREEN_HEIGTH - SCREEN_HEIGTH / 2 &&
            projectedPoints[edge.p2].x >= -(SCREEN_WIDTH / 2) && projectedPoints[edge.p2].x <= SCREEN_WIDTH - SCREEN_WIDTH / 2 &&
            projectedPoints[edge.p2].y >= -(SCREEN_HEIGTH / 2) && projectedPoints[edge.p2].x <= SCREEN_HEIGTH - SCREEN_HEIGTH / 2)
        {
            SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(rend, 
                projectedPoints[edge.p1].x + SCREEN_WIDTH / 2, projectedPoints[edge.p1].y + SCREEN_HEIGTH / 2,
                projectedPoints[edge.p2].x + SCREEN_WIDTH / 2, projectedPoints[edge.p2].y + SCREEN_HEIGTH / 2
            );
        }
    }
    
}

#endif