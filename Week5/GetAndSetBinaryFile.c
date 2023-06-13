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
    int fd = open(filename, O_RDONLY);
    if (fd==-1) return -1;

    struct stat* stat_buff = malloc(sizeof(struct stat));
    if (fstat(fd, stat_buff)==-1) return -1;
    int size = stat_buff->st_size;
    int n = size/sizeof(int); //Nombre d'entier
    if(index>=n) return -2;

    int* numbers = mmap(NULL, size, PROT_READ, MAP_SHARED,fd, 0);
    if (numbers == MAP_FAILED) return -1;

    int result = numbers[index];
    
    if (munmap(numbers, size)==-1) return -1;
    if (close(fd)==-1) return -1;
    return result;
}

/*
 * @pre filename != NULL, index >= 0
 * @post set the element in the file {filename}
 *       at index {index} at value {value}.
 *       do nothing in case of errors
 */
void set(char *filename, int index, int value) {
    int fd = open(filename, O_RDWR);
    if (fd==-1) return;

    struct stat* stat_buff = malloc(sizeof(struct stat));
    if (fstat(fd, stat_buff)==-1) return;
    int size = stat_buff->st_size;
    int n = size/sizeof(int);
    if(index>=n) return;
    
    int *mem = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (mem == MAP_FAILED) return;

    mem[index] = value;

    if (msync(mem, size, MS_SYNC)==-1) return; //force écriture
    if (munmap(mem, size)==-1) return;
    if (close(fd)==-1) return;
}
