#include <stdio.h>

int f()
{
        int a = 1252;
        printf("%d\n", a);
        return a;
}

int main(int argc, const char *argv[])
{
        return f(); // On s'attend à ce que le programme imprime 1252\n dans le terminal
}

// -Wall permet d'afficher les warnings
// -Werror permet d'afficher certains erreurs
// $? permet d'accéder à la valeur de retour dans le shell