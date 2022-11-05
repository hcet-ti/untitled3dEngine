#ifndef RENDER_H
#define RENDER_H

#include "const.h"
#include "camera.h"
#include "mesh.h"
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
        Coordinate2D projectedCoordinates = {
            int(round((cam.focalLength * (vertex.x + cam.position.x)) / (cam.focalLength + vertex.z + cam.position.z))),
            int(round((cam.focalLength * (vertex.y + cam.position.y)) / (cam.focalLength + vertex.z + cam.position.z)))
        };
        printf("projected point %lld: \nx: %d\ny: %d\n", projectedPoints.size(), projectedCoordinates.x, projectedCoordinates.y);
        projectedPoints.push_back(projectedCoordinates);
    }

    for (Edge edge : mesh.edgeTable)
    {
        if (projectedPoints[edge.p1].x >= -(SCREEN_WIDTH / 2) && projectedPoints[edge.p1].x <= SCREEN_WIDTH - SCREEN_WIDTH / 2 &&
            projectedPoints[edge.p1].y >= -(SCREEN_HEIGTH / 2) && projectedPoints[edge.p1].x <= SCREEN_HEIGTH - SCREEN_HEIGTH / 2 &&
            projectedPoints[edge.p2].x >= -(SCREEN_WIDTH / 2) && projectedPoints[edge.p2].x <= SCREEN_WIDTH - SCREEN_WIDTH / 2 &&
            projectedPoints[edge.p2].y >= -(SCREEN_HEIGTH / 2) && projectedPoints[edge.p2].x <= SCREEN_HEIGTH - SCREEN_HEIGTH / 2)
        {
            printf("drawing line between p%d (%5d, %5d) and p%d (%5d, %5d)\n", edge.p1, projectedPoints[edge.p1].x, projectedPoints[edge.p1].y, edge.p2, projectedPoints[edge.p2].x, projectedPoints[edge.p2].y);
            SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(rend, 
                projectedPoints[edge.p1].x + SCREEN_WIDTH / 2, projectedPoints[edge.p1].y + SCREEN_HEIGTH / 2,
                projectedPoints[edge.p2].x + SCREEN_WIDTH / 2, projectedPoints[edge.p2].y + SCREEN_HEIGTH / 2
            );
        }
    }
    
}

#endif