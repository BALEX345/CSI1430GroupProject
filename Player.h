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

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <vector>
#include <string>
#include <ostream>

using namespace std;

struct User{
    string name = "NONE";
    string pin = "---";
    int score = 0;
};


class Player{
private:
    vector<User> board;

public:
    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    void addPlayer(string n = "NONE", string p = "N/A", int s = 0);

    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    void removePlayer(string n = "NONE");

    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    void removePlayer(int index);

    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    void removeExtra();

    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    void sortBoard();

    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    bool updatePlayer(string str, string userPin, int score);

    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    bool checkPlayer(int ind, string userPin);

    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    int searchBoard(string player) const;

    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    int getPlayerCount() const;

    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    int getPlayerScore(string user) const;

    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    string getPlayerName(int n) const;

    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    void printBoardRow(ostream& outStream, int index, bool printPin = false) const;


};

#endif // PLAYER_H_INCLUDED
