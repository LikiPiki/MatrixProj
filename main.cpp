#include <iostream>

#include <SDL2/SDL.h>
#include <GLUT/glut.h>
#include <vector>

#include "Controller.h"
#include "Line.h"
#include "Shape.h"
#include "Matrix.h"

using namespace std;


int main(int argc, char* argv[]) {

    SDL_Renderer *renderer;
    Line *ln = new Line(100, 150, 250, 300);
    ln->move(10, 10);

    vector<Shape*> shapes;
    shapes.push_back(ln);

    // drawer
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                display(renderer, shapes);
                
                SDL_RenderPresent(renderer);
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                    checkKeys(event, ln);
                }
            }
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}