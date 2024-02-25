#include "stackLL.h"
void stackLL_init(stackLL *s)
{
    *s = NULL;
}
/**
 *\brief pushes the element on stack and return 1 if succesfull
 *and 0 if unsuccessfull
 *\param s pointer to head stackLL
 *\param data value to be pushed in stack
 **/
int stackLL_push(stackLL * s, int data)
{
    node * temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = *s;
    if(temp == NULL)
        return 0;
    *s = temp;
    return 1;
}
/**
 *\brief returns 1 if stack is empty else returns 0
 **/
int stackLL_Is_Empty(stackLL s)
{
    if(s == NULL)
        return 1;
    return 0;
}

/**
*\brief pops the top data stored in stack return INT_MIN 
*when stack is empty and returns data if stack not empty
* */
int stackLL_pop(stackLL *s)
{
    if(stackLL_Is_Empty(*s))
        return INT_MIN;
    node * temp = *s;
    *s = (*s)->next;
    int data = temp->data;
    free(temp);
    return data;
}

int stackLL_peek(stackLL s)
{
    if(stackLL_Is_Empty(s))
        return INT_MIN;
    return s->data;
}
