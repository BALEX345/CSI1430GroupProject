#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <vector>
#include <string>
#include <ostream>

using namespace std;

struct User{
    string name = "NONE";
    string pin = "---";
    int score = 0;
};


class Player{
private:
    vector<User> board;

public:
    void addPlayer(string n = "NONE", string p = "N/A", int s = 0);
    void removePlayer(string n = "NONE");
    void removePlayer(int index);
    void removeExtra();
    void sortBoard();

    bool updatePlayer(string str, string userPin, int score);
    bool checkPlayer(int ind, string userPin);

    int searchBoard(string player) const;
    int getPlayerCount() const;
    int getPlayerScore(string user) const;
    string getPlayerName(int n) const;

    void printBoardRow(ostream& outStream, int index, bool printPin = false) const;


};

#endif // PLAYER_H_INCLUDED
