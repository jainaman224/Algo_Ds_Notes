#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
using namespace std;
 
#define N 100
 
struct node{
    char data;
    int key;
} A[N];
 
/*
 * Initial heap size 0 as heap is empty
 */
int heapsize = 0;
 
/*
 * Find the parent node
 */
int parent(int i){
    return ceil(i / 2.0 - 1);
}
 
/*
 * Use for heap insert and decrease key
 * In if condition check if user attempted to increase value instead of decrease
 * Compare child with parent, if child is smaller then swap
 * Now mark that child and apply the same logic until it reaches root node
 */
void decreaseKey(int i, node n){
    if(n.key > A[i].key){
        printf("Error\n");
        return;
    }
 
    A[i] = n;
    while(i > 0 && A[parent(i)].key > A[i].key){
        std:: swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}
 
/*
 * Search for a specific node to change its value
 * Returns the index the node being searched
 */
int searchIndex(node n){
    for(int i = 0; i < heapsize; ++i){
        if(A[i].data == n.data)
            return i;
    }
    return heapsize;
}
 
/*
 * Called initially to create a min heap
 * Also called after a node extraction from min heap
 * Since the smallest value node is at the root of min heap
 * After extraction min heapify is called on root node
 * It compares parent with its children
 * If a smaller child found then its swapped with parent and
 * Min heapify is again called on that child to apply same procedure
 */
void minHeapify(int i){
    int largest;
 
    int l = 2*i +1;
 
    if (l < heapsize && A[l].key < A[i].key)
        largest = l;
    else
        largest = i;
 
    int r = 2*i +2;
 
    if (r < heapsize && A[r].key < A[largest].key)
        largest = r;
 
    if (largest != i){
        std::swap(A[i], A[largest]);
        minHeapify(largest);
    }
}
 
/*
 * Does not extract any items only show the minimum element
 */
node heapMinimum(){
    return A[0];
}
 
/*
 * Increase heap size to create space for new node
 * Insert the node at that space by calling decrease key function
 */
void heapInsert(node n){
    ++heapsize;
    A[heapsize - 1].key = INT_MAX;
    decreaseKey(heapsize - 1, n);
}
 
/*
 * Heap size less than zero mean no items in heap so nothing to extract
 * For min heap minimum value is at the root which in here is A[0]
 * Save the root and replace root with last element in the heap and decrease the heap size
 * So the root is still in the array in last position but no longer in the heap
 * Since the last element is now the root the heap may be unbalanced
 * So to balance the heap call min heapify on the root node again
 * Lastly return the saved root
 */
node extractMin(){
    if(heapsize < 0)
        printf("Heap Underflow\n");
 
    node min = A[0];
    A[0] = A[heapsize - 1];
    --heapsize;
    minHeapify(0);
    return min;
}
 
/*
 * Every time we extract heap size is automatically reduced
 * So no need change heap size in while loop
 */
void printPriorityQueue(){
    printf("Main Output:\n");
    while(heapsize){
        node ext = extractMin();
        printf("%c %d\n", ext.data, ext.key );
    }
}
 
/*
 * input data and key for node and insert that node in min priority queue
 */
void inputQueueItems(){
    int i;
    printf("How many nodes?\n");
    scanf("%d", &i); getchar();
    while(i--){
        node n;
        printf("Enter node name and its value:\n");
        scanf("%c%d", &n.data, &n.key);
        getchar();
        heapInsert(n);
    }
}
 
int main(){
 
    inputQueueItems();
    printPriorityQueue();
 
 
    /*
     * Sample input for quick testing
     * Before using this comment inputQueueItems() function call
     */
    /*
    heapInsert({'z',99});
    heapInsert({'a',9});
    heapInsert({'v',29});
    heapInsert({'x',19});
    heapInsert({'c',95});
    heapInsert({'g',22});
    heapInsert({'b', 1});
    heapInsert({'e', 5});
    heapInsert({'d', 2});
    */
    //decreaseKey( searchIndex({'a', 9}), {'a', 4} );
 
    return 0;
}
