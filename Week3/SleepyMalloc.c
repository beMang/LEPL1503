#include <stdio.h>
#include <stdlib.h>

/* Wrapper to the malloc system call.
 * If malloc fails, sleep for 5 seconds, and then try again.
 * If malloc failed 10 times in a row, return NULL.
 */
void *sleepy_malloc(size_t s) {
    int counter = 0;
    while (counter<10)
    {
        void *a = malloc(s);
        if (a!=NULL){
            return a;
        } else {
            counter++;
            sleep(5);
        }
    }
    return NULL;
}