#include <stdio.h>

char *strcat2(char *dest, const char *src)
{
    char *result = dest;
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

int main(int argc, char const *argv[])
{
    char s[20] = "Adrien";
    strcat2(s, "afjdklm");
    printf("%s\n", s);
}
