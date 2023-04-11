#include <stdlib.h>
#include <stdio.h>

/**
* Structure node
*
* @next: pointer to the next node in the list, NULL if last node_t
* @value: value stored in the node
*/
typedef struct node {
  struct node *next;
  int value;
} node_t;

/**
* Structure list
*
* @first: first node of the list, NULL if list is empty
* @size: number of nodes in the list
*/
typedef struct list {
  struct node *first;
  int size;
} list_t;

/*
* Create a new node containing the value @value.
*
* @value: value stored in the node
* @next : pointer to next node, initialised to NULL.
* @return: returns the pointer to the newly created node, or NULL if an error occured.
*/
node_t *init_node(int value) {
    node_t *new = malloc(sizeof(node_t));
    if(new==NULL){
        return NULL;
    }
    node_t to_copy = {NULL,value};
    *new = to_copy;
    return new;
}

    /*
* Add a node at the head of the list @list and increment the number of nodes in the list (member `size`)
*
* @l: linked list
* @value: value to add to the list
*
* @return: 0 if success, 1 otherwise
*/
int add_node(list_t *list, int value) {
    node_t *new = init_node(value);
    if(new==NULL || list==NULL){ //Erreur
        return 1;
    }
    new->next = list->first;
    list->first = new;
    list->size ++;
    return 0;
}

void printlst(list_t *lst){
    node_t *current = lst->first;
    while (current!=NULL)
    {
        printf("%d \n", current->value);
        current = current->next;
    }
}

int main(int argc, char const *argv[])
{
    node_t node = {NULL, 3};
    list_t lst = {&node, 1};
    add_node(&lst, 5);
    add_node(&lst, 89);
    printlst(&lst);
    return 0;
}
