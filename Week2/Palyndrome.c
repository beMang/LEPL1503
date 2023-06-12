#include <string.h>
#include <stdio.h>

/*
* @return: returns true (1) if str is a palindrome, -1 if str is NULL, otherwise false (0).
*/
int pal(char *str) {
    if (str==NULL) return -1;
    int len = strlen(str);
    if (len==0) return 1;

    char* left = str;
    char* right = str+len-1;

    while (*left!='\0')
    {
        while (*left==32) left++;
        while (*right==32) right--;
        if (*right!=*left) {
            return 0;
        } else {
            right--;
            left++;
            if (right==left) return 1; //Quand on est au milieu on a déjà tout vérifié
        }
    }
}
