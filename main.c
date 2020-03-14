#include "tools/bib.h"

struct newInfo{
    int a;
    int b;
};
typedef struct newInfo newInfo;

struct List{
    const void  *info;
    struct List *next;
};
typedef struct List List;

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

List *listPop(List *theList){
    return listDeleteAt(theList, listLen(theList) - 1);
}

List *listShift(List *theList){
    return listDeleteAt(theList, 0);
}

void afficheList(List *theList){
    List *tempList;

    tempList = theList;
    printf("------------------------\n\n");
    while(tempList != NULL){
        printf("%d\n", tempList->info);
        tempList = tempList->next;
    }
    printf("------------------------\n\n");
}



int main(){

    List *newlist;
    List *item;
    newInfo info;

    info.a = 55;
    info.b = 6;

    newlist = listInit();


    newlist = listPush(newlist, &info);
    item = getItemAt(newlist, 0);
    newInfo *test;
    test = (newInfo *)item->info;
    //int a = ((newInfo *)item->info)->a;
    printf("result : %d\n", test->a);

    

    

    return 0;
}