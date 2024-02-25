#ifndef STACK_LL

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
typedef node * stackLL;

void stackLL_init(stackLL *s);
int stackLL_push(stackLL * s, int data);
int stackLL_pop(stackLL *s);
int stackLL_peek(stackLL s);
int stackLL_Is_Empty(stackLL s);
#endif // !STACK_LL
