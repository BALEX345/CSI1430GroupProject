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

//    GameFunctions game;

    char key;

    //Music class
    Music m;

    //Font Stuff
    int letters[26][15][20];
    int numbers[10][15][20];

    //FOR SCORE TESTING REMOVE LATER
    srand(time(NULL));


    string userName = "";
    string pin = "";
    string scoreString;

    int updatePlayer = -1;
    int userScore = 0;
    int sum = 0;
    int counter = 0;
    int pinCounter = 0;
    int userHighScore = 0;
    int wait = 0;

    bool menu = true;
    bool nameSet = false;
    bool startGame = false;
    bool pinSet = false;
    bool newPlayer = true;
    bool fruitSpawned = false;
    bool pause = false;
    bool menuScoreDisplay = false;
    bool existingPlr = false;
    bool outro = false;

    //Sounds
    int start = time(0);
    int start2 = 0;
    int soundDif = 0;
    int thelp = 0;
    bool soundStart = false;
    bool menuStart = true;

    int textCounter = 0;
    int textCounterShift = 10;


    ofstream outFS;
    ifstream inFS;

    //PlayerClass stuff
    Player leaderBoard;

    //Make it store into a vector class for easy sorting or searching
    string nameHolder;
    string junkStr;
    string junkPin;

    int score;

    int R=20, G=20, B=255;

    Direction dir = RIGHT;
    int speed = 120; //60
    int skip = 0, skip_value = 1; //5


    SDL_Plotter g(FAKE_ROW, FAKE_COL);

    m.initSounds(g);

    point xyLoc(450 + FAKE_SHIFT, 450 + FAKE_SHIFT);
    point xyLocPrev(400 + FAKE_SHIFT, 450 + FAKE_SHIFT);


    Snake snake;
    point fruit;

    fontInit(letters);
    numInit(numbers);

    //LOADING FILE
    cout << "LOADING FILE..." << endl;

    inFS.open("SnakeLeaderBoard.txt");

    if(!inFS){

        cout << "Err: FILE NOT FOUND\nCREATING LEADERBOARD FILE..." << endl;

        outFS.open("SnakeLeaderBoard.txt");
        outFS.close();
        for(int i = 0; i < 5; i++){
           leaderBoard.addPlayer();
        }
    }
    else{

        cout << "LEADERBOARD FOUND" << endl;
        cout << "LOADING LEADERBOARD..." << endl;

        while(inFS >> nameHolder){
            inFS >> junkStr;
            inFS >> score;
            inFS >> junkStr;
            inFS >> junkPin;
            leaderBoard.addPlayer(nameHolder, junkPin, score);

        }
    }
    inFS.close();


    //Game loop
    while (!g.getQuit())
    {

        if (g.kbhit())
        {

            key = g.getKey();
            if(!menu){
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
                    break;
                }
            }
            else if(menu){
                switch (key)
                {
                case RETURN     :
                    if(userName.length() > 0 && !nameSet){
                        nameSet = true;
                    }
                    else if(nameSet && pin.length() == 3){
                        existingPlr = leaderBoard.checkPlayer(leaderBoard.searchBoard(userName), pin);
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
                            displayString(g, letters, 0, 450, "EXISTING PLAYER OR WRONG PIN ENTERED", TEXT_COLOR, 1);
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
                        displayChar(g, letters, static_cast<int>(userName.back()) - 65, counter + 500, 500, ERASE_COLOR, 3, counter);
                        userName.pop_back();


                    }
                    else if(nameSet && !pinSet){
                        pinCounter -=25;
                        displayChar(g, numbers, static_cast<int>(pin.back()) -48, pinCounter + 500, 600, ERASE_COLOR, 3, pinCounter);
                        pin.pop_back();
                    }
                    break;
                default :
                    if(!nameSet && key >= 97 && key <= 122) {
                            if(!nameSet && userName.length() < 5){
                                userName += key-32;
                                displayChar(g, letters, static_cast<int>(key) - 97, counter + 500, 500, TEXT_COLOR, 3, counter);
                                counter+=25;
                            }
                       }
                    else if(nameSet && !pinSet && pin.length() < 3){
                        if(key >= 48 && key <= 57){
                            pin += key;
                            displayChar(g, numbers, static_cast<int>(key) -48, pinCounter + 500, 600, TEXT_COLOR, 3, pinCounter);
                            pinCounter+=25;
                        }
                    }
                }
            }

        }

        // Process
        // ---- Menu Process
        if(menu){
            if(menuStart){
                m.menuMusic(g);
                menuStart = false;
            }
            else if (time(0) > start2 + 34){
                start2 = time(0);
                menuStart = true;
            }

            if(!menuScoreDisplay){
                thelp = 0;
                leaderBoard.sortBoard();
                g.backgroundColor(MENU_BK_COLOR);
                sum = 0;
                if(nameSet){
                    displayString(g, letters, 0, 500 , "PLAYER", TEXT_COLOR, 1, 30);
                    for(int i = 0, shift = 50; i < 5; i++, shift += 50){
                        displayString(g, letters, 0, 500 + shift, leaderBoard.getPlayerName(i), TEXT_COLOR, 2, 40);
                        displayScore(g, numbers, 625, 500 + shift, TEXT_COLOR, leaderBoard.getPlayerScore(leaderBoard.getPlayerName(i)));

                    }
                    displayString(g, letters, 200, 375, userName, TEXT_COLOR, 2, 40);

                    displayString(g, letters, 400, 500, "HIGHSCORE", TEXT_COLOR, 1, 30);
                    displayScore(g, numbers, 400, 375, TEXT_COLOR, userHighScore);
                }
                else{
                    displayString(g, letters, -150, 500 , "USERNAME", TEXT_COLOR, 3, 50 );


                }

            }
            if(nameSet && !pinSet){
                displayString(g, letters, -150, 600 , "PIN", TEXT_COLOR, 3, 50 );
            }
            menuScoreDisplay = true;

            switch(textCounter){
            case 0:
                textCounter++;
                break;
            case 1:
                displayCharMenu(g, letters, 18, -185, 110, ERASE_COLOR, GRID_COLOR, TEXT_COLOR, textCounterShift);
                textCounter++;
                break;
            case 2:
                displayCharMenu(g, letters, 13, 25, 110, ERASE_COLOR, GRID_COLOR, TEXT_COLOR, textCounterShift);
                textCounter++;
                if(nameSet && pinSet){
                    displayString(g, letters, 90, 850, "PRESS ENTER PLAY", ERASE_COLOR, 1, 30);

                }
                break;
            case 3:
                displayCharMenu(g, letters, 0, 235, 110, ERASE_COLOR, GRID_COLOR, TEXT_COLOR, textCounterShift);
                textCounter++;
                break;
            case 4:
                displayCharMenu(g, letters, 10, 445, 110, ERASE_COLOR, GRID_COLOR, TEXT_COLOR, textCounterShift);

                textCounter++;
                break;
            case 5:
                displayCharMenu(g, letters, 4, 655, 110, ERASE_COLOR, GRID_COLOR, TEXT_COLOR, textCounterShift);
                if(nameSet && pinSet){
                    displayString(g, letters, 90, 850, "PRESS ENTER PLAY", TEXT_COLOR, 1, 30);

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


        // ---- Game Process
        else if(!menu){
            if(soundStart){
                m.playMusic(g);
                soundStart = false;
            }
            else if (time(0) > start + 82){
                start = time(0);
                soundStart = true;
            }
            if(startGame == true){
                textCounter = 0;
                g.backgroundColor(GAME_BK_COLOR);
                displayString(g, letters, -100, 865, "MUSIC BY JOSH PRIOR", TEXT_COLOR, 1, 20);

                for(int i = -1; i <= NUM_ROW; i+=SNAP_SIZE){
                    for(int j = 0 + FAKE_SHIFT; j < NUM_COL - FAKE_SHIFT / 2; j++){
                        g.plotPixel(i, j, GRID_COLOR);
                        g.plotPixel(j, i, GRID_COLOR);

                    }
                }
                startGame = false;
            }

            if(!fruitSpawned){
                fruit.spawnFruit(NUM_COL);
                if(snake.touchingFruit(fruit, true)){
                    fruit.spawnFruit(NUM_COL);
                }
                g.plotFruit(fruit, FRUIT_COLOR, SIZE);

                fruitSpawned = true;
            }
            else if (snake.touchingFruit(fruit, false)){
                snake.addPoint(xyLocPrev);
                userScore++;
                switch(rand()%5){
                case 0:
                    m.playEat(g, 0);
                    break;
                case 1:
                    m.playEat(g, 1);
                    break;
                case 2:
                    m.playEat(g, 2);;
                    break;
                case 3:
                    m.playEat(g, 3);
                    break;
                case 4:
                    m.playEat(g, 4);
                    break;
                }
                if(userScore > userHighScore){
                    userHighScore = userScore;
                }
                g.plotFruit(fruit, GAME_ERASE_COLOR, SIZE);
                fruitSpawned = false;
            }
            else if(pause){
                g.plotFruit(fruit, FRUIT_COLOR, SIZE);
                pause = false;
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


            g.plotFruit(snake.getPoint(snake.getLength()), GAME_ERASE_COLOR, SIZE);



            // Draw
            for(int i = 0; i < snake.getLength(); i++){
                g.plotFruit(snake.getPoint(i), SNAKE_COLOR, SIZE);

            }


            if (xyLoc.x > FAKE_ROW - FAKE_SHIFT * 2|| xyLoc.x + SIZE - FAKE_SHIFT < 0 ||
                xyLoc.y > FAKE_COL - FAKE_SHIFT * 2|| xyLoc.y - FAKE_SHIFT < 0 ||

                snake.touchingFruit(snake.getPoint(0), true)){
                if(wait == 0){
                    switch(rand()%5){
                    case 0:
                        m.playHit(g, 0);
                        break;
                    case 1:
                        m.playHit(g, 1);
                        break;
                    case 2:
                        m.playHit(g, 2);
                        break;
                    case 3:
                        m.playHit(g, 3);
                        break;
                    case 4:
                        m.playHit(g, 4);
                        break;
                    }
                }
                wait++;

                for(int i = 0; i < snake.getLength() && wait%3 == 0; i++){
                    g.plotFruit(snake.getPoint(i), FRUIT_COLOR, SIZE);
                }

                if(wait == 9){
                    if(!leaderBoard.checkPlayer(leaderBoard.searchBoard(userName), pin)){
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
                    m.stopMusic(g);
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

    //Exit game process
    m.stopMenuMusic(g);
    m.stopMusic(g);
    m.playOutro(g);
    outFS.open("SnakeLeaderBoard.txt");
    if(userName.size() != 0 && pin.size() == 3){

        leaderBoard.sortBoard();

        for(int i = 0; i <= leaderBoard.getPlayerCount()-1; i++){
            leaderBoard.printBoardRow(outFS, i, true);
        }
    }
    else{
        for(int i = 0; i <= leaderBoard.getPlayerCount()-1; i++){
            leaderBoard.printBoardRow(outFS, i, true);
        }
    }
    outFS.close();



    return 0;
}
