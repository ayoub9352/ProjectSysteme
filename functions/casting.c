#include "../tools/bib.h"

char *TO_STRING(List *list, int pos){
    void *p;

    p = listGetAt(list, pos)->info;
    return (char *)p;
}

newType *TO_NEWTYPE(List *list, int pos){
    newType *item;

    item = (newType *)(listGetAt(list, pos)->info);
    return item;
}