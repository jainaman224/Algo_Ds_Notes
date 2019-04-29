/*Segment tree or segtree is a basically a binary tree used for storing the intervals or segments. Each node in the segment tree represents an interval.
Consider an array A of size N and a corresponding segtree T:
The root of T will represent the whole array A[0:N-1].
Each leaf in the segtree T will represent a single element A[i] such that 0 <= i < N.
The internal nodes in the segtree tree T represent union of elementary intervals A[i:j] where 0 <= i < j < N.*/
#include <iostream>
#include <math.h> 

using namespace std;
#define MAX 100
int tree[MAX] = {0};
int lazy[MAX] = {0};

//Updating the tree by incrementing elements within range [l, r] with value val
int update(int node, int start, int end, int l, int r, int val);

//Function to find sum and maximum value in the array within the query [l,r]
int func(int start, int end, int l, int r, int node, int choice);

//Constructing tree 
void construct(int arr[], int start, int end, int node);

int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int node = 0;
    int start = 0;	

    //Constructing the tree
    construct(arr, start, n - 1, node);

    // Updating the value in the array from index 0 to index 3 by adding value 4 in it.
    update(node, start, n - 1, 0, 3, 4);
    //After updating the array becomes [5,6,7,8,5]

    cout << "1.Sum\n";
    cout << "2.Maximum\n";
    cout << "3.Quit";
    int choice;
    do 
    {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: // To get the sum of updated array from index 1 to index 4
                    // Sum of updated array [5,6,7,8,5]
                    cout << "\nUpdated sum of value in given range = " << func(start, n-1, 1, 4,node,choice);
                    break;

            case 2: // To get the maximum value in updated array from index 1 to index 4
                    // Maximum value of the updated array
                    cout << "\nUpdated maximum value in given range = " << func(start, n-1, 1, 4,node,choice);
                    break;

            case 3: cout << "Exit \n";
                    break;               
        }  
    } while(choice != 3);
    return 0; 
} 

// A recursive function that constructs Segment Tree for 
//  array[start..end]. 
void construct(int arr[], int start, int end, int node) 
{     
    // out of range as start can never be greater than end 
    if (start > end) 
        return ;   

    // If there is one element in array, store it in 
    // current node of segment tree and return 
    if (start == end) 
    { 
        tree[node] = arr[start]; 
        return; 
    } 

    // If there are more than one elements, then  
    //  left and right subtrees and store the sum 
    // of values in this node 
    int mid = (start + end) / 2; 
    construct(arr, start, mid, node * 2 + 1); 
    construct(arr, mid + 1, end, node * 2 + 2); 

    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2]; 
}

//Function to find sum and maximum value in the array within the query [l, r]
int func(int start, int end, int l, int r, int node, int choice) 
{ 
    if (lazy[node] != 0) 
    { 
        // Make pending updates to this node. 
        tree[node] += (end - start + 1) * lazy[node]; 
         
        if (start != end) 
        { 
            // Mark child as lazy 
            lazy[node * 2 + 1] += lazy[node]; 
            // Mark child as lazy
            lazy[node * 2 + 2] += lazy[node]; 
        } 
        // Reset it
        lazy[node] = 0; 
    } 

    // Current segment is not within range [l, r]
    if (start > end || start > r || end < l) 
        return 0; 

    // Current segment is totally within range [l, r]
    if (start >= l && end <= r) 
        return tree[node]; 

    int mid = (start + end) / 2; 

    //To find sum
    if (choice == 1)
        return func(start, mid, l, r, 2*node+1, choice) + func(mid+1, end, l, r, 2*node+2, choice); 
    //To find max value
    if (choice == 2)
        return max(func(start, mid, l, r, 2*node+1, choice),func(mid+1, end, l, r, 2*node+2, choice));
}  

int update(int node, int start, int end, int l, int r, int val) 
{ 
    if (lazy[node] != 0) 
    { 
        // This node needs to be updated
        // Update it
        tree[node] += (end - start + 1) * lazy[node]; 
        if (start != end) 
        { 
            lazy[node * 2 + 1] += lazy[node]; 
            lazy[node * 2 + 2] += lazy[node]; 
        }
        lazy[node] = 0; 
    } 

    // out of range
    if (start > end || start > r || end < l) 
        return 0; 

    / Current segment is totally within range [l, r]
    if (start >= l && end <= r) 
    { 
        tree[node] += (end - start + 1)*val; 
        if (start != end) 
        { 
            // Not leaf node
            lazy[node * 2 + 1] += val; 
            lazy[node * 2 + 2] += val; 
        } 
        return 0; 
    } 

    // If not a leaf node, recur for children.
    int mid = (start + end) / 2;

    // Updating left child
    update(node * 2 + 1, start, mid, l, r, val); 

    // Updating right child
    update(node * 2 + 2, mid + 1, end, l, r, val); 

    // Use the result of children calls to update this node
    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

/*
1.Sum
2.Maximum
3.Quit
Enter your choice: 1
Updated sum of value in given range = 26
Enter your choice: 2
Updated maximum value in given range = 8
*/
