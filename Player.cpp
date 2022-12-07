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
