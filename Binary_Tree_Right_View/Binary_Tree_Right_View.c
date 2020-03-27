/* C program to print right view of the binary tree*/

#include<stdio.h>
#include<stdlib.h>

/* A binary tree node has data, pointer to left child and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

/* Inserting elements into Binary Tree*/
struct Node *create()
{
    Node *ptr;
    int x;
   
    printf("Enter data(-1 for no node):");
    scanf("%d", &x);

    if(x == -1)
    return NULL;

    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = x;
   
    printf("Enter left child of %d:\n",x);
    ptr -> left = create();
   
    printf("Enter right child of %d:\n",x);
    ptr -> right = create();
   
    return ptr;
}

/*Recursive solution for priniting right view of Binary Tree*/
void findRightView(struct Node *root, int *ans, int *size, int index)
{
    if(root == NULL)
        return;
    
    index++;

    // Increasing the level of the tree every time a node with the same level appears
    if(index > *size)
        ans[(*size)++] = root -> data;
    
    // Recursively calling the nodes down the tree
    findRightView(root -> right, ans, size, index);
    
    findRightView(root -> left, and, size, index);
}

// Function for intializing the level of the root node and size of the array 
int *rightView(struct Node *root, int *size)
{
    int *ans = malloc(sizeof(int) * 100);
    *size = 0;
    
    findRightView(root, ans, size, 0);

    return ans;
}

int main()
{
    struct Node *root = create();

    int size = 0;
    int *res = rightView(root, &size);

    for(int i = 0; i < size; i++)
        printf("%d", res[i]);
}

/* Sample Input
Enter data(-1 for no node: 1
Enter left child of 1:
Enter data(-1 for no node: 2
Enter left child of 2:
Enter data(-1 for no node: 6
Enter left child of 6:
Enter data(-1 for no node: -1
Enter right child of 6:
Enter data(-1 for no node: -1
Enter right child of 2:
Enter data(-1 for no node: -1
Enter right child of 1:
Enter data(-1 for no node: 3
Enter left child of 3:
Enter data(-1 for no node: -1
Enter right child of 3:
Enter data(-1 for no node: -1

            1
           / \
          2   3
         /      
        6

Output :- 1 3 6
*/

