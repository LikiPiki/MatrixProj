#include <iostream>

#include "Shape.h"
#include "Matrix.h"

using namespace std;

#ifndef LINE_H
#define LINE_H

class Line : public Shape {
public:

	const int N = 2;
	const int M = 3;

	Matrix *mt;

	Line(int x1, int y1, int x2, int y2) {
		mt = new Matrix();
		mt->createM1(2, 3);
		mt->mas[0][0] = x1;
		mt->mas[0][1] = y1;
		mt->mas[1][0] = x2;
		mt->mas[1][1] = y2;
		mt->printMatrix();
	}

	void draw(SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, mt->mas[0][0], mt->mas[0][1], mt->mas[1][0], mt->mas[1][1]); 
	}

	void move(double dx, double dy) {
		Matrix *move = new Matrix();
		move->generateMoveMatrix(dx, dy);
		mt = mt->mul(move);
		mt->printMatrix();
	}

	void scale(double sx, double sy) {
		Matrix *scale = new Matrix();
		scale->generateScaleMatrix(sx, sy);
		mt = mt->mul(scale);
		mt->printMatrix();
	}

};

#endif // LINE_H
