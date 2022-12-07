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
