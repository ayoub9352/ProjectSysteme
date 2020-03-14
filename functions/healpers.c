#include "../tools/bib.h"

void newError(char *message){
    int i;

    i = 0;
    while(message[i]){
        write(2, &message[i] , 1);
        i++;
    }
    exit(0);
}