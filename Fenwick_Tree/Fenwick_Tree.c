/*
    Fenwick Tree[also known as binary indexed tree] is used when there is a problem of range sum query wiht update i.e.RMQ.
    Suppose you have an array and you have been asked to find sum in range.It can be done in linear time with static array
    method.It will be difficult for on to do it in linear time when you have point updates.In this, update operation
    incrementing an index by some value.Brute force approach will take O(n^2) time but Fenwick tree will take O(nlogn) time.
*/

#include <stdio.h>
#include <stdlib.h>

/*  n --> No. of elements present in input array. 
    BITree[0..n] --> Array that represents Fenwick Tree(Binary Indexed Tree). 
    arr[0..n-1] --> Input array for which prefix sum is evaluated.
*/
/*
    Returns sum of arr[0..index]. This function assumes that the array is preprocessed and partial sums of 
    array elements are stored in BITree[]. 
*/

int getSum(int BITree[], int index)
{
    int sum = 0; // Iniialize result

    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse ancestors of BITree[index]
    while (index > 0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

/*
   Updates a node in Fenwick Tree at given index in BITree. The given value 'val' is added to BITree[i] and 
   all of its ancestors in tree. 
*/

void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
        // Add 'val' to current node of BI Tree
        BITree[index] += val;

        // Update index to that of parent in update View
        index += index & (-index);
    }
}

/*
   Constructs and returns a Fenwick Tree for given array of size n. 
*/

int *constructBITree(int arr[], int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = (int*) calloc(n+1, sizeof(int));

    for (int i = 1; i <= n; ++i)
        BITree[i] = 0;

    // Store the actual values in BITree[] using update()
    for (int i = 0; i < n; ++i)
        updateBIT(BITree, n, i, arr[i]);

    return BITree;
}

int rangeSum(int l, int r, int BITree[])
{
    return getSum(BITree, r) - getSum(BITree, l);
}

int main()
{
    int n;
    scanf("%d", &n);

    int freq[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &freq[i]);
    }
    int *BITree = constructBITree(freq, n);
    // Print sum of freq[0...5]
    printf("%d\n", getSum(BITree, 5));

    //Update operation
    freq[4] += 16;
    updateBIT(BITree, n, 4, 16);

    //Print sum of freq[2....7] after update
    printf("%d\n", rangeSum(2, 7, BITree));
   
    return 0;
    
}

/*  
INPUT 
-----
n=12
freq :[2,1,1,3,2,3,4,5,6,7,8,9];
Print sum of freq[0...5]
Update position 4 by adding 16 
Print sum of freq[2....7] after update
    
OUTPUT
------   
12
33
*/
