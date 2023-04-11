#include <stdio.h>
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
    if (head==NULL ||*head==NULL || strcpy(result, (*head)->name) == NULL){
        return 1;
    }
    struct node *tmp = *head;
    free((*head)->name);
    *head = (*head)->next;
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
    char *copy = malloc(sizeof(char)*(strlen(value)+1));
    if(copy==NULL || head==NULL){
        return 1;
    }
    strcpy(copy, value);
    struct node new_node = {*head, copy};
    struct node *new_ptr = (struct node *) malloc(sizeof(struct node));
    if(new_ptr==NULL){
        return 1;
    }
    if (new_ptr==NULL){
        return 1;
    }
    *new_ptr = new_node;
    *head = new_ptr;
    return 0;
}

int main(int argc, char const *argv[])
{
    struct node first = {NULL, "allo"};
    if(first.next==NULL){
        printf("hey");
    }
    struct node *ptr1 = &first;
    struct node **head = &ptr1;
    if((*head)->next == NULL){
        printf("Bonjour");
    }
    char *result = malloc(10*sizeof(char));
    char result2[100];
    push(head, "yolo");
    pop(head, result);
    pop(head,result2);
    printf("%s et %s \n", (*head)->name, result);
    printf("%s", result2);
    return 0;
}
