#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
 #include <sys/types.h>
#include <sys/stat.h>

/*
 * @pre filename != NULL, name of the file
 * @post returns the sum of all integers stored in the binary file.
 *       return -1 if the file can not be open.
 *       return -2 if the file can not be closed.
 *       return -3 if mmap() fails.
 *       return -4 if munmap() fails.
 *       return -5 if fstat() fails.
 */
int sum_file(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd==-1) return -1;

    struct stat* stat_buff = malloc(sizeof(struct stat));
    if (fstat(fd, stat_buff)==-1) return -5;
    int size = stat_buff->st_size;
    if(size==0){ //Si le fichier ne contient aucun chiffre on s'arrête
        if (close(fd) < 0) return -2;
        return 0;
    }

    int* numbers = mmap(filename, size, PROT_READ, MAP_SHARED,fd, 0); //Place le fichier en mémoire
    if (numbers == MAP_FAILED) return -3;

    int sum = 0;
    for (size_t i = 0; i < size/sizeof(int); i++)
    {
        sum+=numbers[i];
    }
    
    if (munmap(numbers, size)==-1) return -4;
    if (close(fd) < 0) return -2;
    return sum;
}
