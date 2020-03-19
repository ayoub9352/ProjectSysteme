#include "../tools/bib.h"

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





