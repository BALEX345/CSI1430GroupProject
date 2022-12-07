#include "SDL_Plotter.h"
#include <fstream>
#include <string>

using namespace std;

/*
* description: Used to initialize the font.
* return: Void.
* precondition: Array to hold the characters.
* postcondition: Letters are initialized.
*/
void fontInit(int [26][15][20]);
/*
* description: Used to initialize the Numbers.
* return: Void.
* precondition: Array to hold the numbers.
* postcondition: Numbers are initialized.
*/
void numInit(int [10][15][20]);
/*
 * Description: Displays the characters that move in the menu.
 * Return: Void.
 * Precondition: Existing plotter, Font Array, Character, x and y values for plotting, 3 colors, and shift.
 * Postcondition: Menu chracters are displayed.
 */
void displayCharMenu(SDL_Plotter& g, int Font[26][15][20], int c, int x, int y, color erse, color plot, color txt, int shift);
/*
 * Description: Displays a string to the screen.
 * Return: Void.
 * Precondition: Existing Plotter, Font Array, x and y values for plotting, color, size value, and spacing value.
 * Postcondition: The string is printed.
 */
void displayString(SDL_Plotter& g, int Font[26][15][20], int x, int y, string str, color clr, int s = 5, int spc = 20);
/*
* Description: Displays a character to the screen.
* Return: Void.
* Precondition: Existing Plotter, Font Array, x and y values for plotting, color, size value, and spacing value.
* Postcondition: The character is printed.
*/
void displayChar(SDL_Plotter& g, int Font[26][15][20], int c, int x, int y, color clr, int s = 10, int spc = 200);
/*
* Description: Displays the score.
* Return: Void.
* Precondition: Existing Plotter, Font Array, x and y values for plotting, color, and score value.
* Postcondition: The score is printed.
*/
void displayScore(SDL_Plotter& g, int Font[10][15][20], int x, int y, color clr, int score);
