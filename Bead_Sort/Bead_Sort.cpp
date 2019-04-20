#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// BeadSort algorithm function
void beadSort(vector<int>& arr)
{
    // find maximum element in vector
    auto max = *std::max_element(std::begin(arr), std::end(arr));

    // declare beads vector for sorting
    vector<unsigned char> beads(max * arr.size(), 0);

    // initialize the beads accordingly
    for(auto i = 0; i < arr.size(); i++)
        for(auto j = 0; j < arr[i]; j++)
            beads[i * max + j] = 1;

    // Use gravity to let beads fall
    for(auto j = 0; j < max; j++)
    {
        int sum = 0;
        // assign beads for each post
        for(auto i = 0; i < arr.size(); i++)
        {
            sum += beads[i * max + j];
            beads[i * max + j] = 0;
        }

        // Use gravity to bring beads down
        for(auto i = arr.size() - sum; i < arr.size(); i++)
            beads[i * max + j] = 1;
    }

    // put sorted beads back into vector
    for(auto i = 0; i < arr.size(); i++)
    {
        for(auto j = 0; j < max && beads[i * max + j]; ++j)
            arr[i] = j+1;
    }
}

int main()
{
    // initialize vector
    vector<int> arr = {23, 2, 12, 54, 90, 102, 32};
    int n = sizeof(arr) / sizeof(arr[0]);

    // reserve static vector for optimal performance gain
    arr.reserve(n);

    // Print vector before sorting
    cout << "Before sorting" << endl;
    for(auto const& i: arr)
        cout << i << " ";
    cout << endl;

    beadSort(arr);

    // Print vector after sorting
    cout << "After sorting" << endl;
    for(auto const& i: arr)
        cout << i << " ";
    cout << endl;

    // Free memory space of vector
    arr.shrink_to_fit();
}

/*
Output
Before sorting
23 2 12 54 90 102 32
After sorting
2 12 23 32 54 90 102
*/
