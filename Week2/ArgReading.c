#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {
        if(i%2!=0){
            if(i<argc-2){
                printf("%s ", *argv);
            } else {
                printf("%s", *argv);
            }
        }
        argv++;
    }
    printf("\n");
    
    return 0;
}
