#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <vector>
#include "SDL_Plotter.h"
using namespace std;

const int MAX_LENGTH = 200;

class Snake{
private:
    point snakeXY[MAX_LENGTH];
    int currLength = 1;
public:
    int getLength() const;
    point getPoint(int n) const;
    void addPoint(point p);
    void updatePoint(point p, bool flag);
    void resetSnake(point& prev, point& curr);

    bool touchingFruit(point p, bool self);
};


#endif // SNAKE_H_INCLUDED
