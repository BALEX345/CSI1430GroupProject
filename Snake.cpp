#include "Snake.h"

using namespace std;



point Snake::getPoint(int n) const{
    return snakeXY[n];
}

int Snake::getLength() const{
    return currLength;
}

void Snake::addPoint(point p){
    snakeXY[currLength+1] = p;
    currLength++;
}

void Snake::updatePoint(point b, bool flag){
    int i = getLength();
    if(!flag){
        i++;
    }
    for(i ; i > 0; i--){
        snakeXY[i] = snakeXY[i-1];
    }
    snakeXY[0] = b;
}
bool Snake::touchingFruit(point fruit, bool self){
    bool flag = false;
    int i = 0;
    if(self){
        i++;
    }
    for(i; i < getLength(); i++){
        if(snakeXY[i] == fruit){
            flag = true;
        }
    }
    return flag;
}

void Snake::resetSnake(point& prev, point& curr){
    point coord1(450, 450);
    point coord2(400, 450);
    prev = coord1;
    curr = coord2;
    point temp;
    snakeXY[0] = coord1;
    snakeXY[1] = coord2;
    for(int i = 2; i < getLength(); i++){
        snakeXY[i] = temp;
    }
    currLength =  1;
};
