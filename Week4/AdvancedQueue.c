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
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node==NULL) return -1;
    new_node->value = val;
    if(q->size==0){
        q->tail = new_node;
    } else {
        new_node->next = q->tail->next;
    }
    q->tail->next = new_node;
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
    int value = last->value;
    for (size_t i = 1 ; i < q->size; i++)
    {
        tmp = tmp->next;
    }
    tmp->next=last->next;
    q->size--;
    q->tail = (q->size==0) ? NULL : tmp;
    free(last);
    return value;
}
