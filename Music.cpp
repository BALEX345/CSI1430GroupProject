#include "Music.h"

void Music::initSounds(SDL_Plotter &g){
    g.initSound(GAME_MUSIC);
    g.initSound(MENU_MUSIC);
    g.initSound(OUTRO_MUSIC);
    for(int i = 0; i < 10; i++){
        g.initSound(arr[i]);
    }
}

void Music::playMusic(SDL_Plotter &g){
    g.playSound(GAME_MUSIC);
}

void Music::stopMusic(SDL_Plotter &g){
    g.quitSound(GAME_MUSIC);
    g.initSound(GAME_MUSIC);
}


void Music::menuMusic(SDL_Plotter &g){
    g.playSound(MENU_MUSIC);
}

void Music::stopMenuMusic(SDL_Plotter &g){
    g.quitSound(MENU_MUSIC);
    g.initSound(MENU_MUSIC);
}

void Music::playHit(SDL_Plotter &g, int r){
    if(r>10 || r < 0){
        r = 0;
    }
    g.playSound(arr[r]);
}
void Music::playEat(SDL_Plotter &g, int r){
    if(r>10 || r < 0){
        r = 5;
    }
    g.playSound(arr[r+5]);
}

void Music::playOutro(SDL_Plotter &g){
    g.playSound(OUTRO_MUSIC);
}

