#ifndef BST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>

typedef struct BST_node {
    char *name;
    int MIS;
    struct BST_node *left, *right;
}BST_node;

typedef BST_node* BST;

void BST_display(BST t);
void BST_init(BST *t);
void BST_insert(BST *t, char *str, int MIS);
void BST_remove(BST *t, int MIS);
int BST_count(BST t);
BST copy(BST t);
void BST_preorder(BST t);
void BST_inorder(BST t);
void BST_postorrer(BST t);
BST mirror(BST t);
int BST_depth(BST t);
void BST_levelwise_traversal(BST t);
#endif // !BST
