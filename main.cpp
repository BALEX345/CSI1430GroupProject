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

#include <iostream>
#include <string>
#include <fstream>
#include "SDL_Plotter.h"
#include "Player.h"


//FOR SCORE TESTING REMOVE LATER
#include <stdio.h>
#include <stdlib.h>

#include <ctime>
#include "Snake.h"
#include "TEXT.h"
#include "Music.h"

using namespace std;

const int NUM_ROW = 899; //899
const int FAKE_ROW = 1000;
const int FAKE_COL = 1000;
const int NUM_COL = 899; //899
const int GAME_BK_COLOR = 0;
const int MENU_BK_COLOR = 60;
const int FAKE_SHIFT = 100;
const color SNAKE_COLOR(60, 230,60);
const color GRID_COLOR(180, 180,180);
const color FRUIT_COLOR(245,42,42);
const color TEXT_COLOR(255,255,255);
const color ERASE_COLOR(MENU_BK_COLOR, MENU_BK_COLOR, MENU_BK_COLOR);
const color GAME_ERASE_COLOR(GAME_BK_COLOR,GAME_BK_COLOR,GAME_BK_COLOR);


const int SIZE = 49;

enum Direction {UP, DOWN, LEFT, RIGHT};

const int SNAP_SIZE = 50;

