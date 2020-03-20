/* C program to print bottom view of the binary tree*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// A binary tree node has data, pointer to left child and a pointer to right child
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
    
    printf("Enter left child of %d:\n", x);
    ptr -> left = create();
    
    printf("Enter right child of %d:\n", x);
    ptr -> right = create();
    
    return ptr;
}

// Calculating the level and the vertical distance of the node and finding the nodes that appear as the top view
void findBottomView(struct Node *root, int *a, int *b, int level, int dist)
{
    if(root == NULL)
        return;

    if(level > a[50 + dist])
    {
        a[50 + dist] = level;
        b[50 + dist] = root -> data;
    }
    
    # Recursively calling the right and the left child to get the bottom view
    
    findBottomView(root -> right, a, b, level + 1, dist + 1);
    findBottomView(root -> left, a, b, level + 1, dist - 1);
}

int *bottomView(struct Node* root, int *len) {
    
    int i, o = 0;
    
    // a stores level of the node
    // b stores vertical distance of the node from root
    
    int *a = (int *)calloc(100, sizeof(int));
    int *b = (int *)calloc(100, sizeof(int));
    int *c = (int *)calloc(100, sizeof(int));
    
    // Initialising a and b as INT_MIN as we need to print bottom most elements
    for(i = 0; i < 100; i++)
    {
        a[i] = INT_MIN;
        b[i] = INT_MIN;
    }

    findBottomView(root, a, b, 0, 0);
    
    for(i = 0; i < 100; i++)
    {
        if(b[i] != INT_MIN)
            c[o++] = b[i];
    }

    *len = o;
    return c;
}

int main()
{
    struct Node *root = create();
    int len = 0;
    int *res = bottomView(root, &len);
    
    for(int i = 0; i < len; i++)
        printf("%d ", res[i]);
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

Output :- 6 2 1 3
*/

