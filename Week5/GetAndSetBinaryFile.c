#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
 #include <sys/types.h>
#include <sys/stat.h>

/*
 * @pre filename != NULL, index >= 0
 * @post return the integer at the index {index}
 *       of the array in the file {filename}.
 *       return -1 in case of error.
 *       return -2 if index >= length of array.
 */
int get(char *filename, int index) {
    int error = -1;
    int fd = open(filename, O_RDONLY);
    if (fd==-1) return error;

    struct stat* stat_buff = malloc(sizeof(struct stat));
    if (fstat(fd, stat_buff)==-1) return error;
    int size = stat_buff->st_size;
    int n = size/sizeof(int);
    if(index>=n) return -2;

    int* numbers = mmap(NULL, size, PROT_READ, MAP_SHARED,fd, 0); //Place le fichier en mémoire
    if (numbers == MAP_FAILED) return error;

    int result = numbers[index];
    
    if (munmap(numbers, size)==-1) return error;
    if (close(fd) < 0) return error;
    return result;
}

/*
 * @pre filename != NULL, index >= 0
 * @post set the element in the file {filename}
 *       at index {index} at value {value}.
 *       do nothing in case of errors
 */
void set(char *filename, int index, int value) {
    int fd = open(filename, O_RDWR); //On ouvre le fichier, ne pas oublier les permissions
    if (fd==-1) return;

    struct stat* stat_buff = malloc(sizeof(struct stat));
    if (fstat(fd, stat_buff)==-1) return;
    int size = stat_buff->st_size;
    int n = size/sizeof(int);
    if(index>=n) return;
    
    int *mem = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); //On place le fichier directement en mémoire
    if (mem == MAP_FAILED) printf("ça pète\n");

    mem[index] = value;

    if (msync(mem, size, MS_SYNC)==-1) return; //On force à écrire sur le disque

    if (munmap(mem, size)==-1) return; //On ferme la zone mémoire allouée
    if (close(fd) < 0) return;
}
