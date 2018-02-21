#include <iostream>

#include <SDL2/SDL.h>
#include <GLUT/glut.h>
#include <vector>

#include "Controller.h"
#include "Line.h"
#include "BLine.h"
#include "Shape.h"
#include "Matrix.h"

using namespace std;


int main(int argc, char* argv[]) {

    SDL_Renderer *renderer;
    auto *controller = new Controller();

    auto *ln = new Line(300, 400, 500, 140);
    auto *bl = new BLine(10, 10, 300, 300);

    controller->push(ln);
    controller->push(bl);

    // drawer
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = nullptr;
        renderer = nullptr;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            while (!done) {
                SDL_Event event{};

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                controller->display(renderer);
                
                SDL_RenderPresent(renderer);
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                    controller->checkKeys(event);
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