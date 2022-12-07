/*
 * Authors: Samuel Fries
 *          Alejandro Garcia Jr
 *          Christian Wright
 *          Luke Heard
 *          Zac Benson
 *
 *          sam_fries1
 *          alex_garcia17
 *          christian_wright2
 *          luke_heard1
 *          zac_benson1
 *
 *          Honorable Mentions (Assistance with assets)
 *          * Josh Prior - Music
 *          * Alejandro Garcia Jr - Vocals
 *          * Megan Monthofer - Explaining Text
 *          * MyInstants.com - Sound effects
 *
 * Assignment Title: CSI1430 Group Project - Snake Game
 * Assignment Description: This program creates a working Snake Game.
 *                         The game asks for a Name, and Pin (these are saved)
 *                         Contains a menu screen, game screen, and outro.
 * Due Date: 12/07/2022
 * Date Created: 11/24/2022
 * Date Last Modified: 12/07/2022
 *
 * Data Abstraction: Creates all necessary variables to make our snake game.
 * Input:            Takes in the users name and pin and stores them into a file. (This is used to save high scores.)
 * Process:          Creates the game, displays the menu screen with instructions, displays the game screen,
 *                   lets the user play the game.
 * Output:           A working game is output to the screen.
 * Assumptions:      Assumes that the user has a working computer.
 *                   Assumes that the user can follow instructions.
 */
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
    for(i; i > 0; i--){
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
