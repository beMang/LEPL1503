#include <stdlib.h>

/**
 * @brief calcule n! (de façon récursive terminale)
 */
int factorial_helper(int n, int acc)
{
    return (n<=1) ? acc : factorial_helper(n-1, n*acc);
}

int factorial(int n){
    return factorial_helper(n, 1);
}

//Factoriel plus simple mais pas récursif terminal :
int factorial_not_recursive_terminal(int n){
    int result = 1;
    for (size_t i = 2; i <= n; i++)
    {
        result = result*i;
    }
    return result;
}