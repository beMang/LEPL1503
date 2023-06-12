#include <stdio.h>

struct fract_t
{
    int num;
    int denum;
};

void swap(struct fract_t *a, struct fract_t *b)
{
    struct fract_t temp = *b;
    *b = *a;
    *a = temp;
}
