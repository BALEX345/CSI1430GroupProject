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

//void displayTitle(SDL_Plotter&, int [26][15][20], int x, int y, color c);
//
//
//* description: function plots pixels to form the string "SCORE"
//* return: void
//* precondition: an SDL_Plotter& and int[26][15][20] exist
//* postcondition: draws the letters needed to form the string "SCORE"
//

void displayScore(SDL_Plotter& g, int Font[10][15][20], int x, int y, color clr, int score);

/*
* description: function plots pixels to form the string "HIGHSCORE"
* return: void
* precondition: an SDL_Plotter& and int[26][15][20] exist
* postcondition: draws the letters needed to form the string "HIGHSCORE"
*/

void displayHighScore(SDL_Plotter&, int [26][15][20]);

/*
* description: function plots pixels to form the string "LIVES"
* return: void
* precondition: an SDL_Plotter& and int[26][15][20] exist
* postcondition: draws the letters needed to form the string "LIVES"
*/

//void displayLives(SDL_Plotter&, int[26][15][20]);
//
///*
//* description: function plots pixels to form the string "GAMEOVER"
//* return: void
//* precondition: an SDL_Plotter& and int[26][15][20] exist
//* postcondition: draws the letters needed to form the string "GAMEOVER"
//*/
//
//void displayGameOver(SDL_Plotter&, int[26][15][20]);
//
///*
//* description: function plots pixels to form the string "GAMEOVER"
//* return: void
//* precondition: an SDL_Plotter& and int[26][15][20] exist
//* postcondition: draws the letters needed to form the string "GAMEOVER"
//*/
//
//void displayInstruct(SDL_Plotter&, int[26][15][20]);
//
///*
//* description: function plots pixels to display 0
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and two integers exist
//* postcondition: plots the appropriate pixels to form the number 0
//*/
//
//void display0(SDL_Plotter&, int[10][15][20], int, int);
//
///*
//* description: function plots pixels to display 1
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and two integers exist
//* postcondition: plots the appropriate pixels to form the number 1
//*/
//
//void display1(SDL_Plotter&, int[10][15][20], int, int);
//
///*
//* description: function plots pixels to display 2
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and two integers exist
//* postcondition: plots the appropriate pixels to form the number 2
//*/
//
//void display2(SDL_Plotter&, int[10][15][20], int, int);
//
///*
//* description: function plots pixels to display 3
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and two integers exist
//* postcondition: plots the appropriate pixels to form the number 3
//*/
//
//void display3(SDL_Plotter&, int[10][15][20], int, int);
//
///*
//* description: function plots pixels to display 4
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and two integers exist
//* postcondition: plots the appropriate pixels to form the number 4
//*/
//
//void display4(SDL_Plotter&, int[10][15][20], int, int);
//
///*
//* description: function plots pixels to display 5
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and two integers exist
//* postcondition: plots the appropriate pixels to form the number 5
//*/
//
//void display5(SDL_Plotter&, int[10][15][20], int, int);
//
///*
//* description: function plots pixels to display 6
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and two integers exist
//* postcondition: plots the appropriate pixels to form the number 6
//*/
//
//void display6(SDL_Plotter&, int[10][15][20], int, int);
//
///*
//* description: function plots pixels to display 7
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and two integers exist
//* postcondition: plots the appropriate pixels to form the number 7
//*/
//
//void display7(SDL_Plotter&, int[10][15][20], int, int);
//
///*
//* description: function plots pixels to display 8
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and two integers exist
//* postcondition: plots the appropriate pixels to form the number 8
//*/
//
//void display8(SDL_Plotter&, int[10][15][20], int, int);
//
///*
//* description: function plots pixels to display 9
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and two integers exist
//* postcondition: plots the appropriate pixels to form the number 9
//*/
//
//void display9(SDL_Plotter&, int[10][15][20], int, int);
//
///*
//* description: displays the current score which is the amount of obstacles hit
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and a score that is past
//*               reference exist
//* postcondition: plots the appropriate numbers for the score the player has
//*/
//
//void displayCurrScore(SDL_Plotter&, int[10][15][20], int&);
//
///*
//* description: displays the current lives which is the amount of balls left to shoot
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and an int& exist
//* postcondition: plots the appropriate numbers for the amount of balls the
//*                player has left
//*/
//
//void displayCurrLives(SDL_Plotter&, int[10][15][20], int&);
//
///*
//* description: displays the current high score which is the amount of obstacles hit
//* return: void
//* precondition: an SDL_Plotter&, int[10][15][20], and an int& exist
//* postcondition: plots the appropriate numbers for the highest score that a player
//*                has reached
//*/
//
//void displayCurrHighScore(SDL_Plotter&, int[10][15][20], int&);
