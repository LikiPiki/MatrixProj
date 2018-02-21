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

        double deltax = abs(x2 - x1);
        double deltay = abs(y2 - y1);
        double error = 0;
        double deltaerr = deltay;
        double y = y1;
        double diry = y2 - y1;

        if (diry > 0) diry = 1;
        if (diry < 0) diry = -1;

        for (double x = x1; x < x2; x++) {
            SDL_RenderDrawPoint(renderer, x, y);
            error = error + deltaerr;
            if (2 * error >= deltax) {
                y = y + diry;
                error -= deltax;
            }
        }
    }

};

#endif //BLINE_H
