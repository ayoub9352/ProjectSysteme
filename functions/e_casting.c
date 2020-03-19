#include "../tools/bib.h"

char *TO_STRING(List *list, int pos){
    void *p;

    p = getItemAt(list, pos)->info;
    return (char *)p;
}