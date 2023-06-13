#include <stdio.h>
#include <stdlib.h>
/***
 * Représente une liste chainée
*/
typedef struct node{
    char val;
    struct node *next;
} node_t;

/*
* @return: 0 if equals, negative number if @b is greater,
* and positive number otherwise
*/
int compare(char a, char b) {
    if (a==b){
        return 0;
    } else {
        return a-b;
    }
}

/*
* @value: value to be inserted. If the value is already in the list, no element is added and the list is not modified
* @fun: comparison function which defines the order relationship of the list
* @head: first node of the list, head != NULL
* @return: 0 if success, -1 otherwise
*/
int insert(node_t **head, char val, int (*cmp)(char,char)) {
    node_t* current = *head;
    node_t* previous = NULL;
    while (current!=NULL)
    {
        if(cmp(val, current->val)<0){
            node_t* new_node = malloc(sizeof(node_t));
            if(new_node==NULL) return -1;
            new_node->val = val;
            new_node->next = current;
            if(previous!=NULL){
                previous->next=new_node;
            } else {
                *head = new_node;
            }
            return 0;
        } else if(current->val==val){
            return 0; //Déjà dans la liste
        } else {
            previous = current;
            current = current->next;
        }
    }
    //Ajoute à la fin :
    node_t* new_node = malloc(sizeof(node_t));
    if(new_node==NULL) return -1;
    new_node->val = val;
    new_node->next = NULL;
    if(previous!=NULL){
        previous->next=new_node;
    } else {
        *head = new_node;
    }
    return 0;
}
