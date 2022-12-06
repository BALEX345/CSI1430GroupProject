
#include "TEXT.h"



void fontInit(int Font[26][15][20]){

    ifstream inputFile[26];
    string trash1, trash2;
    int letter;

    // OPENS EACH LETTER FILE

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

    // CLOSES EACH LETTER FILE

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

    // OPENS EACH NUMBER FILE

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

    // CLOSES EACH NUMBER FILE

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
    int cap = static_cast<int>(str.at(0));
    if(str.at(0) >= 48 && str.at(0) <= 57){
        arrShift = 48;
    }
    for(int i = 0; i < str.length(); i++){
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
    int num, row, col;
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
//
//void displayTitle(SDL_Plotter& g, int Font[26][15][20], int x, int y, color c)
//{
//    int num, row, col, size = 10;
//    int xOffset = 10, yOffset = 10;
//    int alpha;
//    int yStart = x;
//    int xStart = y;
//
//    for(int m = 0; m < 5; m++){
//        if(m == 0){
//            alpha = 18;
//        }
//        if(m == 1){
//            alpha = 13;
//        }
//        if(m == 2){
//            alpha = 0;
//        }
//        if(m == 3){
//            alpha = 10;
//        }
//        if(m == 4){
//            alpha = 4;
//        }
//
//        for(int y = 0; y < 20; y++){
//            for(int x = 0; x < 15; x++){
//                num = Font[alpha][x][y];
//                if(num == 1){
//                    for(int i = 0; i < size; i++){
//                        for(int j = 0; j < size; j++){
//                            g.plotPixel(xStart + xOffset + (x * size) + i,
//                                        yStart + yOffset + (y * size) + j,
//                                       c);
//                        }
//                    }
//                }
//            }
//        }
//
//        // SPACES EACH CHARACTER OUT
//
//        xStart = xStart + 200;
//    }
//
//    g.update();
//}


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

void displayHighScore(SDL_Plotter& g, int Font[26][15][20]){
    int num, row, col;
    int x = 50, y = 50, size = 1;
    int xOffset = 10, yOffset = 10;
    int alpha;
    int yStart = 0;
    int xStart = 0;

    // ITERATES THROUGH THE CHARACTERS OF "HIGHSCORE"

    for(int m = 0; m < 9; m++){
        if(m == 0){
            alpha = 7;
        }
        if(m == 1){
            alpha = 8;
        }
        if(m == 2){
            alpha = 6;
        }
        if(m == 3){
            alpha = 7;
        }
        if(m == 4){
            alpha = 18;
        }
        if(m == 5){
            alpha = 2;
        }
        if(m == 6){
            alpha = 14;
        }
        if(m == 7){
            alpha = 17;
        }
        if(m == 8){
            alpha = 4;
        }

        // PLOTS THE APPROPRIATE PIXELS FOR EACH CHARACTER

        for(int y = 0; y < 20; y++){
            for(int x = 0; x < 15; x++){
                num = Font[alpha][x][y];
                if(num == 1){
                    for(int i = 0; i < size; i++){
                        for(int j = 0; j < size; j++){
                            g.plotPixel(xStart + xOffset + (x * size) + i,
                                        yStart + yOffset + (y * size) + j,
                                        255, 255, 255);
                        }
                    }
                }
            }
        }

        // SPACES EACH CHARACTER OUT

        xStart = xStart + 20;
    }

    g.update();
}

//void displayLives(SDL_Plotter& g, int Font[26][15][20]){
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int alpha;
//    int yStart = 0;
//    int xStart = 400;
//
//    // ITERATES THROUGH THE CHARACTERS OF "LIVES"
//
//    for(int m = 0; m < 5; m++){
//        if(m == 0){
//            alpha = 11;
//        }
//        if(m == 1){
//            alpha = 8;
//        }
//        if(m == 2){
//            alpha = 21;
//        }
//        if(m == 3){
//            alpha = 4;
//        }
//        if(m == 4){
//            alpha = 18;
//        }
//
//        // PLOTS THE APPROPRIATE PIXELS FOR EACH CHARACTER
//
//        for(int y = 0; y < 20; y++){
//            for(int x = 0; x < 15; x++){
//                num = Font[alpha][x][y];
//                if(num == 1){
//                    for(int i = 0; i < size; i++){
//                        for(int j = 0; j < size; j++){
//                            g.plotPixel(xStart + xOffset + (x * size) + i,
//                                        yStart + yOffset + (y * size) + j,
//                                        255, 255, 255);
//                        }
//                    }
//                }
//            }
//        }
//
//        // SPACES EACH CHARACTER OUT
//
//        xStart = xStart + 20;
//    }
//
//    g.update();
//}
//
//void displayGameOver(SDL_Plotter& g, int Font[26][15][20]){
//    int num, row, col;
//    int x = 50, y = 50, size = 2;
//    int xOffset = 10, yOffset = 10;
//    int alpha;
//    int yStart = 350;
//    int xStart = 120;
//
//    // ITERATES THROUGH THE CHARACTERS OF "GAMEOVER"
//
//    for(int m = 0; m < 8; m++){
//        if(m == 0){
//            alpha = 6;
//        }
//        if(m == 1){
//            alpha = 0;
//        }
//        if(m == 2){
//            alpha = 12;
//        }
//        if(m == 3){
//            alpha = 4;
//        }
//        if(m == 4){
//            alpha = 14;
//        }
//        if(m == 5){
//            alpha = 21;
//        }
//        if(m == 6){
//            alpha = 4;
//        }
//        if(m == 7){
//            alpha = 17;
//        }
//
//        // PLOTS THE APPROPRIATE PIXELS FOR EACH CHARACTER
//
//        for(int y = 0; y < 20; y++){
//            for(int x = 0; x < 15; x++){
//                num = Font[alpha][x][y];
//                if(num == 1){
//                    for(int i = 0; i < size; i++){
//                        for(int j = 0; j < size; j++){
//                            g.plotPixel(xStart + xOffset + (x * size) + i,
//                                        yStart + yOffset + (y * size) + j,
//                                        255, 255, 255);
//                        }
//                    }
//                }
//            }
//        }
//
//        // SPACES EACH CHARACTER OUT
//
//        xStart = xStart + 40;
//    }
//
//    g.update();
//}
//
//void displayInstruct(SDL_Plotter& g, int Font[26][15][20])
//{
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int alpha;
//    int yStart = 450;
//    int xStart = 150;
//
//    // ITERATES THROUGH THE CHARACTERS OF "PRESS P TO START"
//
//    for(int m = 0; m < 13; m++){
//        if(m == 0){
//            alpha = 15;
//        }
//        if(m == 1){
//            alpha = 17;
//        }
//        if(m == 2){
//            alpha = 4;
//        }
//        if(m == 3){
//            alpha = 18;
//        }
//        if(m == 4){
//            alpha = 18;
//        }
//        if(m == 5){
//            alpha = 15;
//            xStart = xStart + 10;
//        }
//        if(m == 6){
//            alpha = 19;
//            xStart = xStart + 10;
//        }
//        if(m == 7){
//            alpha = 14;
//        }
//        if(m == 8){
//            alpha = 18;
//            xStart = xStart + 10;
//        }
//        if(m == 9){
//            alpha = 19;
//        }
//        if(m == 10){
//            alpha = 0;
//        }
//        if(m == 11){
//            alpha = 17;
//        }
//        if(m == 12){
//            alpha = 19;
//        }
//
//        // PLOTS THE APPROPRIATE PIXELS FOR EACH CHARACTER
//
//        for(int y = 0; y < 20; y++){
//            for(int x = 0; x < 15; x++){
//                num = Font[alpha][x][y];
//                if(num == 1){
//                    for(int i = 0; i < size; i++){
//                        for(int j = 0; j < size; j++){
//                            g.plotPixel(xStart + xOffset + (x * size) + i,
//                                        yStart + yOffset + (y * size) + j,
//                                        255, 255, 255);
//                        }
//                    }
//                }
//            }
//        }
//
//        // SPACES EACH CHARACTER OUT
//
//        xStart = xStart + 20;
//    }
//
//    g.update();
//}
//
//void display0(SDL_Plotter& g, int numArray[10][15][20],int xStartShift, int yStartShift){
//
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int yStart = 50;
//    int xStart = 120;
//
//    // PLOTS THE APPROPRIATE PIXELS FOR THE CHARACTER "0"
//
//    for(int y = 0; y < 20; y++){
//        for(int x = 0; x < 15; x++){
//            num = numArray[0][x][y];
//            if(num == 1){
//                for(int i = 0; i < size; i++){
//                    for(int j = 0; j < size; j++){
//                        g.plotPixel(xStart + xStartShift + xOffset + (x * size) + i,
//                                    yStart + yStartShift + yOffset + (y * size) + j,
//                                    255, 255, 255);
//                    }
//                }
//            }
//        }
//    }
//
//    g.update();
//}
//
//void display1(SDL_Plotter& g, int numArray[10][15][20], int xStartShift, int yStartShift){
//
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int yStart = 50;
//    int xStart = 120;
//
//    // PLOTS THE APPROPRIATE PIXELS FOR THE CHARACTER "1"
//
//    for(int y = 0; y < 20; y++){
//        for(int x = 0; x < 15; x++){
//            num = numArray[1][x][y];
//            if(num == 1){
//                for(int i = 0; i < size; i++){
//                    for(int j = 0; j < size; j++){
//                        g.plotPixel(xStart + xStartShift + xOffset + (x * size) + i,
//                                    yStart + yStartShift + yOffset + (y * size) + j,
//                                    255, 255, 255);
//                    }
//                }
//            }
//        }
//    }
//
//    g.update();
//}
//
//void display2(SDL_Plotter& g, int numArray[10][15][20], int xStartShift, int yStartShift){
//
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int yStart = 50;
//    int xStart = 120;
//
//    // PLOTS THE APPROPRIATE PIXELS FOR THE CHARACTER "2"
//
//    for(int y = 0; y < 20; y++){
//        for(int x = 0; x < 15; x++){
//            num = numArray[2][x][y];
//            if(num == 1){
//                for(int i = 0; i < size; i++){
//                    for(int j = 0; j < size; j++){
//                        g.plotPixel(xStart + xStartShift + xOffset + (x * size) + i,
//                                    yStart + yStartShift + yOffset + (y * size) + j,
//                                    255, 255, 255);
//                    }
//                }
//            }
//        }
//    }
//
//    g.update();
//}
//
//void display3(SDL_Plotter& g, int numArray[10][15][20], int xStartShift, int yStartShift){
//
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int yStart = 50;
//    int xStart = 120;
//
//    // PLOTS THE APPROPRIATE PIXELS FOR THE CHARACTER "3"
//
//    for(int y = 0; y < 20; y++){
//        for(int x = 0; x < 15; x++){
//            num = numArray[3][x][y];
//            if(num == 1){
//                for(int i = 0; i < size; i++){
//                    for(int j = 0; j < size; j++){
//                        g.plotPixel(xStart + xStartShift + xOffset + (x * size) + i,
//                                    yStart + yStartShift + yOffset + (y * size) + j,
//                                    255, 255, 255);
//                    }
//                }
//            }
//        }
//    }
//
//    g.update();
//}
//
//void display4(SDL_Plotter& g, int numArray[10][15][20], int xStartShift, int yStartShift){
//
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int yStart = 50;
//    int xStart = 120;
//
//    // PLOTS THE APPROPRIATE PIXELS FOR THE CHARACTER "4"
//
//    for(int y = 0; y < 20; y++){
//        for(int x = 0; x < 15; x++){
//            num = numArray[4][x][y];
//            if(num == 1){
//                for(int i = 0; i < size; i++){
//                    for(int j = 0; j < size; j++){
//                        g.plotPixel(xStart + xStartShift + xOffset + (x * size) + i,
//                                    yStart + yStartShift + yOffset + (y * size) + j,
//                                    255, 255, 255);
//                    }
//                }
//            }
//        }
//    }
//
//    g.update();
//}
//
//void display5(SDL_Plotter& g, int numArray[10][15][20],int xStartShift, int yStartShift){
//
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int yStart = 50;
//    int xStart = 120;
//
//    // PLOTS THE APPROPRIATE PIXELS FOR THE CHARACTER "5"
//
//    for(int y = 0; y < 20; y++){
//        for(int x = 0; x < 15; x++){
//            num = numArray[5][x][y];
//            if(num == 1){
//                for(int i = 0; i < size; i++){
//                    for(int j = 0; j < size; j++){
//                        g.plotPixel(xStart + xStartShift + xOffset + (x * size) + i,
//                                    yStart + yStartShift + yOffset + (y * size) + j,
//                                    255, 255, 255);
//                    }
//                }
//            }
//        }
//    }
//
//    g.update();
//}
//
//void display6(SDL_Plotter& g, int numArray[10][15][20], int xStartShift, int yStartShift){
//
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int yStart = 50;
//    int xStart = 120;
//
//    // PLOTS THE APPROPRIATE PIXELS FOR THE CHARACTER "6"
//
//    for(int y = 0; y < 20; y++){
//        for(int x = 0; x < 15; x++){
//            num = numArray[6][x][y];
//            if(num == 1){
//                for(int i = 0; i < size; i++){
//                    for(int j = 0; j < size; j++){
//                        g.plotPixel(xStart + xStartShift + xOffset + (x * size) + i,
//                                    yStart + yStartShift + yOffset + (y * size) + j,
//                                    255, 255, 255);
//                    }
//                }
//            }
//        }
//    }
//
//    g.update();
//}
//
//void display7(SDL_Plotter& g, int numArray[10][15][20], int xStartShift, int yStartShift){
//
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int yStart = 50;
//    int xStart = 120;
//
//    // PLOTS THE APPROPRIATE PIXELS FOR THE CHARACTER "7"
//
//    for(int y = 0; y < 20; y++){
//        for(int x = 0; x < 15; x++){
//            num = numArray[7][x][y];
//            if(num == 1){
//                for(int i = 0; i < size; i++){
//                    for(int j = 0; j < size; j++){
//                        g.plotPixel(xStart + xStartShift + xOffset + (x * size) + i,
//                                    yStart + yStartShift + yOffset + (y * size) + j,
//                                    255, 255, 255);
//                    }
//                }
//            }
//        }
//    }
//
//    g.update();
//}
//
//void display8(SDL_Plotter& g, int numArray[10][15][20], int xStartShift, int yStartShift){
//
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int yStart = 50;
//    int xStart = 120;
//
//    // PLOTS THE APPROPRIATE PIXELS FOR THE CHARACTER "8"
//
//    for(int y = 0; y < 20; y++){
//        for(int x = 0; x < 15; x++){
//            num = numArray[8][x][y];
//            if(num == 1){
//                for(int i = 0; i < size; i++){
//                    for(int j = 0; j < size; j++){
//                        g.plotPixel(xStart + xStartShift + xOffset + (x * size) + i,
//                                    yStart + yStartShift + yOffset + (y * size) + j,
//                                    255, 255, 255);
//                    }
//                }
//            }
//        }
//    }
//
//    g.update();
//}
//
//void display9(SDL_Plotter& g, int numArray[10][15][20], int xStartShift, int yStartShift){
//
//    int num, row, col;
//    int x = 50, y = 50, size = 1;
//    int xOffset = 10, yOffset = 10;
//    int yStart = 50;
//    int xStart = 120;
//
//    // PLOTS THE APPROPRIATE PIXELS FOR THE CHARACTER "9"
//
//
//    for(int y = 0; y < 20; y++){
//        for(int x = 0; x < 15; x++){
//            num = numArray[9][x][y];
//            if(num == 1){
//                for(int i = 0; i < size; i++){
//                    for(int j = 0; j < size; j++){
//                        g.plotPixel(xStart + xStartShift + xOffset + (x * size) + i,
//                                    yStart + yStartShift + yOffset + (y * size) + j,
//                                    255, 255, 255);
//                    }
//                }
//            }
//        }
//    }
//
//    g.update();
//}
//
//void displayCurrScore(SDL_Plotter& g, int numArray[10][15][20], int& score){
//
//    int xStartShift1 = 0;    // ONES PLACE POSITION
//    int xStartShift2 = 20;   // TENS PLACE POSITION
//    int yStartShift = 0;     // KEPT CONSTANT (USED FOR "displayCurrLives" FUNCTION)
//
//    // DETERMINES WHICH NUMBER TO DISPLAY FOR TENS PLACE
//
//    if(score / 10 == 0){
//        display0(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(score / 10 == 1){
//        display1(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(score / 10 == 2){
//        display2(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(score / 10 == 3){
//        display3(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(score / 10 == 4){
//        display4(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(score / 10 == 5){
//        display5(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(score / 10 == 6){
//        display6(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(score / 10 == 7){
//        display7(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(score / 10 == 8){
//        display8(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(score / 10 == 9){
//        display9(g, numArray, xStartShift1, yStartShift);
//    }
//
//    // DETERMINES WHICH NUMBER TO DISPLAY FOR ONES PLACE
//
//    if(score % 10 == 0){
//        display0(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(score % 10 == 1){
//        display1(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(score % 10 == 2){
//        display2(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(score % 10 == 3){
//        display3(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(score % 10 == 4){
//        display4(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(score % 10 == 5){
//        display5(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(score % 10 == 6){
//        display6(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(score % 10 == 7){
//        display7(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(score % 10 == 8){
//        display8(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(score % 10 == 9){
//        display9(g, numArray, xStartShift2, yStartShift);
//    }
//}
//
//void displayCurrLives(SDL_Plotter& g, int numArray[10][15][20], int& lives){
//
//    int xStartShift1 = -800;   // X POSITION
//    int yStartShift = -48;     // Y POSITION
//                               // THESE VALUES ARE SUBTRACTED FROM THE "xStart"
//                               //     and "yStart" VALUES THAT ARE SET IN EACH
//                               //     NUMBER DISPLAY FUNCTION
//
//    // DISPLAYS NUMBER OF LIVES LEFT
//
//    if(lives == 3){
//        display3(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(lives == 2){
//        display2(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(lives == 1){
//        display1(g, numArray, xStartShift1, yStartShift);
//    }
//}
//
//void displayCurrHighScore(SDL_Plotter& g, int numArray[10][15][20], int& highScore){
//
//    int xStartShift1 = 80;
//    int xStartShift2 = 100;
//    int yStartShift = -50;
//
//    // DETERMINES WHICH NUMBER TO DISPLAY FOR TENS PLACE
//
//    if(highScore / 10 == 0){
//        display0(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(highScore / 10 == 1){
//        display1(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(highScore / 10 == 2){
//        display2(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(highScore / 10 == 3){
//        display3(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(highScore / 10 == 4){
//        display4(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(highScore / 10 == 5){
//        display5(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(highScore / 10 == 6){
//        display6(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(highScore / 10 == 7){
//        display7(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(highScore / 10 == 8){
//        display8(g, numArray, xStartShift1, yStartShift);
//    }
//    else if(highScore / 10 == 9){
//        display9(g, numArray, xStartShift1, yStartShift);
//    }
//
//    // DETERMINES WHICH NUMBER TO DISPLAY FOR ONES PLACE
//
//    if(highScore % 10 == 0){
//        display0(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(highScore % 10 == 1){
//        display1(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(highScore % 10 == 2){
//        display2(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(highScore % 10 == 3){
//        display3(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(highScore % 10 == 4){
//        display4(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(highScore % 10 == 5){
//        display5(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(highScore % 10 == 6){
//        display6(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(highScore % 10 == 7){
//        display7(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(highScore % 10 == 8){
//        display8(g, numArray, xStartShift2, yStartShift);
//    }
//    else if(highScore % 10 == 9){
//        display9(g, numArray, xStartShift2, yStartShift);
//    }
//}
