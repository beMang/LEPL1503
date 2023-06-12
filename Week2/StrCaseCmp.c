#include <stdio.h>

int strcasecmp(const char *s1, const char *s2) {
    while(*s1!='\0' && *s2!='\0'){
        int c1 = (char) *s1;
        int c2 = (char) *s2;

        //Lower the char
        if(65<=c1 && c1<=90){
            c1+=32;
        }
        if(65<=c2 && c2<=90){
            c2+=32;
        }

        if(c1<c2){
            return -1;
        }
        if (c1>c2){
            return 1;
        }
        s1++;
        s2++;
    }
    if (*s1==*s2){
        return 0;
    } else if(*s1=='\0'){
        return -1;
    } else {
        return 1;
    }
}
