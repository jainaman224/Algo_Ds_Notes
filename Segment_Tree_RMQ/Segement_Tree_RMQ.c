#include <stdio.h>
#include<stdlib.h>
#include <limits.h>

int min(int x, int y)
{
    return (x < y) ? x : y;
}

void build(int *a, int *tree, int start, int end, int treenode)
{
    if (start == end)
    {
        tree[treenode] = a[start];
        return;
    }

    int mid;
    mid = (start + end) / 2;

    //compute the values in the left and right subtrees
    build(a, tree, start, mid, 2 * treenode);
    build(a, tree, mid + 1, end, 2 * treenode + 1);

    /*store the minimum value in the first and
    second half of the interval*/
    tree[treenode] = min(tree[2 * treenode], tree[2 * treenode + 1]);
    return;
}

int query(int *tree, int start, int end, int l, int r, int treenode)
{
    /* if the current interval doesn’t intersect
    the query interval return INT_MAX*/
    if (start > r || end < l)
    {
        return INT_MAX;
    }

    /*if the current interval is included in
    the query interval return tree[treenode]*/
    if (start >= l && end <= r)
    {
        return tree[treenode];
    }

    int mid;
    mid = (start + end) / 2;

    //return the minimum value
    int e = query(tree, start, mid, l, r, 2 * treenode);
    int f = query(tree, mid + 1, end, l, r, 2 * treenode + 1);

    return min(e, f);
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int  array[size];
    int *segTree = (int *)malloc(sizeof(4 * size));
    
    printf("Enter the elements.\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    build(array, segTree, 0, size - 1, 1);

    int start, end;
    printf("Enter the range of the query: ");
    scanf("%d %d", &start, &end);
    int result = query(segTree, 0, size - 1, start - 1, end - 1, 1);

    printf("Minimum value in index range %d to %d is: %d\n", start, end, result);

    return 0;
}

/*
Input:
Enter the size of the array.: 5
-7 3 -1 8 1
Enter the range of the query.: 2 5

Output:
Minimum value in index range 2 to 5 is: -1
*/
