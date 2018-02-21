#include <iostream>

#include "Line.h"

#ifndef BLINE_H
#define BLINE_H

class BLine : public Line {
public:
    BLine(int x1, int y1, int x2, int y2) : Line(x1, y1, x2, y2) {
    }

    void draw(SDL_Renderer *renderer) override {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
        double x1 = mt->mas[0][0];
        double x2 = mt->mas[1][0];
        double y1 = mt->mas[0][1];
        double y2 = mt->mas[1][1];

        double deltaX = abs(x2 - x1);
        double deltaY = abs(y2 - y1);
        double signX = x1 < x2 ? 1 : -1;
        double signY = y1 < y2 ? 1 : -1;

        double error = deltaX - deltaY;

        SDL_RenderDrawPoint(renderer, x2, y2);
        while(x1 != x2 || y1 != y2) {
            SDL_RenderDrawPoint(renderer, x1, y1);
            double error2 = error * 2;

            if(error2 > -deltaY)
            {
                error -= deltaY;
                x1 += signX;
            }
            if(error2 < deltaX)
            {
                error += deltaX;
                y1 += signY;
            }
        }
    }

};

#endif //BLINE_H
