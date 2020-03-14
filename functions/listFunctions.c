#include "../tools/bib.h"

List *listInit(){
    return NULL;
}

int listLen(List *theList){
    List *tempList;
    int i;

    tempList = theList;
    i = 0;
    while(tempList != NULL){
        tempList = tempList->next;
        i++;
    }
    return i;
}

List *getItemAt(List *theList, int pos){
    List *theItem;
    int i;

    if(pos >= 0 && pos < listLen(theList)){
        theItem = theList;
        i = 0;
        while(i < pos){
            theItem = theItem->next;
            i++;
        }
    }else{
        newError("index out of bound list at getItem function");
    }
    return (theItem);
}

List *listAddAt(List *theList, void *info, int pos){
    List *newItem;
    List *tempList;

    if(pos >= 0 && pos <= listLen(theList)){
        //creat new item List
        newItem = malloc(sizeof(newItem));
        newItem->info = malloc(sizeof(info));
        newItem->info = info;
        newItem->next = NULL;
        //add new Item
        if(pos == 0){
            newItem->next = theList;
            theList = newItem;
        }else{
            tempList = getItemAt(theList, pos - 1);
            newItem->next = tempList->next;
            tempList->next = newItem;
        }
    }else{
        newError("index out of bound list at listAddAt function");
    }
    
    return theList;
}

List *listDeleteAt(List *theList, int pos){
    List *deletedItem;
    List *tempList;

    if(pos >= 0 && pos < listLen(theList)){
        if(pos == 0){
            tempList = theList;
            theList = theList->next;
            free(tempList);
        }else{
            tempList = getItemAt(theList, pos - 1);
            deletedItem = tempList->next;
            tempList->next = deletedItem->next;
            free(deletedItem);
        }
    }else{
        newError("index out of bound at listDeleteAt function");
    }
    return theList;
}

//--------------------------------------------------------------
//add item to the end
//push add element to the front of the list

List *listAdd(List *theList, void *info){
    List *newList;

    newList = listAddAt(theList, info, listLen(theList));
    return newList;
}

List *listPush(List *theList, void *info){
    List *newList;

    newList = listAddAt(theList, info, 0);
    return newList;
}

//pop item (delete item in the end)
//shift item (delete the first element)

List *listPop(List *theList){
    return listDeleteAt(theList, listLen(theList) - 1);
}

List *listShift(List *theList){
    return listDeleteAt(theList, 0);
}
