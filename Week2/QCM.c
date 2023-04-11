#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int tab [4];
    int lenght = 4;
    for (size_t i = 0; i < lenght; i++)
    {
        tab[i] = i;
    }
    
    unsigned int* ptr = tab;
    printf("%s\n", &tab);
    for (size_t i = 0; i < 6; i++)
    {
        printf("%d\n", *ptr);
        ptr++;
    }
    
}
