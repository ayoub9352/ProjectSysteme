#include "../tools/bib.h"

void newError(char *message){
    printf("ERROR : %s\n", message);
    exit(0);
}

void changeColorText(char *color){
    printf(color);
}

void changeHeightLight(char *color){
    printf(color);
}

void CursorP(int x,int y){
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void printAtPos(int x, int y ,char *message){
    CursorP(x, y);
    printf("%s", message);
}