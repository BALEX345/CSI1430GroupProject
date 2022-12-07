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
/*
 * SDL_Plotter.h
 *
 * Version 3.0
 * 5/31/2022
 *
 * Version 2.4
 * 4/4/2022
 *
 * Version 2.3
 *  6/28/2021
 *
 * Version 2.2
 *  4/26/2019
 *
 *  Dr. Booth
 */

#ifndef SDL_PLOTTER_H_
#define SDL_PLOTTER_H_

//OSX Library
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_mixer.h>
//#include <SDL2/SDL_thread.h>

//Windows Library
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <string.h>
#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <queue>
using namespace std;

const char UP_ARROW    = 1;
const char DOWN_ARROW  = 2;
const char LEFT_ARROW  = 3;
const char RIGHT_ARROW = 4;
const char RETURN = 5;
const char SPACE = 6;
const char BACKSPACE = 7;
const char GRAVE = 8;
const char ESCAPE = 9;
const int RED_SHIFT    = 65536;
const int GREEN_SHIFT  = 256;
const int BLUE_SHIFT   = 1;
const int ALPHA_SHIFT  = 16777216;
const int WHITE        = 255;
const int MAX_THREAD   = 100;
const int GRID_SIZE = 50;
const int FAKE_SIZE = 100;


//Point
struct point{
	int x,y;
	point(){
		x = y = 0;
	}
	point(int a, int b){
        x = a - a%GRID_SIZE;
        y = b - b%GRID_SIZE;
	}

	void spawnFruit(int side){
	    x = rand()%side;
	    x = x - x%GRID_SIZE;
	    x += FAKE_SIZE;
	    if(x > side - FAKE_SIZE * 2){
            x-= FAKE_SIZE * 2;
	    }
	    y = rand()%side;
	    y = y - y%GRID_SIZE;
	    y += FAKE_SIZE;
	    if(y > side - FAKE_SIZE * 2){
            y -= FAKE_SIZE * 2;
	    }
	}

	bool operator==(point rhs){
	    bool flag = false;
	    point temp;
	    temp.x = x;
	    temp.y = y;
	    if(temp.x == rhs.x && temp.y == rhs.y){
            flag = true;
	    }
	    return flag;
	}
};

//Color
struct color{
	unsigned int R,G,B;
	color(){
		R = G = B = 0;
	}
	color(int r, int g, int b){
	    R=r;
	    G=g;
	    B=b;
	}
};

//Threaded Sound Function
struct param{
	bool play;
	bool running;
	bool pause;
	SDL_Thread*  threadID;
	SDL_cond *cond;
	SDL_mutex *mut;
	string name;

	param(){
		play = false;
		running = false;
		pause = false;
	    cond = nullptr;
	    mut  = nullptr;
	    threadID = nullptr;
	    name="";
	}
};


class SDL_Plotter{
private:
	SDL_Texture  *texture;
	SDL_Renderer *renderer;
	SDL_Window   *window;
    Uint32       *pixels;
    const Uint8  *currentKeyStates;
    SDL_Event    event;
    int          row, col;
    bool         quit;

    //Keyboard Stuff
    queue<char> key_queue;

    //Mouse Stuff
    queue<point> click_queue;

    //Sound Stuff
    bool SOUND;
    int soundCount;
    map<string, param> soundMap;

    char getKeyPress(SDL_Event & event);

public:
    /*
    * Description: Plots a grid square to the screen.
    * Return: Void.
    * Precondition: Existing point, color, and positive size.
    * Postcondition: Plots a square to the grid.
    */
    void plotSquare(point f, color c, int s);

    /*
    * Description: Fills in the background color of the plotter.
    * Return: Void.
    * Precondition: Existing Plotter and color is within 0 and 255.
    * Postcondition: Entire color of the plotter is changed.
    */
    void backgroundColor(int c);

    SDL_Plotter(int r=480, int c=640, bool WITH_SOUND = true);
    ~SDL_Plotter();
    void update();

    bool getQuit();
    void setQuit(bool flag);

    bool kbhit();
    void callQuit();
    bool mouseClick();
    char getKey();
    point getMouseClick();

    void plotPixel(int x, int y, int r, int g, int b);
    void plotPixel(point p, int r, int g, int b);
    void plotPixel(int x, int y, color=color{});
    void plotPixel(point p, color=color{});

    void clear();

    int getRow();
    int getCol();

    void initSound(string sound);
    void playSound(string sound);
    void quitSound(string sound);

    void Sleep(int ms);

    bool getMouseDown(int& x, int& y);
    bool getMouseUp(int& x, int& y);
    bool getMouseMotion(int& x, int& y);
    void getMouseLocation(int& x, int& y);

    Uint32 getColor(int x, int y);

};

#endif // SDL_PLOTTER_H_
