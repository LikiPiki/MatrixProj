#include <iostream>
#include <vector>

#include "SDL2/SDL.h"
#include "Shape.h"
#include "Line.h"

using namespace std;

#ifndef CONTROLLER_H
#define CONTROLLER_H

// TODO: delete line from ln
void checkKeys(SDL_Event event, Line *ln) {
    if (event.type == SDL_KEYDOWN) {
      switch(event.key.keysym.sym) {
        case SDLK_DOWN:
        	ln->move(0, 3);
            break;
        case SDLK_UP:
        	ln->move(0, -3);
            break;
        case SDLK_RIGHT:
        	ln->move(3, 0);
            break;
        case SDLK_LEFT:
        	ln->move(-3, 0);
            break;
        case SDLK_z:
        	ln->scale(1.10, 1.10);
        	break;
        case SDLK_x:
        	ln->scale(0.90, 0.90);
        	break;
      	case SDLK_q:
            ln->rotateX(5);
			break;
      	case SDLK_w:
          	ln->rotateX(-5);
          	break;


		  default:break;
	  }
    }
}

void display(SDL_Renderer *renderer, vector<Shape*> shapes) {
	for (int i = 0; i < shapes.size(); i++) {
		shapes[i]->draw(renderer);
	}
}


#endif // CONTROLLER_H
