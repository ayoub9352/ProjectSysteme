#ifndef LIST_STRUCT
#define LIST_STRUCT

    struct newType{
    int i;
    int j;
    };
    typedef struct newType newType;

    struct List{
        void  *info;
        struct List *next;
    };
    typedef struct List List;

#endif