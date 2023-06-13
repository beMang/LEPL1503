#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
 * @pre file_name != NULL, name of the original file
 *      new_file_name != NULL, name of the new file (the copy)
 *
 * @post copy the contents of {file_name} to {new_file_name}.
 *       return 0 if the function terminates with success, -1 in case of errors.
 */
int copy(char *file_name, char *new_file_name)
{
    int fd1 = open(file_name, O_RDONLY);
    if (fd1 == -1) return -1;

    struct stat *stats = malloc(sizeof(struct stat));
    if (fstat(fd1, stats) == -1) return -1;
    int size = stats->st_size;

    int fd2 = open(new_file_name, O_RDWR | O_CREAT | O_TRUNC, stats->st_mode); // Nouveau fichier
    if (fd2 == -1) return -1;
    if (ftruncate(fd2, size) == -1) return -1; // Met le fichier à la bonne taille

    int *content = mmap(NULL, size, PROT_READ, MAP_SHARED, fd1, 0); // Place le premier fichier en mémoire
    if (content == MAP_FAILED) return -1;

    int *new_content = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0); // Place le premier fichier en mémoire
    if (new_content == MAP_FAILED) return -1;

    memcpy(new_content, content, size); // On copie les données

    if (msync(new_content, size, MS_SYNC) == -1) return -1; // On écrit la copie/force la copie

    // On ferme les zones mémoires ainsi que les fichiers :
    if (munmap(content, size) == -1) return -1;
    if (munmap(new_content, size) == -1) return -1;
    if (close(fd1) < 0) return -1;
    if (close(fd2) < 0) return -1;
    return 0;
}
