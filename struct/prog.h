#ifndef PROG_STRUCT
#define PROG_STRUCT

    //programme info
    struct Programme{
        char *name;
        int arrive;
        int exucution;
        int priority;
    };
    typedef struct Programme prog;

    //list programme -> BCP
    struct ListProg{
        prog prog;
        struct ListProg *next;
        //struct ListProg *end;
    };
    typedef struct ListProg listProg;

#endif