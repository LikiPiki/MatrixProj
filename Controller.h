#include <iostream>
#include <vector>

#include "SDL2/SDL.h"
#include "Shape.h"
#include "Line.h"

using namespace std;

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
public:

	Controller() {
        selected = 1;
	}

    void push(Shape *sh) {
		shapes.push_back(sh);
	}

	void checkKeys(SDL_Event event) {
		if (event.type == SDL_KEYDOWN) {
			switch(event.key.keysym.sym) {
				case SDLK_0:
                    select(0);
					break;
				case SDLK_1:
					select(1);
					break;
				case SDLK_2:
					select(2);
					break;
				case SDLK_DOWN:
					shapes[selected]->move(0, 3);
					break;
				case SDLK_UP:
					shapes[selected]->move(0, -3);
					break;
				case SDLK_RIGHT:
					shapes[selected]->move(3, 0);
					break;
				case SDLK_LEFT:
					shapes[selected]->move(-3, 0);
					break;
				case SDLK_z:
					shapes[selected]->scale(1.10, 1.10);
					break;
				case SDLK_x:
					shapes[selected]->scale(0.90, 0.90);
					break;
				case SDLK_q:
					shapes[selected]->rotate(5);
					break;
				case SDLK_w:
					shapes[selected]->rotate(-5);
					break;
				default:break;
			}
		}
	}

	void display(SDL_Renderer *renderer) {
		for (int i = 0; i < shapes.size(); i++) {
			shapes[i]->draw(renderer);
		}
	}

private:

	int selected;
	vector<Shape*> shapes;

	void select(int number) {
        if ((number >= 0) && (number < shapes.size())) {
			selected = number;
		}
	}

};




#endif // CONTROLLER_H
