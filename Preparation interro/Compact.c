#include <stdio.h>
#include <stdlib.h>

struct set
{
    struct node *first; // pointeur vers le premier node
    int n;              // nombre total d'éléments (pas nécessairement distincts) dans l'ensemble
};

struct node
{
    double real;       // partie réelle
    double img;        // partie imaginaire
    int count;         // nombre d'éléments ayant cette valeur
    struct node *next; // pointeur vers le noeud suivant
};

/*
 * @pre set!=NULL
 * @post le nombre complexe (real,img) a été correctement
 *       ajouté à l'ensemble set. La variable n de cet
 *       ensemble contient à tout moment la quantité de
 *       nombres complexes dans l'ensemble (qui est équivalente à
 *       la somme des count de tous les éléments de la liste chainée).
 *       La fonction retourne la quantité de nombres complexes dans
 *       l'ensemble . En cas d'erreur, retourne -1.
 */
int add(double real, double img, struct set *set)
{
    if (set->first==NULL)
    {
        set->first = malloc(sizeof(struct node));
        if(set->first==NULL) return -1;
        set->first->real = real;
        set->first->img = img;
        set->first->count = 1;
        set->first->next=NULL;
        set->n = 1;
        return 0;
    }
    struct node* current = set->first;
    while (current!=NULL)
    {
        if (current->img==img && current->real==real)
        {
            current->count++;
            set->n++;
            return 0;
        } else {
            if (current->next==NULL) break; //Pour garder le dernier noeud
        }
        current=current->next;
    }
    current->next = malloc(sizeof(struct node));
    if(current->next==NULL) return -1;
    current->next->real = real;
    current->next->img = img;
    current->next->count = 1;
    current->next->next=NULL;
    set->n++;
    return 0;
}

void display_set(struct set *set){
    printf("______________________________\n");
    printf("Taille de l'ensemble : %d \n", set->n);
    if (set->n==0 || set->first==NULL) printf("Ensemble vide\n");
    
    struct node* current = set->first;
    while (current!=NULL)
    {
        printf("x = %f + %f j - count : %d \n", current->real, current->img, current->count);
        current = current->next;
    }
}

int main(int argc, char const *argv[])
{
    struct set set; set.n = 0; set.first = NULL;
    display_set(&set);
    add(2.3,2.2,&set);
    display_set(&set);
    add(2.3,2.2,&set);
    display_set(&set);
    add(2.3,2.3,&set);
    display_set(&set);
    add(2.3,2.3,&set);
    display_set(&set);
    return 0;
}