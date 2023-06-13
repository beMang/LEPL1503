#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    char *name;
};

/**
* Remove the top element of the stack and return its content.
*
* @head : pointer to the top of the stack
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the stack
*/

int pop(struct node **head, char *result){
    if(head==NULL || *head==NULL || strcpy(result, (*head)->name)==NULL) return 1;
    struct node* tmp = *head;
    *head = (*head)->next;
    free(tmp->name);
    free(tmp);
    return 0;
}

/**
* Add @name at the "top" of the stack.
*
* @head : pointer to the top of the stack
* @name : the string to be placed in the element at the top of the stack
*
* @return 0 if no error, 1 otherwise
*/

int push(struct node **head, const char *value){
    if(head==NULL || value==NULL) return 1;
    struct node* new = malloc(sizeof(struct node));
    if (new==NULL) return 1;
    new->next = *head;
    new->name = malloc(sizeof(char)*(1+strlen(value)));
    if(new->name==NULL) return 1;
    strcpy(new->name, value);
    *head = new;
    return 0;
}
