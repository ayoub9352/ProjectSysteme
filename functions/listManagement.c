#include "../tools/bib.h"

List *listInit(){
    return NULL;
}

int listLen(List *list){
    List *tempList;
    int i;

    i = 0;
    tempList = list;
    while(tempList != NULL){
        i++;
        tempList = tempList->next;
    }
    return i;
}

List *listGetAt(List *list, int pos){
    List *listTemp;
    int i;

    if( pos >= 0 && pos <= listLen(list) ){
        listTemp = list;
        i = 0;
        while(i < pos){
            listTemp = listTemp->next;
            i++;
        }
    }else{
        newError("index out of bound list at getItem function");
    }
    return listTemp;
}

List *listAddAt(List *list, void *info, int pos){
    List *newItem;
    List *currentItem;


    if(pos >= 0 && pos <= listLen(list)){
        newItem = malloc(sizeof(List));
        newItem->info = malloc(sizeof(info));
        newItem->info = info;
        newItem->next = NULL;
        if(pos != 0){
            currentItem = listGetAt(list, pos - 1);
            newItem->next = currentItem->next;
            currentItem->next = newItem;
        }
        else{
            newItem->next = list;
            list = newItem;
        }
    }else{
        newError("index out of bound list at getItem function");
    }
    return list;
}

List *listDeleteAt(List *list, int pos){
    List *currentItem;
    List *deletedItem;
    List *listTemp;

    if(pos >= 0 && pos <= listLen(list)){
        if(pos != 0){
            currentItem = listGetAt(list, pos - 1);
            deletedItem = currentItem->next;
            currentItem->next = deletedItem->next;
            free(deletedItem);
        }else{
            listTemp = list->next;
            free(list);
            list = listTemp;
        }
    }else{
        newError("index out of bound list at getItem function");
    }
    return list;
}

 /*----------------------------------------------------------*/

List *listAdd(List *list, void *info){
    return listAddAt(list, info, listLen(list));
}

List *listPush(List *list, void *info){
    return listAddAt(list, info, 0);
}

List *listPop(List *list){
    return listDeleteAt(list, listLen(list) - 1);
}

List *listShift(List *list){
    return listDeleteAt(list, 0);
}