#include "../tools/bib.h"

//prog
//listProg


prog makeProg(char *name, int arrive, int exucution, int priority){
    prog newProg;

    newProg.name = name;
    newProg.arrive = arrive;
    newProg.exucution = exucution;
    newProg.priority = priority;

    return newProg;
}


void afficheProg(prog theProg){
    printf("le nom du programme : %s\n", theProg.name);
    printf("la date d'arrive : %d\n", theProg.arrive);
    printf("la duree d'exucution : %d\n", theProg.exucution);
    printf("la priorite du programme : %d\n", theProg.priority);
}


void afficheListProg(listProg *List){
    listProg *tempListProg;

    printf("SADFAS0");
    tempListProg = List;
    while(tempListProg != NULL){
        afficheProg(tempListProg->prog);
        tempListProg = tempListProg->next;
    }
}

listProg *newListProg(){
    return NULL;
}

int lenList(listProg *theList){
    int i;
    listProg *tempList;

    tempList = theList;
    i = 0;
    while(tempList != NULL){
        tempList = tempList->next;
    }
    return i;
}
/*
listProg *addAtNewProg(listProg *theList, prog *newProg, int pos){
    listProg *newItem;
    listProg *tempList;
    listProg *sTempList;
    int length;
    int i;

    length = lenList(listProg);
    if(pos >= 0 && pos < length){
        newItem->prog = newProg;
        newItem->next = NULL;

        if(pos == 0){
            newItem->next = theList;
            theList = newItem;
        }else{
            tempList = theList;
            for(i = 0; i < pos - 1; i++){
                tempList = tempList->next;
            }
            if(pos == length - 1){
                tempList->next = newItem;
            }else{
                sTempList = tempList->next;
                tempList->next = newItem;
                newItem->next = sTempList;
            }
        }
    }else{
        newError("ERROR : out of index list at (addAtNewProg)");
    }
    return (listProg);
}
*/
