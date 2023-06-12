#include <stdlib.h>

/*
* Node has a value, @value, and two children, @left and @right.
* All the children of @left and itself have a smaller value than the node and all the children of @right and itself have a larger value than node
*/
typedef struct node{
    int value;
    struct node* left; // to smaller values
    struct node* right; // to larger values
} node_t;


typedef struct bt{
    struct node* root;
} bt_t;

int contain_helper(struct node *node, int value){
    if(node==NULL) return 0;
    if (node->value==value){
        return 1;
    } else {
        return (value<node->value) ? contain_helper(node->left, value) : contain_helper(node->right, value);
    }
}
/*
* Return 1 if there is a node containing @value in @tree and 0 otherwise.
*/
int contains(bt_t* tree, int value){
    if(tree==NULL) return 0;
    return contain_helper(tree->root, value);
}