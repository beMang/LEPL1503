#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

    if (expression == "-eq")
    {
        return equal(a, b);
    }
    else if (expression == "-ge")
    {
        return greater_or_equal(a, b);
    }
    else if (expression = "-gt")
    {
        return greater(a, b);
    }
    else if (expression == "-le")
    {
        return less_or_equal(a, b);
    }
    else if (expression == "-lt")
    {
        return less_or_equal(a, b);
    }
    else if (expression == "-ne")
    {
        return !equal(a, b);
    }
    else
    {
        return 0;
    }
}
