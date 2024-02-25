#include "list.h"


void list_init(list* head)
{
    *head = NULL;
}
void list_number_display(list l)
{
    while(l){
        printf("%d", l->data);
        l = l->next;
    }
    printf("\n");
}
int list_add_beg(list *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    if(!temp)
        return INT_MIN;
    temp->data = data;
    temp->next = *head;
       
    *head = temp;
    return 1;
}

int list_add_end(list *head, int data)
{
    node * temp = (node *)malloc(sizeof(node));
    if(!temp)
        return INT_MIN;
    temp->data = data;
    temp->next = NULL;
    
    if(*head == NULL)
    {
        *head = temp;
        return 1;
    }

    node * traverse = *head;
    while(traverse->next) traverse = traverse ->next;
    
    traverse->next = temp; 
    return 1;
}

int list_remove_beg(list *head)
{
    if(*head == NULL)
        return INT_MIN;

    list temp = (*head) ->next;
    int data = (*head) ->data;
    free(*head);
    *head = temp;
    return data;
}

int list_remove_end(list *head)
{
    if(*head == NULL)
        return INT_MIN;
    
    if((*head)->next == NULL)
    {
        int temp = (*head)->data;
        free(*head);
        *head = NULL;
        return temp;
    }

    node * traverse = *head;
    while((traverse->next)->next) traverse = traverse ->next;
    
    int temp = (traverse->next)->data;
    free(traverse->next);
    traverse->next = NULL;
    return temp;
}

void list_display(list l)
{
    printf("[ ");
    while(l)
    {
        printf("%d, ", l->data);
        l = l->next;
    }
    printf("]\n");
}

void list_concat(list *l, list b)
{
    while(b)
    {
        list_add_end(l, b->data);
        b = b->next;
    }
}

node * list_search(list l, int data)
{
    while(l)
    {
        if(l->data == data)
            return l;
        l = l->next;
    }
    return NULL;
}

void list_reverse(list *head)
{
    if(*head == NULL || (*head)->next == NULL)
        return ;

    node *curr = *head;
    node *prev = NULL;
    
    while(curr)
    {
        node * temp = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = temp; 
    }

    *head = prev;
}
//give pos as 1 to enter at the begining of the list
//     int insert_iteratively(list *head, int pos, int val)
//     {
//     if(pos <= 1)
//     {
//         node *temp = (node *)malloc(sizeof(node));
//         if(!temp)
//             return INT_MIN;
//
//         temp->data = val;
//         temp->next = *head;
//         *head = temp; 
//         return 1;
//     }
//
//     if(*head == NULL)
//         return INT_MIN;
//
//     node *traverse = *head;
//     int count = 1;
//     while(count++ < pos - 1)
//     {
//         if(traverse == NULL)
//             return INT_MIN;
//         traverse = traverse->next;       
//     }
//     
//     node *temp = (node *)malloc(sizeof(node));
//     if(!temp)
//         return INT_MIN;
//
//     temp->data = val;
//     temp->next = traverse->next;
//     traverse->next = temp; 
//     return 1;
// }




/**
* \briefthe function inserts a number at given position and list and 
* pushes the numbers on the position before insertion after the 
* insert 
* \param head pointer to pointer to head
* \param pos position in list at which number is to be inserted
* \param val value to be inesrted in list
**/

int list_insert_iteratively(list *head, int pos, int val)
{
    list *traverse = head;
    while(pos != 1)
    {
        if(*traverse == NULL)
            return INT_MIN;
        traverse = &((*traverse) -> next);
        pos--;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp->next = *traverse;
    temp->data = val;
    *traverse = temp;
    return 1;
}

int list_remove_pos(list *head, int pos)
{
    list *traverse = head;
    list *prev = traverse;
    while(pos != 1)
    {
        prev = traverse;
        if(*traverse == NULL)
            return INT_MIN;
        traverse = &((*traverse) -> next);
        pos--;
    }
    *prev = (*traverse)->next;
}

void insert_recursively(list *l, int pos, int val)
{
    if(*l == NULL)
    {
        return ;
    }
    if(pos == 1)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->next = *l;
        temp->data = val;
        *l = temp;
        return ;
    }
    
    insert_recursively(&((*l) -> next), pos -1, val);
}

void list_destroy(list *l){
    if((*l) == NULL)
        return ;
    list_destroy(&((*l)->next));
    free(*l);
    *l = NULL;
}

int list_len(list l)
{
    int len = 0;
    while(l)
    {
        len++;
        l = l->next;
    }
    return len;
}

list list_make_copy(list l1)
{
    list l3;
    list_init(&l3);
    while(l1)
    {
        list_add_end(&l3, l1->data);
        l1 = l1->next;
    }
    return l3;
}
