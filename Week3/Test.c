#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int equal(int a, int b)
{
    return a == b;
}

int greater_or_equal(int a, int b)
{
    return a >= b;
}

int greater(int a, int b)
{
    return a > b;
}

int less_or_equal(int a, int b)
{
    return a <= b;
}

int less(int a, int b)
{
    return a < b;
}

int main(int argc, char const **argv)
{
    if (argc < 4)
        return 1;
    int a = atoi(argv[1]);
    int b = atoi(argv[3]);
    char const *expression = argv[2];

    if (strcmp(expression, "-eq")==0)
    {
        return !equal(a, b);
    }
    else if (strcmp(expression, "-ge")==0)
    {
        return !greater_or_equal(a, b);
    }
    else if (strcmp(expression, "-gt")==0)
    {
        return !greater(a, b);
    }
    else if (strcmp(expression, "-le")==0)
    {
        return !less_or_equal(a, b);
    }
    else if (strcmp(expression, "-lt")==0)
    {
        return !less(a, b);
    }
    else if (strcmp(expression, "-ne")==0)
    {
        return equal(a, b);
    }
    else
    {
        return 0;
    }
}
