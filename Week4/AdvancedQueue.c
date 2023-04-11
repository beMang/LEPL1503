#include <stdlib.h>
#include <stdio.h>

typedef struct node{
  struct node* next;
  int value;
} node_t;

typedef struct queue{
  struct node* tail;
  int size;
} queue_t  ;

/*
* Add @val value at the head of the @q queue
*
* @val     : the value to enqueue
* @q     : the queue
*
* @return 0 if no error, -1 otherwise
*
* pre : The queue q will always be valid, you don't need to handle the NULL case.
*/
int enqueue(queue_t* q, int val){
    struct node *new = malloc(sizeof(struct node));
    if(new==NULL) return -1;
    if(q->size==0){
        struct node new_node = {NULL, val};
        *new=new_node;
        q->tail = new;
        new->next=q->tail;
    } else {
        struct node new_node = {q->tail->next, val};
        *new = new_node;
        q->tail->next = new;
    }
    q->size++;
    return 0;
}

/*
* Remove the node at the tail of the @q queue and return the value of this node
* @q         : the queue
* @return     : the value at the tail
*
* pre         : The given queue will always be valid, you do not need to handle the NULL case.
*/
int dequeue(queue_t* q){
    struct node *last = q->tail; //Fin de q
    struct node *tmp = q->tail; //Avant-dernier
    int value = tmp->value;
    for (size_t i = 1 ; i < q->size; i++)
    {
        tmp = tmp->next;
    }
    tmp->next=last->next;
    q->size--;
    if(q->size==0){
        q->tail = NULL;
    } else {
        q->tail = tmp;
    }
    free(last);
    return value;
}

void printqueue(queue_t* q){
    printf("____________________\n");
    node_t *current = q->tail->next;
    for (size_t i = 0; i < q->size; i++)
    {
        printf("%d noeud : valeur : %d \n", (int) i, current->value);
        current = current->next;
    }
    
}
