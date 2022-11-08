#include "engine.h"
#include <cstdio>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 0;
    }
    printf("SDL successfully initialized!\n");

    SDL_Window* win = SDL_CreateWindow("Main Window",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       SCREEN_WIDTH, SCREEN_HEIGTH, 0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_bool done = SDL_FALSE;

    Camera cam = {{0, 0, 0}, {0, 0, 0}, 20};
    Mesh mesh = {{
    //    X   Y   Z 
        {-1, -1, -1}, // 0
        {-1, -1,  1}, // 1
        {-1,  1, -1}, // 2
        {-1,  1,  1}, // 3
        { 1, -1, -1}, // 4
        { 1, -1,  1}, // 5
        { 1,  1, -1}, // 6
        { 1,  1,  1}  // 7
    }, {
        {0, 1},
        {0, 2},
        {0, 4},
        {7, 3},
        {7, 5},
        {7, 6},
        {3, 1},
        {5, 1},
        {6, 4},
        {5, 4},
        {6, 2},
        {3, 2},
    }};
    mesh.scale({10, 10, 10});

    while (!done) 
    {
        SDL_Event event;

        SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(rend);

        render(rend, cam, mesh);
        
        SDL_RenderPresent(rend);

        while (SDL_PollEvent(&event)) 
        {
            switch (event.type)
            {
            case SDL_QUIT:
                done = SDL_TRUE;
                break;
            
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:
                    break;
                
                case SDLK_RIGHT:
                    break;
                
                case SDLK_UP:
                    break;
                
                case SDLK_DOWN:
                    break;

                case SDLK_w:
                    cam.position.z -= 1;
                    break;

                case SDLK_s:
                    cam.position.z += 1;
                    break;

                case SDLK_a:
                    cam.position.x += 1;
                    break;

                case SDLK_d:
                    cam.position.x -= 1;
                    break;
                
                default:
                    break;
                }
                break;

            case SDL_MOUSEMOTION:
                mesh.rotation.x -= event.motion.yrel * 0.001;
                mesh.rotation.y += event.motion.xrel * 0.001;
                break;

            case SDL_MOUSEWHEEL:
                cam.focalLength += event.wheel.y;
                printf("focal length: %f\n", cam.focalLength);
                break;
            
            default:
                break;
            }            
        }
    }

    SDL_Quit();

    return 0;
}
