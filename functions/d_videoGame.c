#include "../tools/bib.h"


List *setUpList(){
    List *list;

    list = listInit();

    list = listAdd(list, "Item A");
    list = listAdd(list, "Item B");
    list = listAdd(list, "Item C");
    list = listAdd(list, "Item D");
    list = listAdd(list, "Item E");

    return list;
}

void setBackground(int x, int y, int width, int height, char *color){
    int a;
    int b;

    heightLightColor(color);
    CursorP(x, y);
    for(a = 0; a < height; a++){
        for(b = 0; b < width; b++){
            printf(" ");
        }
        CursorP(x, y + a);
    }
    heightLightColor(RESET_HL);
}

void setUpMenu(int x, int y){
    char    c;
    int     i;
    int     j;
    List    *list;
    int     length;

    //config
    char *textColor = ANSI_COLOR_RESET;
    char *textHeightLightColor = GREEN_HL;
    char *backGroundColor = LIGHTBLUE_HL;
    int width = 60;
    int height = 15;

    i = 0;
    list = setUpList();
    length = listLen(list);
    setBackground(x, y, width, height, backGroundColor);
    while(1){

        //display List
        for(j = 0; j < length; j++){
            CursorP(x + width / 2 - 3, y + height / 2 - length / 2 + j);
            if(i == j){
                heightLightColor(textHeightLightColor);
                changeTextColor(textColor);
                printf( "%s", TO_STRING(list, j) );
                heightLightColor(backGroundColor);
            }else{
                printf( "%s", TO_STRING(list, j) );
            }  
        }

        //get input
        c = getch();
        switch(c){
            case press_down :
                i++;
                i = i % length;
                break;
            case press_up :
                i--;
                if(i < 0){i = length - 1;}
                break;
        }
        if(c == press_enter){
            heightLightColor(RESET_HL);
            break;
        }
    }
}