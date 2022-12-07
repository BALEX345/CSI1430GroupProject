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

#include "Player.h"
#include <iostream>

void Player::addPlayer(string n, string p, int s){
    User temp;
    temp.name = n;
    temp.score = s;
    temp.pin = p;
    board.push_back(temp);
}

void Player::removePlayer(string n){
    int index = searchBoard(n);
    removePlayer(index);
}

void Player::removePlayer(int n){
    if(n >= 0 && n <= static_cast<int>(board.size()) -1){
        board.erase(board.begin() + n);
    }
}
void Player::removeExtra(){
    for(int i = getPlayerCount()-1; i >= 0; i--){
        if(board.at(i).name == "NONE" && getPlayerCount() > 5){
            removePlayer(i);
        }
    }
}


void Player::sortBoard(){
    int i, j;
    User temp;
    removeExtra();
    for(i = 1; i < getPlayerCount(); i++){
        j = i;
        while(j > 0 && (board.at(j-1).score < board.at(j).score ||
                        board.at(j-1).score == board.at(j).score &&
                        board.at(j-1).name.compare(board.at(j).name) > 0)){
            swap(board.at(j), board.at(j-1));
            j--;
        }
    }

}

bool Player::updatePlayer(string userName, string userPin, int s){
    bool newPlr = true;
    int flag = searchBoard(userName);
    if(flag != -1 && board.at(flag).pin.compare(userPin) == 0){
        if(board.at(flag).score < s){
            board.at(flag).score = s;
        }
        newPlr = false;
    }
    return newPlr;
}

bool Player::checkPlayer(int ind, string userPin){
    bool flag = false;
    if(ind != -1 && board.at(ind).pin.compare(userPin) == 0){
        flag = true;
    }
    return flag;

}

int Player::searchBoard(string player) const{
    int ind = -1;
    bool flag = false;
    for(int i = 0; i < getPlayerCount() && !flag; i++){
        if(board.at(i).name.compare(player) == 0){
            ind = i;
            flag = true;
        }
    }
    return ind;

}


int Player::getPlayerCount() const{
    return static_cast<int>(board.size());
}

int Player::getPlayerScore(string user) const{
    int flag = searchBoard(user);
    if(flag != -1){
        return board.at(flag).score;
    }
}

void Player::printBoardRow(ostream& outStream, int i, bool flag) const{
    if(i >= getPlayerCount()){
        i = 0;
        outStream << "-1" << endl; // Index checker
    }
    else{
        outStream << board.at(i).name << " - " << board.at(i).score;
        if(flag){
            outStream << " - " << board.at(i).pin;
        }
        outStream << endl;
    }
}

string Player::getPlayerName(int n) const{
    return board.at(n).name;
}
