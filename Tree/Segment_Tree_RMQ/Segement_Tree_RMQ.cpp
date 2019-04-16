#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int RMQ(int segArray[], int segStart, int segEnd, int start, int end, int index)
{
    if (start <= segStart && end >= segEnd)
        return segArray[index];

    if (segEnd < start || segStart > end)
        return INT_MAX;

    int mid = segStart + (segEnd - segStart) / 2;

    int left = RMQ(segArray, segStart, mid, start, end, 2*index + 1);
    int right = RMQ(segArray, mid + 1, segEnd, start, end, 2*index + 2);
    return (left <= right ? left : right);
}

int buildSegmentTree(int array[], int start, int end, int segArray[], int index)
{
    if (start == end)
    {
        segArray[index] = array[start];
        return array[start];
    }

    int mid = start + (end - start) / 2;
    int left = buildSegmentTree(array, start, mid, segArray, index*2 + 1);
    int right = buildSegmentTree(array, mid + 1, end, segArray, index*2 + 2);

    segArray[index] = (left <= right ? left : right);

    return segArray[index];
}

int main()
{
    int array[10] = {1, 3, 2, 7, 9, 11, 8, 4, 20, 15};
    int size = 10;

    int height = ceil( log2(size) );
    int segtree_size = 2 * (pow(2, height) - 1);
    int *segArray = new int[segtree_size];

    buildSegmentTree(array, 0, size - 1, segArray, 0);

    int start = 1, end = 5;

    cout << "Minimum value in index range " <<  start << " to " << end << " is" << endl;
    cout << RMQ(segArray, 0, size - 1, start, end, 0) << endl;

    return 0;
}


/* Output
 *
 * Minimum value in index range 1 to 5 is
 * 2
 *
 */
