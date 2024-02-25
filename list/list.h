#ifndef LIST

#define LIST
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
typedef node* list;

void list_init(list* head);

int list_add_end(list *head, int data);

void list_number_display(list l);

int list_remove_end(list *head);

int list_remove_beg(list *head);

void list_display(list l);

void list_concat(list *l, list n);

node * list_search(list l, int data);

void list_reverse(list *head);

int list_insert_iteratively(list *head, int pos, int val);

void list_insert_recursively(list *l, int pos, int val);

int list_add_beg(list *l, int data);

void list_destroy(list *l);

int list_len(list l);

list list_make_copy(list l1);

#endif // !LIST
