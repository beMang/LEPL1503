#include <pthread.h>

/*
* Function used to protect a global variable used in the function inc().
*
* @inc : the function that must be called in critical (= protected) section
* @nb : the number of times the function inc() has to be called
* @mutex : an initialised mutex that has to be used for the protection
*
* @return 0 if no error, -1 otherwise
*/
int protect(void inc(void), int nb, pthread_mutex_t* mutex){
    for (size_t i = 0; i < nb; i++)
    {
        int err = pthread_mutex_lock(mutex);
        if(err!=0) return -1;
        inc();
        err = pthread_mutex_unlock(mutex);
        if(err!=0) return -1;
    }
    return 0;
}