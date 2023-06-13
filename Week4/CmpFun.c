#include <stdlib.h>
#include <stdio.h>

int cmp_func(int (*f1)(int), int (*f2)(int)){
    for (size_t i = 0; i < __INT8_MAX__; i++)
    {
        if((*f1)(i)!=(*f2)(i)){
            return 0;
        }
    }
    return 1;
}

int f1(int test){
    return test;
}

int f2(int test){
    return test +1;
}

int main(int argc, char const *argv[])
{
    int result = cmp_func(&f1, &f2);
    printf("%d", result);
    return 0;
}
