/*
main function for a wireframe 3d renderer
*/

#include "engine.h"
#include <SDL.h>

int main(int argc, char const *argv[])
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
                                       480, 360, 0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_bool done = SDL_FALSE;

    Camera cam = {{0, 0, 0}, 1};
    Mesh mesh = {};

    while (!done) 
    {
        SDL_Event event;

        SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(rend);

        render(cam, mesh);


        /*SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(rend, 320, 200, 300, 240);
        SDL_RenderDrawLine(rend, 300, 240, 340, 240);
        SDL_RenderDrawLine(rend, 340, 240, 320, 200);*/
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
                    camera.rotation.y -= 0.1;
                    break;
                
                case SDLK_RIGHT:
                    camera.rotation.y += 0.1;
                    break;
                
                case SDLK_UP:
                    camera.rotation.x += 0.1;
                    break;
                
                case SDLK_DOWN:
                    camera.rotation.x -= 0.1;
                    break;

                case SDLK_w:
                    triangle1.p1.x -= .5;
                    break;

                case SDLK_s:
                    triangle1.p1.x += .5;
                    break;
                
                default:
                    break;
                }
                break;

            case SDL_MOUSEMOTION:
                camera.rotation.x -= event.motion.yrel * 0.001;
                camera.rotation.y += event.motion.xrel * 0.001;
                break;

            case SDL_MOUSEWHEEL:
                camera.focalLength += event.wheel.y;
                break;
            
            default:
                break;
            }            
        }
    }

    SDL_Quit();

    return 0;
}
