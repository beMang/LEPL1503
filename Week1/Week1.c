#include <stdio.h>
#include <stdlib.h>

int absval(int i)
{
    if (i < 0)
    {
        return -i;
    }
    else
    {
        return i;
    }
}

int factorial(int n)
{
    int result = 1;
    for (size_t i = 2; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}

/* tab_find

@tab : an array of int
@len : the number of int in tab
@elem : the elem looked for
@return : return the index at which elem is found, else returns -1 if not found. */
int tab_find(int tab[], int len, int elem)
{
    for (size_t i = 0; i < len; i++)
    {
        if (tab[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        printf("%s", argv[1]);
        if (argv[1] == "f")
        {
            printf("Factorial");
        }
        printf("Valeur absolue de %i : \n", atoi(argv[1]));
        printf("%i \n", absval(atoi(argv[1])));
    }
    else
    {
        printf("Pas d'argument\n");
    }
    return 0;
}
