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
    /*
    * Description: Gets the length of the snake.
    * Return: Int.
    * Precondition: None.
    * Postcondition: Length of the snake.
    */
    int getLength() const;
    /*
    * Description: Gets a point on the snake.
    * Return: Point.
    * Precondition: An integer.
    * Postcondition: The point is returned.
    */
    point getPoint(int n) const;
    /*
     * Description: Adds a point to the snake.
     * Return: Void.
     * Precondition: A point.
     * Postcondition: A point is added.
     */
    void addPoint(point p);
    /*
     * Description: Updates the snake.
     * Return: Void.
     * Precondition: A point and a boolean.
     * Postcondition: The updated snake.
     */
    void updatePoint(point p, bool flag);
    /*
     * Description: Resets the snake.
     * Return: Void.
     * Precondition: Previous and current coordinates.
     * Postcondition: The snake is reset.
     */
    void resetSnake(point& prev, point& curr);
    /*
     * Description: Checks if the snake is touching a fruit.
     * Return: Bool
     * Precondition: An existing point, and a bool that checks for intersection.
     * Postcondition: The bool is returned.
     */
    bool touchingFruit(point p, bool self);
};


#endif // SNAKE_H_INCLUDED
