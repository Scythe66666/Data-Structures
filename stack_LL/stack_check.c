#include  "stackLL.h"

int main() {
    stackLL s1;
    stackLL_init(&s1);
    stackLL_push(&s1, 3);
    stackLL_push(&s1, 4);
    stackLL_push(&s1, 6);
    stackLL_push(&s1, 8);
    stackLL_push(&s1, 0);
    
    for(int i = 0; i < 10; i++)
    {
        int val;
        if((val = stackLL_pop(&s1)) == INT_MIN)
            printf("stack is empty\n");
        else {
            printf("popped value is %d\n", val);
        }
        if((val = stackLL_peek(s1)) == INT_MIN)
            printf("stack is empty for operation peek\n");
        else {
            printf("peeked value is %d\n", val);
        }
    }
    if(stackLL_Is_Empty(s1))
        printf("stack is Empty 1\n");
    stackLL_push(&s1, 8);
    stackLL_push(&s1, 0);
    if(stackLL_Is_Empty(s1))
        printf("stack is Empty 2\n");


}