int main(int argc, char **argv)
{

    //Data Abstraction
    // -- Music class
    Music m;

    // -- Font variables
    int letters[26][15][20];
    int numbers[10][15][20];
    fontInit(letters);
    numInit(numbers);

    // -- Randomize
    srand(time(NULL));

    // -- Current player info
    string userName = "";
    string pin = "";
    int userScore = 0;
    int userHighScore = 0;

    // -- Text helper variables
    int counter = 0;
    int pinCounter = 0;
    int wait = 0;
    int pauseShift = 0;
    int textCounter = 0;
    int textCounterShift = 10;

    // -- Game helper variables
    bool menu = true;
    bool nameSet = false;
    bool startGame = false;
    bool pinSet = false;
    bool fruitSpawned = false;
    bool pause = false;
    bool menuScoreDisplay = false;
    bool existingPlr = false;

    // -- Sound helper variables
    int start = time(0);
    int start2 = 0;
    bool soundStart = false;
    bool menuStart = true;

    // -- Leader board variables
    Player leaderBoard;
    ofstream outFS;
    ifstream inFS;
    string nameHolder;
    string junkStr;
    string junkPin;
    int junkScore;

    // -- Snake and plotter variables
    char key;
    Direction dir = RIGHT;
    int speed = 120;
    int skip = 0, skip_value = 1;
    SDL_Plotter g(FAKE_ROW, FAKE_COL);

    Snake snake;
    point xyLoc(450 + FAKE_SHIFT, 450 + FAKE_SHIFT);
    point xyLocPrev(400 + FAKE_SHIFT, 450 + FAKE_SHIFT);
    point fruit;

    // -- Load sounds
    m.initSounds(g);


    //Input
    // -- Read in or create new leaderboard
    inFS.open("SnakeLeaderBoard.txt");
    if(!inFS){
        // -- Make new leaderboard
        outFS.open("SnakeLeaderBoard.txt");
        outFS.close();
        for(int i = 0; i < 5; i++){
           leaderBoard.addPlayer();
        }
    }
    else{
        // -- Read existing leaderboard
        while(inFS >> nameHolder){
            inFS >> junkStr;
            inFS >> junkScore;
            inFS >> junkStr;
            inFS >> junkPin;
            leaderBoard.addPlayer(nameHolder, junkPin, junkScore);

        }
    }
    inFS.close();


    //Process
    // -- Game loop
    m.playSFX(g, 19);
    while (!g.getQuit())
    {
        if (g.kbhit())
        {

            key = g.getKey();
            if(!menu && wait == 0){
                // -- Game interaction process
                switch (key)
                {
                case UP_ARROW   :
                    if(dir != DOWN){
                        dir = UP;
                    }
                    break;

                case DOWN_ARROW :
                    if(dir != UP){
                        dir = DOWN;
                    }
                    break;

                case LEFT_ARROW :
                    if(dir != RIGHT){
                        dir = LEFT;
                    }
                    break;

                case RIGHT_ARROW:
                    if(dir != LEFT){
                        dir = RIGHT;
                    }
                    break;
                case SPACE  :
                    menu = true;
                    startGame = false;
                    pause = true;
                    pauseShift = 435;
                    m.playSFX(g, 19);

                    break;
                }
            }
            else if(menu){
                // -- Menu interaction process
                switch (key)
                {
                case RETURN     :
                    if(userName.length() > 0 && !nameSet){
                        nameSet = true;
                    }
                    else if(nameSet && pin.length() == 3){
                        existingPlr = leaderBoard.checkPlayer(leaderBoard.searchBoard(userName),pin);
                        if(leaderBoard.searchBoard(userName) == -1 ||
                           existingPlr){
                            if(existingPlr){
                                userHighScore = leaderBoard.getPlayerScore(userName);
                            }
                            pinSet = true;
                            menu = false;
                            soundStart = true;


                            if(pause){
                                soundStart = false;
                                fruitSpawned = true;
                            }
                            else{
                                userScore = 0;
                            }
                            startGame = true;
                            start = time(0);
                            m.stopMenuMusic(g);
                        }
                        else{
                            start2 = time(0);
                            displayString(g, letters, 0, 450, "EXISTING PLAYER OR WRONG PIN ENTERED",
                                          TEXT_COLOR, 1);
                            displayString(g, letters, -150, 600 , "PIN", ERASE_COLOR, 3, 50 );
                            displayString(g, numbers, 300, 600 , pin, ERASE_COLOR, 3, 50 );
                            displayString(g, letters, 300, 500 , userName, ERASE_COLOR, 3, 50 );


                            counter = 0;
                            pinCounter = 0;
                            nameSet = false;
                            pinSet = false;
                            userName = "";
                            pin = "";
                        }
                    }
                    break;
                case BACKSPACE   :
                    if(!nameSet && userName.length() > 0){
                        counter-=25;
                        displayChar(g, letters, static_cast<int>(userName.back()) - 65,
                                    counter + 500, 500, ERASE_COLOR, 3, counter);
                        userName.pop_back();


                    }
                    else if(nameSet && !pinSet){
                        pinCounter -=25;
                        displayChar(g, numbers, static_cast<int>(pin.back()) -48,
                                    pinCounter + 500, 600, ERASE_COLOR, 3, pinCounter);
                        pin.pop_back();
                    }
                    break;
                default :
                    if(!nameSet && key >= 97 && key <= 122) {
                            if(!nameSet && userName.length() < 5){
                                userName += key-32;
                                displayChar(g, letters, static_cast<int>(key) - 97,
                                            counter + 500, 500, TEXT_COLOR, 3, counter);
                                counter+=25;
                            }
                       }
                    else if(nameSet && !pinSet && pin.length() < 3){
                        if(key >= 48 && key <= 57){
                            pin += key;
                            displayChar(g, numbers, static_cast<int>(key) -48,
                                        pinCounter + 500, 600, TEXT_COLOR, 3, pinCounter);
                            pinCounter+=25;
                        }
                    }
                }
            }

        }

        // -- Menu process
        if(menu){
            if(menuStart && !pause && time(0) > start+1){
                m.playMenuMusic(g);
                menuStart = false;
            }
            else if (time(0) > start2 + 34){
                start2 = time(0);
                menuStart = true;
            }

            if(!menuScoreDisplay){
                leaderBoard.sortBoard();
                g.backgroundColor(MENU_BK_COLOR);
                if(nameSet){
                    displayString(g, letters, -50, 500 , "PLAYER", TEXT_COLOR, 1, 30);
                    for(int i = 0, shift = 50; i < 5; i++, shift += 50){
                        displayString(g, letters, -50, 500 + shift, leaderBoard.getPlayerName(i),
                                     TEXT_COLOR, 2, 40);
                        displayScore(g, numbers, 625, 500 + shift, TEXT_COLOR,
                                     leaderBoard.getPlayerScore(leaderBoard.getPlayerName(i)));
                    }
                    displayString(g, letters, -50, 375, userName, TEXT_COLOR, 2, 40);

                    displayString(g, letters, 400, 500, "HIGHSCORE", TEXT_COLOR, 1, 30);
                    displayString(g, letters, 475, 435, "LAST", TEXT_COLOR, 1, 20);
                    displayString(g, letters, 475, 385, "HIGH", TEXT_COLOR, 1, 20);
                    displayString(g, letters, 215, 900, "ESC EXIT", TEXT_COLOR, 1, 20);
                    displayScore(g, numbers, 625, 375, TEXT_COLOR, userHighScore);
                    displayScore(g, numbers, 625, 425, TEXT_COLOR, userScore);
                }
                else{
                    displayString(g, letters, -150, 500 , "USERNAME", TEXT_COLOR, 3, 50 );


                }

            }
            if(nameSet && !pinSet){
                displayString(g, letters, -150, 600 , "PIN", TEXT_COLOR, 3, 50 );
            }
            menuScoreDisplay = true;

            // -- Fancy menu screen text process
            switch(textCounter){
            case 0:
                textCounter++;
                break;
            case 1:
                displayCharMenu(g, letters, 18, -185, 110, ERASE_COLOR,
                                GRID_COLOR, TEXT_COLOR, textCounterShift);
                textCounter++;
                break;
            case 2:
                displayCharMenu(g, letters, 13, 25, 110, ERASE_COLOR,
                                GRID_COLOR, TEXT_COLOR, textCounterShift);
                textCounter++;
                if(nameSet && pinSet){
                    displayString(g, letters, 45, 850 - pauseShift, "PRESS ENTER PLAY",
                                   ERASE_COLOR, 1, 30);

                }
                break;
            case 3:
                displayCharMenu(g, letters, 0, 235, 110, ERASE_COLOR, GRID_COLOR,
                                TEXT_COLOR, textCounterShift);
                textCounter++;
                break;
            case 4:
                displayCharMenu(g, letters, 10, 445, 110, ERASE_COLOR, GRID_COLOR,
                                TEXT_COLOR, textCounterShift);

                textCounter++;
                break;
            case 5:
                displayCharMenu(g, letters, 4, 655, 110, ERASE_COLOR, GRID_COLOR,
                                TEXT_COLOR, textCounterShift);
                if(nameSet && pinSet){
                    displayString(g, letters, 45, 850 - pauseShift, "PRESS ENTER PLAY",
                                  TEXT_COLOR, 1, 30);
                }
                textCounter++;
                break;
            case 6:
                textCounterShift *=-1;

                textCounter = 0;
                break;
            default:
                textCounter++;
            }



        }


        // -- Game process
        else if(!menu){
            if(soundStart){
                m.playGameMusic(g);
                soundStart = false;
            }
            else if (time(0) > start + 82){
                start = time(0);
                soundStart = true;
            }
            if(startGame == true){
                textCounter = 0;
                g.backgroundColor(GAME_BK_COLOR);
                displayString(g, letters, -100, 865, "MUSIC BY JOSH PRIOR",
                              TEXT_COLOR, 1, 15);
                displayString(g, letters, 430, 865, "SPACE  PAUSE",
                              TEXT_COLOR, 1, 15);
                displayScore(g, numbers, 725, 100, TEXT_COLOR, userScore);

                for(int i = -1; i <= NUM_ROW; i+=SNAP_SIZE){
                    for(int j = 0 + FAKE_SHIFT; j < NUM_COL - FAKE_SHIFT / 2; j++){
                        g.plotPixel(i, j, GRID_COLOR);
                        g.plotPixel(j, i, GRID_COLOR);
                    }
                }
                startGame = false;

            }
            // -- Spawn fruit
            if(!fruitSpawned){
                fruit.spawnFruit(NUM_COL);
                if(snake.touchingFruit(fruit, true)){
                    fruit.spawnFruit(NUM_COL);
                }
                g.plotSquare(fruit, FRUIT_COLOR, SIZE);

                fruitSpawned = true;
            }
            else if (snake.touchingFruit(fruit, false) ){
                // -- Add point, extend snake
                snake.addPoint(xyLocPrev);
                displayScore(g, numbers, 725, 100, GAME_ERASE_COLOR, userScore);
                userScore++;
                displayScore(g, numbers, 725, 100, TEXT_COLOR, userScore);

                m.playSFX(g, rand()%5 +14);
                if(userScore > userHighScore){
                    userHighScore = userScore;
                }
                g.plotSquare(fruit, GAME_ERASE_COLOR, SIZE);
                fruitSpawned = false;
            }
            // -- Re-plot fruit on unpause
            else if(pause){

                g.plotSquare(fruit, FRUIT_COLOR, SIZE);
                pause = false;
                pauseShift = 0;
            }

            if(wait == 0){
            xyLocPrev = xyLoc;
            snake.updatePoint(xyLocPrev, fruitSpawned);
            switch (dir)
                {
                case RIGHT:
                    xyLoc.x = xyLoc.x + SNAP_SIZE;
                    break;

                case LEFT:
                    xyLoc.x = xyLoc.x - SNAP_SIZE;
                    break;

                case UP:
                    xyLoc.y = xyLoc.y - SNAP_SIZE;
                    break;

                case DOWN:
                    xyLoc.y = xyLoc.y + SNAP_SIZE;
                    break;
                }
            }



            g.plotSquare(snake.getPoint(snake.getLength()), GAME_ERASE_COLOR,
                         SIZE);



            // -- Draw
            for(int i = 0; i < snake.getLength(); i++){
                g.plotSquare(snake.getPoint(i), SNAKE_COLOR, SIZE);

            }


            if (xyLoc.x > FAKE_ROW - FAKE_SHIFT * 2||
                xyLoc.x + SIZE - FAKE_SHIFT < 0 ||
                xyLoc.y > FAKE_COL - FAKE_SHIFT * 2||
                xyLoc.y - FAKE_SHIFT < 0 ||
                snake.touchingFruit(snake.getPoint(0), true)){

                if(wait == 0){
                    m.playSFX(g, rand()%14);
                }
                wait++;
                for(int i = snake.getLength(); i >= wait; i--){
                    for(int j = 0; j < wait; j++){
                        g.plotSquare(snake.getPoint(j), FRUIT_COLOR, SIZE);
                    }
                }

                if(wait == snake.getLength()){
                    if(!leaderBoard.checkPlayer(leaderBoard.searchBoard(userName),pin)){
                        leaderBoard.addPlayer(userName, pin, userHighScore);
                    }
                    else{
                        leaderBoard.updatePlayer(userName, pin, userHighScore);
                    }
                    snake.resetSnake(xyLocPrev, xyLoc);
                    startGame = false;
                    fruitSpawned = false;
                    menuScoreDisplay = false;
                    menuStart = true;
                    soundStart = true;
                    m.stopGameMusic(g);
                    menu = true;
                    wait = 0;
                }
            }

        }
        skip = (skip + 1) % skip_value;
        if (skip == 0)
        {
            g.update();

        }

        g.Sleep(speed);

    }


    //Output
    outFS.open("SnakeLeaderBoard.txt");
    leaderBoard.sortBoard();
    for(int i = 0; i <= leaderBoard.getPlayerCount()-1; i++){
        leaderBoard.printBoardRow(outFS, i, true);
    }

    outFS.close();

    return 0;
}
