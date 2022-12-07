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
#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED

#include "SDL_Plotter.h"
#include <string>

using namespace std;

const string GAME_MUSIC = "SNAKE!.mp3";
const string MENU_MUSIC = "SnakeMenu.mp3";
const string PAUSE_SFX = "SnakePause.mp3";

class Music{
private:
    string arr[19] = {"SnakeHit1.wav", "SnakeHit2.wav", "SnakeHit3.wav", "SnakeHit4.wav",
                      "SnakeHit5.wav", "SnakeHit6.mp3", "SnakeHit7.mp3", "SnakeHit8.mp3",
                      "SnakeHit9.mp3", "SnakeHit10.mp3", "SnakeHit11.mp3", "SnakeHit12.mp3",
                      "SnakeHit13.mp3",
                      "SnakeHit5.wav","Eat1.wav", "Eat2.wav", "Eat3.wav", "Eat4.wav", "Eat5.wav"};
public:
    /*
     * Description: Initializes all the sounds for our game.
     * Return: None.
     * Precondition: Existing Plotter.
     * Postcondition: Game sound is initialized.
     */
    void initSounds(SDL_Plotter &g);
    /*
    * Description: Plays the game theme song.
    * Return: None.
    * Precondition: Existing Plotter.
    * Postcondition: Game theme plays when the user is on the game screen.
    */
    void playGameMusic(SDL_Plotter &g);
    /*
    * Description: Stops playing the theme song.
    * Return: None.
    * Precondition: Existing plotter.
    * Postcondition: Game theme stops playing.
    */
    void stopGameMusic(SDL_Plotter &g);
    /*
    * Description: Plays the menu music while the player is on the menu.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme starts playing.
    */
    void playMenuMusic(SDL_Plotter &g);
    /*
    * Description: Stops playing the menu music.
    * Return: Void.
    * Precondition: Existing Plotter.
    * Postcondition: Menu theme stops playing.
    */
    void stopMenuMusic(SDL_Plotter &g);
    /*
     * Description: Plays a random hit sound from our pool.
     * Return: Void.
     * Precondition: Existing Plotter, number generated in main.
     * Postcondition: Plays a random hit.
     */
    void playSFX(SDL_Plotter &g, int r);

};

#endif // MUSIC_H_INCLUDED
