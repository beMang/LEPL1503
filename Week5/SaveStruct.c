#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

typedef struct point
{
    int x;
    int y;
    int z;
} point_t;

/*
 * @pre pt != NULL, pointer to the first point_t in the array
 *      size > 0, the length of the array.
 *      filename != NULL
 * @post writes the array of point_t in the file.
 *       return 0 is everything worked correctly
 *       -1 if open() failed.
 *       -2 if close() failed.
 *       -3 if mmap() failed.
 *       -4 if munmap() failed.
 *       -5 if msync() failed.
 *       -6 if ftruncate() failed.
 *
 */
int save(point_t *pt, int size, char *filename)
{
    int needed = size * sizeof(point_t);
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600); //On ouvre le fichier, ne pas oublier les permissions
    if (fd==-1) return -1;

    if(ftruncate(fd, size*sizeof(point_t))==-1) return -6; //Met le fichier à la bonne taille
    point_t *mem = mmap(NULL, needed, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); //On place le fichier directement en mémoire
    if (mem == MAP_FAILED) return -3;

    memcpy(mem, pt, needed); //On modifie la zone mémoire
    if (msync(mem, needed, MS_SYNC)==-1) return -5; //On force à écrire sur le disque

    if (munmap(mem, needed)==-1) return -4; //On ferme la zone mémoire allouée
    if (close(fd) < 0) return -2;
    return 0;
}
