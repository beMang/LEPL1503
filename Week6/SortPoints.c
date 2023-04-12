#include <stdio.h>
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
    if (fd == -1)
        return -1;

    struct stat *stats = malloc(sizeof(struct stat));
    if (fstat(fd, stats) == -1){
        close(fd);
        return -5;
    }

    int size = stats->st_size;
    int n = size/sizeof(points_t);

    points_t* content = (points_t*) mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); // Place le premier fichier en mémoire
    if (content == MAP_FAILED){
        close(fd);
        return -2;
    }

    //Average :
    points_t* current = content;
    for (size_t i = 0; i < n; i++)
    {
        float average = (current->LEPL1103 + current->LEPL1108 + current->LEPL1203 + current->LEPL1302 + current->LEPL1402)/5;
        current->average = average;
        current++;
    }
    
    //Then sort the arrray :
    qsort(content, n, sizeof(points_t), compar);

    //On force/sauve les modifs : 
    if (msync(content, size, MS_SYNC) == -1){
        munmap(content, size);
        close(fd);
        return -4;
    }

    // On ferme les zones mémoires ainsi que les fichiers :
    if (munmap(content, size) == -1)
        return -3;
    if (close(fd) < 0)
        return -6;
    return 0;
}