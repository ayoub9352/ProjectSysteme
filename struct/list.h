#ifndef LIST_STRUCT
#define LIST_STRUCT

    struct newInfo{
        int a;
        int b;
    };
    typedef struct newInfo newInfo;

    struct List{
        void  *info;
        struct List *next;
    };
    typedef struct List List;

#endif