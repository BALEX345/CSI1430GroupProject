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
#include "Music.h"

void Music::initSounds(SDL_Plotter &g){
    g.initSound(MENU_MUSIC);
    g.initSound(GAME_MUSIC);
    g.initSound(PAUSE_SFX);
    for(int i = 0; i < 20; i++){
        g.initSound(arr[i]);
    }
}

void Music::playGameMusic(SDL_Plotter &g){
    g.playSound(GAME_MUSIC);
}

void Music::stopGameMusic(SDL_Plotter &g){
    g.quitSound(GAME_MUSIC);
    g.initSound(GAME_MUSIC);
}


void Music::playMenuMusic(SDL_Plotter &g){
    g.playSound(MENU_MUSIC);
}

void Music::stopMenuMusic(SDL_Plotter &g){
    g.quitSound(MENU_MUSIC);
    g.initSound(MENU_MUSIC);
}

void Music::playSFX(SDL_Plotter &g, int r){
    g.playSound(arr[r]);
}


