#include <stdlib.h>

void *calloc2(size_t nmemb, size_t size) {
    if(size<1 || nmemb<1) return NULL;
    void* result = malloc(size*nmemb);
    if(result==NULL) return NULL;

    for (size_t i = 0; i < nmemb; i++)
    {
        ((char *)result)[i] = 0;
    }
    return result;
}