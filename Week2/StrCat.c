#include <stdio.h>

char *strcat2(char *dest, const char *src)
{
    char *result = dest; //On garde un pointeur vers le début de la chaine de caractère
    while (*dest != '\0')
    {
        dest++;
    }
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return result;
}

int strlen(const char *s)
{
    int i = 0;
    while (*s != '\0')
    {
        s++;
        i++;
    }
    return i;
}
