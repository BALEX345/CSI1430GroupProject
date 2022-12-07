#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "SDL_Plotter.h"
#include <string>

using namespace std;

const string GAME_MUSIC = "SNAKE!.mp3";
const string MENU_MUSIC = "SnakeMenu.mp3";

class Music{
private:
    string arr[10] = {"SnakeHit1.wav", "SnakeHit2.wav", "SnakeHit3.wav", "SnakeHit4.wav",
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
    void playHit(SDL_Plotter &g, int r);
    /*
    * Description: Plays a random munch sound from our pool.
    * Return: Void.
    * Precondition: Existing Plotter, number generated in main.
    * Postcondition: Plays a random munch.
    */
    void playEat(SDL_Plotter &g, int r);

};

#endif // SNAKE_H_INCLUDED
