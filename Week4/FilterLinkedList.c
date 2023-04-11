#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
    if (head == NULL)
    {
        return NULL;
    }
    struct node *copy = malloc(sizeof(struct node));
    if (copy == NULL)
    {
        return NULL;
    }
    memcpy(copy, head, sizeof(struct node));
    if (head->next != NULL)
    {
        copy->next = pair_filter(head->next->next);
    }
    return copy;
}

void print_list(struct node *head)
{
    if (head != NULL)
    {
        printf("%s\n", head->name);
        print_list(head->next);
    }
}

int main(int argc, char const *argv[])
{
    struct node test = {NULL, 4, "4ème"};
    struct node test2 = {&test, 3, "3ème"};
    struct node test3 = {&test2, 2, "2ème"};
    struct node test4 = {&test3, 1, "1ème"};
    struct node test5 = {&test4, 0, "0ème"};

    print_list(&test5);
    struct node *ptr = pair_filter(&test5);
    print_list(ptr);
    return 0;
}
