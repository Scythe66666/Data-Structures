#include "BST.h"

int main()
{
    BST t1;
    BSTinit(&t1);
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
    printf("before removing inorder is \n");
    inorder(t1);
    BST_remove(&t1, 23); 
    BST_remove(&t1, 48); 
    BST_remove(&t1, 55); 
    BST_remove(&t1, 33); 
    BST_remove(&t1, 13); 
    BST_remove(&t1, 3); 
    BST_remove(&t1, 15); 
    BST_remove(&t1, 38); 
    BST_remove(&t1, 28); 
    BST_remove(&t1, 8); 
    BST_remove(&t1, 20); 
    BST_remove(&t1, 18); 
    BST_remove(&t1, 43); 
    BST_remove(&t1, 53); 
    BST_remove(&t1, 63); 
    BST_remove(&t1, 10); 
    BST_remove(&t1, 40); 
    BST_remove(&t1, 50); 
    printf("last\n");
    inorder(t1);
}
