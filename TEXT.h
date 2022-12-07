#include "SDL_Plotter.h"
#include <fstream>
#include <string>

using namespace std;


/*
* description: function draws each letter of its respective text file
* return: void
* precondition: int[26][15][20] exist
* postcondition: defines each letter
*/

void fontInit(int [26][15][20]);

/*
* description: function draws each number of its respective text file
* return: void
* precondition: int[10][15][20] exist
* postcondition: defines each number
*/

void numInit(int [10][15][20]);


void displayCharMenu(SDL_Plotter& g, int Font[26][15][20], int c, int x, int y, color erse, color plot, color txt, int shift);


void displayString(SDL_Plotter& g, int Font[26][15][20], int x, int y, string str, color clr, int s = 5, int spc = 20);


/*
*
*
*
*
*/
void displayChar(SDL_Plotter& g, int Font[26][15][20], int c, int x, int y, color clr, int s = 10, int spc = 200);

/*
* description: function plots pixels to form a string named: "FALLINGBALLS"
* return: void
* precondition: an SDL_Plotter& and int[26][15][20] exist
* postcondition: draws the letters needed to form the title of the game
*/
void displayScore(SDL_Plotter& g, int Font[10][15][20], int x, int y, color clr, int score);
