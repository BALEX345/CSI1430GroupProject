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
#include "TEXT.h"



void fontInit(int Font[26][15][20]){

    ifstream inputFile[26];
    string trash1, trash2;
    int letter;

    inputFile[0].open("Letters/A.txt");
    inputFile[1].open("Letters/B.txt");
    inputFile[2].open("Letters/C.txt");
    inputFile[3].open("Letters/D.txt");
    inputFile[4].open("Letters/E.txt");
    inputFile[5].open("Letters/F.txt");
    inputFile[6].open("Letters/G.txt");
    inputFile[7].open("Letters/H.txt");
    inputFile[8].open("Letters/I.txt");
    inputFile[9].open("Letters/J.txt");
    inputFile[10].open("Letters/K.txt");
    inputFile[11].open("Letters/L.txt");
    inputFile[12].open("Letters/M.txt");
    inputFile[13].open("Letters/N.txt");
    inputFile[14].open("Letters/O.txt");
    inputFile[15].open("Letters/P.txt");
    inputFile[16].open("Letters/Q.txt");
    inputFile[17].open("Letters/R.txt");
    inputFile[18].open("Letters/S.txt");
    inputFile[19].open("Letters/T.txt");
    inputFile[20].open("Letters/U.txt");
    inputFile[21].open("Letters/V.txt");
    inputFile[22].open("Letters/W.txt");
    inputFile[23].open("Letters/X.txt");
    inputFile[24].open("Letters/Y.txt");
    inputFile[25].open("Letters/Z.txt");

    for(int i = 0; i < 26; i++){
        getline(inputFile[i], trash1);
        getline(inputFile[i], trash2);
        for(int j = 0; j < 20; j++){
            for(int k = 0; k < 15; k++){
                 inputFile[i] >> letter;
                 Font[i][k][j] = letter;
            }
        }
        inputFile[i].close();
    }
}

void numInit(int numArray[10][15][20]){

    ifstream inputFile2[10];
    string trash1, trash2;
    int letter;

    inputFile2[0].open("Numbers/0.txt");
    inputFile2[1].open("Numbers/1.txt");
    inputFile2[2].open("Numbers/2.txt");
    inputFile2[3].open("Numbers/3.txt");
    inputFile2[4].open("Numbers/4.txt");
    inputFile2[5].open("Numbers/5.txt");
    inputFile2[6].open("Numbers/6.txt");
    inputFile2[7].open("Numbers/7.txt");
    inputFile2[8].open("Numbers/8.txt");
    inputFile2[9].open("Numbers/9.txt");

    for(int i = 0; i < 10; i++){
        getline(inputFile2[i], trash1);
        getline(inputFile2[i], trash2);
        for(int j = 0; j < 20; j++){
            for(int k = 0; k < 15; k++){
                 inputFile2[i] >> letter;
                 numArray[i][k][j] = letter;
            }
        }
        inputFile2[i].close();
    }
}

void displayString(SDL_Plotter& g, int Font[26][15][20], int x, int y, string str, color clr, int s, int spc){
    int arrShift = 65;
    if(str.at(0) >= 48 && str.at(0) <= 57){
        arrShift = 48;
    }
    for(size_t i = 0; i < str.length(); i++){
        if(str.at(i) != ' '){
            displayChar(g, Font, static_cast<int>(str.at(i)) - arrShift, x, y, clr, s);
            x+=spc;
        }
        else{
            x+=spc;
        }
    }
}

void displayChar(SDL_Plotter& g, int Font[26][15][20], int c, int x, int y, color clr, int s, int spc){
    int num;
    int xOffset = spc, yOffset = 0;
    int yStart = y;
    int xStart = x;


    for(int y = 0; y < 20; y++){
        for(int x = 0; x < 15; x++){
            num = Font[c][x][y];
            if(num == 1){
                for(int i = 0; i < s; i++){
                    for(int j = 0; j < s; j++){
                        g.plotPixel(xStart + xOffset + (x * s) + i,
                                    yStart + yOffset + (y * s) + j,
                                    clr);
                    }
                }
            }
        }
        }


}

void displayCharMenu(SDL_Plotter& g, int Font[26][15][20], int c, int x, int y, color erse, color plot, color txt, int shift){
    displayChar(g, Font, c, x, y + shift, erse);
    displayChar(g, Font, c, x-3, y + shift-3, erse);
    displayChar(g, Font, c, x, y - shift, plot);
    displayChar(g, Font, c, x-3, y - shift-3, txt);
}

void displayScore(SDL_Plotter& g, int Font[10][15][20], int x, int y, color clr, int score)
{
    if(score == 0){
        displayChar(g, Font, score, x, y, clr, 2);
    }
    for(int i = score, shift = 0, h = i%10; i > 0; i/=10, shift -= 40){
        h = i%10;
        displayChar(g, Font, h, x + shift, y, clr, 2);
    }

}

