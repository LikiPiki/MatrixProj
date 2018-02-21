
#include <SDL2/SDL.h>

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
	virtual void draw(SDL_Renderer *renderer) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double sx, double sy) = 0;
	virtual void rotate(double angle) = 0;
};

#endif // SHAPE_H
