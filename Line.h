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


	void draw(SDL_Renderer *renderer) override {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer,
                           ceil(mt->mas[0][0]), ceil(mt->mas[0][1]),
                           ceil(mt->mas[1][0]), ceil(mt->mas[1][1])
        );
	}

	void move(double dx, double dy) override{
		auto *move = new Matrix();
		move->generateMoveMatrix(dx, dy);
		mt = mt->mul(move);
		mt->printMatrix();
	}

	void scale(double sx, double sy) override {
		auto *scale = new Matrix();
		scale->generateScaleMatrix(sx, sy);

        moveToZero();
		mt = mt->mul(scale);
        moveAfter();

		mt->printMatrix();
	}

    void rotate(double angle) override {
        auto rotateX = new Matrix();
        rotateX->createRotateMatrix(angle);

        moveToZero();
        mt = mt->mul(rotateX);
        moveAfter();

        normalizeCoordinates();
        mt->printMatrix();
    }


private:

    double ox, oy;

    void moveToZero() {
        ox = - (mt->mas[0][0] + mt->mas[1][0]) / 2;
        oy = - (mt->mas[0][1] + mt->mas[1][1]) / 2;
        move(ox, oy);
        ox = -ox;
        oy = -oy;
    }

    void moveAfter() {
        move(ox, oy);
    }

    void normalizeCoordinates() {
        for (int i = 0; i < mt->n; i++) {
            for (int j = 0; j < mt->m; j++) {
                mt->mas[i][j] /= mt->mas[i][mt->m-1];
            }
        }
    }

};

#endif // LINE_H
