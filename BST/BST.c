#include "BST.h"
#include <math.h>
#include "../../list/list.h"

void BST_init(BST *t){
    *t = NULL;
}

void BST_insert(BST *t, char *str, int MIS){
    if(*t == NULL)
    {
        BST_node *n = (BST_node *) malloc(sizeof(BST_node));
        n->right = NULL;
        n->left = NULL;
        n->MIS = MIS;
        n->name = (char *)malloc(sizeof(char) * strlen(str));
        *t = n;
        strcpy(n->name, str);
        return ;
    }
    if((*t)->MIS < MIS)
        BST_insert(&((*t)->right), str, MIS);
    else if((*t)->MIS > MIS)
        BST_insert(&((*t)->left), str, MIS);
    else {
        return ;
    }
}

void levelwise2(BST t, list *arr, int depth, int array[], int maxDepth);

void BST_levelwise_traversal(BST t)
{
    if(t == NULL)
        return ;
    int Depth = BST_depth(t);
    list arr[Depth + 2];
    for(int i = 0 ; i < Depth + 2; i++)
    { 
        list_init(&arr[i]);
        int power = pow(2, i);
        // printf("function brok on power level : %d\n", i);
        for(int j = 0; j < power; j++)
            list_add_end(&arr[i], 0);
    }
    int array[Depth + 2];
    // printf("array init function reached\n");
    for(int i = 0; i < Depth + 2; i++)
        array[i] = 1;
    // printf("levelwise2 function reached\n");
    levelwise2(t, arr, 0, array, Depth);
    for(int i = 0; i < Depth + 1; i++)
    {
        printf("level %d is:\n", i);
        list_display(arr[i]);
        list_destroy(&arr[i]);
    }
    // printf("BST_levelwise_traversal complete\n");
}

void levelwise2(BST t, list *arr, int depth, int array[], int maxDepth)
{
    if(t == NULL)
    {
        // printf("value of array depth is %d value of depth is :%d in null\n", array[depth], depth);
        list_remove_pos(&arr[depth], array[depth]);
        // printf("segfaul not in remove \n");
        list_insert_iteratively(&arr[depth], array[depth]++, 0);
        for(int i = depth + 1; i < maxDepth; i++)
            array[i] += pow(2, i - depth );
        return ;
    }
    // printf("value of array depth is %d value of depth is :%d\n", array[depth], depth);
    list_remove_pos(&arr[depth],  array[depth]);
    list_insert_iteratively(&arr[depth], array[depth]++, t->MIS);
    levelwise2(t->left, arr, depth + 1, array, maxDepth);
    levelwise2(t->right, arr, depth + 1, array, maxDepth);
}

void BST_display(BST t)
{
    if(t == NULL)
        return ;
    int Depth = BST_depth(t);
    list arr[Depth + 2];
    for(int i = 0 ; i < Depth + 2; i++)
    { 
        list_init(&arr[i]);
        int power = pow(2, i);
        for(int j = 0; j < power;j++)
        list_add_end(&arr[i], 0);
    }
    int array[Depth + 2];
    for(int i = 0; i < Depth + 2; i++)
        array[i] = 1;
    levelwise2(t, arr, 0, array, Depth);

    struct winsize w; 
    ioctl(0, TIOCGWINSZ, &w); 

    int columns = w.ws_col;
    printf("the width of row is:%d\n", columns);
    int rows = w.ws_row;
    for(int i = 0; i < Depth + 1; i++)
    {
        while(arr[i] != NULL) {
            int j = list_remove_beg(&arr[i]); 
            int power = pow(2, i);
            int mov = (columns ) / (power + 1);
            if(j != 0) 
                printf("%*d", mov, j);
            else {
                char c = ' ';
                printf("%*c", mov, c);
            }
        }
        printf("\n\n\n\n");
        list_destroy(&arr[i]);
    }
}

void BST_remove(BST *t, int MIS){
    while(*t)
    {
        if((*t)->MIS == MIS)
        {
            BST temp = *t;
            if((*t)->right)
            {
                // printf("%d\n", (*t)->MIS);
                BST *r = &((*t)->right);
                while((*r)->left)
                    r = &((*r)->left);
                (*r)->left = (*t)->left; 
                *t = (*t) ->right;
            }
            else 
                *t = (*t)->left;
            free(temp);
            return;
        }
        else if((*t)->MIS > MIS)
            t = &((*t)->left);
        else
            t = &((*t)->right);
    }
    return ;
}

int BST_count(BST t){
    if(t == NULL)
        return 0;
    return 1 + BST_count(t->left) + BST_count(t->right);
}

void BST_preorder(BST t){
    if(t == NULL)
        return ;
    printf("name:%s, MIS:%d \n", t->name, t->MIS);
    BST_preorder(t->left);
    BST_preorder(t->right);
}

void BST_inorder(BST t){
    if(t == NULL)
        return ;
    BST_inorder(t->left);
    printf("name:%s, MIS:%d \n", t->name, t->MIS);
    BST_inorder(t->right);
}
void BST_postorder(BST t){
    if(t == NULL)
        return ;
    BST_postorder(t->left);
    BST_postorder(t->right);
    printf("name:%s, MIS:%d \n", t->name, t->MIS);
}
int BST_depth(BST t){
    if(t == NULL)
        return -1;
    int left = BST_depth(t->left);
    int right = BST_depth(t->right);
    return 1 + (left > right? left :right);
}
