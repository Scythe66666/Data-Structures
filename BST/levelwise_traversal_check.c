#include "BST.h"

int main()
{
    BST t1;
    BST_init(&t1);
    int i = 0;
     
    BST_insert(&t1, "ritesh", 33);
     
    BST_insert(&t1, "shivangi", 13);
     
    BST_insert(&t1, "amruni", 53);
     
    BST_insert(&t1, "snehal", 3);
     
    BST_insert(&t1, "mukta", 8);
     
    BST_insert(&t1, "Chinmay", 10);
    
    BST_insert(&t1, "Bankar", 63);
    
    BST_insert(&t1, "Dr Stone", 43);

    BST_insert(&t1, "ramchandra", 23);
    BST_insert(&t1, "John", 50);
    BST_insert(&t1, "Alice", 20);
    BST_insert(&t1, "Bob", 40);
    BST_insert(&t1, "Eve", 15);

    // Adding 18 more numbers with unique values

    BST_insert(&t1, "Mike", 55);
    BST_insert(&t1, "Sarah", 18);
    BST_insert(&t1, "David", 38);
    BST_insert(&t1, "Linda", 28);
    BST_insert(&t1, "James", 48);
    // BST_levelwise_traversal(t1);
    BST_display(t1);
}
