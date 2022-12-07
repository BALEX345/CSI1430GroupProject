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
