#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*
* Creates a buffer that has the same size as src, and copies the content of src to this buffer.
*
* @src: string to be copied
* @return: return pointer. if src == NULL or in case of error, return NULL
*
* Remember that strings are terminated with '\0' and that strlen("abc") returns 3 even if 4 bytes are required to store this string.
*/
char *buf_strcpy(const char *src) {
    int len = strlen(src);
    char *str = malloc(sizeof(char)*(len+1)) ; //Use malloc to create the buffer
    if(str==NULL){
        return NULL;
    }
    while (*src!='\0')
    {
        *str = *src;
        str++;
        src++;
    }
    *str = '\0';
    return str - len;
}

int main(int argc, char const *argv[])
{
    char test[] = "adrien";
    printf("%s", buf_strcpy(test));
    return 0;
}
