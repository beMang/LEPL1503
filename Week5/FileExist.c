#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * @pre filename != NULL
 * @post return 0 if the file {filename} exist. -1 Otherwise.
 */
int file_exists(char *filename)
{
    int desc = open(filename, O_RDONLY);
    if (desc==-1){

        return -1;
    }
    close(desc);
    return 0;
}
