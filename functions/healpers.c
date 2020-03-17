#include "../tools/bib.h"

void newError(const char *message){
    
    printf("ERROR : %s\n", message);
    exit(0);
}

int lengthOfInt(long long x){
    int r;

    if(x == 0){
        return 1;
    }else{
        r = 0;
        while(x != 0){
            x = x / 10;
            r++;
        }
        return r;
    }
}

char *intToString(long long x){
    int r;
    int i;
    char *result;

    if(x >= -2147483648 && x <= 21474836487){
        r = lengthOfInt(x);
        result = malloc(r + 1);
        i = 0;
        while(i < r){
            result[r - i - 1] = (x % 10) + '0';
            x = x / 10;
            i++;
        }
        result[r] = '\0';
        return result;
    }else{
        newError("the number is too big");
    }
    return NULL;
}