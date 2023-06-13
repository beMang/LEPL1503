#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *next;
    int id;
    char name[20];
};

/* pair_filter
 * Make a copy of the linked list starting at head,
 * only taking the elements with an even index
 *
 * @head : head of a linked list, possibly NULL
 * @return: pointer to the filtered linked list, return NULL if error or if head == NULL
 */
struct node *pair_filter(struct node *head)
{
    if (head == NULL) return NULL;
    struct node *copy = malloc(sizeof(struct node));
    if (copy == NULL) return NULL;
    memcpy(copy, head, sizeof(struct node));
    if (head->next != NULL) copy->next = pair_filter(head->next->next);
    return copy;
}
