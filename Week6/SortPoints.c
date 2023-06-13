#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct points {
    int NOMA;
    float LEPL1103;
    float LEPL1203;
    float LEPL1108;
    float LEPL1302;
    float LEPL1402;
    float average;
} points_t;

/*
* Function used to compare two structures based on their averages.
*
* @s1 : a pointer to the first structure
* @s2 : a pointer to the second structure
*
* @return an integer less than, equal to, or greater than zero if the first argument is considered to be
*        respectively less than, equal to, or greater than the second
*/
int compar(const void* s1, const void* s2){
    float a1 = ((points_t*) s1)->average;
    float a2 = ((points_t*) s2)->average;
    if(a2==a1){
        return 0;
    } else if(a1<a2){
        return -1;
    } else {
        return 1;
    }
}

/*
* Function used to update the file with the structures stored in it
*
* @filename : the path indicating where to find the file (!= NULL)
*
* @return 0 if no error
*        -1 if open failed
*        -2 if mmap failed
*        -3 if munmap failed
*        -4 if msync failed
*        -5 if fstat failed
*        -6 if close failed
*/
int sort(char* filename){
    int fd = open(filename, O_RDWR);
    if (fd==-1) return -1;

    struct stat* stats = malloc(sizeof(struct stat));
    if (fstat(fd, stats)==-1) {
        close(fd);
        return -5;
    }
    int size = stats->st_size;

    struct points* datas = (points_t*) mmap(NULL, size, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0); //flags pour écrire et lire + cast pour le bon type
    if (datas==MAP_FAILED) {
        close(fd);
        return -2;
    }

    int n = size/sizeof(points_t);
    for (size_t i = 0; i < n; i++)
    {
        datas[i].average = (datas[i].LEPL1103 + datas[i].LEPL1108 + datas[i].LEPL1203 + datas[i].LEPL1302 + datas[i].LEPL1402)/5;
    }
    
    qsort(datas, n, sizeof(points_t), compar);
    if (msync(datas, size, MS_SYNC)==-1) {
        munmap(datas, size);
        close(fd);
        return -4;
    }
    if(munmap(datas, size)==-1) {
        close(fd);
        return -3;}
    if(close(fd)==-1) return -6;
    return 0;
}