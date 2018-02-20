
#include <SDL2/SDL.h>

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
	virtual void draw(SDL_Renderer *renderer) = 0;
};

#endif // SHAPE_H
