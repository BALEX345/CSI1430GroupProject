#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED

#include "SDL_Plotter.h"
#include <string>

using namespace std;

const string GAME_MUSIC = "SNAKE!.mp3";
const string MENU_MUSIC = "SnakeMenu.mp3";
const string OUTRO_MUSIC = "Outro.mp3";

class Music{
private:
    string arr[10] = {"SnakeHit1.wav", "SnakeHit2.wav", "SnakeHit3.wav", "SnakeHit4.wav",
                     "SnakeHit5.wav","Eat1.wav", "Eat2.wav", "Eat3.wav", "Eat4.wav", "Eat5.wav"};
public:
    void initSounds(SDL_Plotter &g);
    void playMusic(SDL_Plotter &g);
    void stopMusic(SDL_Plotter &g);
    void stopMenuMusic(SDL_Plotter &g);
    void menuMusic(SDL_Plotter &g);
    void playOutro(SDL_Plotter &g);

    void playHit(SDL_Plotter &g, int r);
    void playEat(SDL_Plotter &g, int r);

};

#endif // MUSIC_H_INCLUDED
