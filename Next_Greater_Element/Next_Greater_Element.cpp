/*
    Next Greater Element for any element present in the array is the 
    first element occuring to the right of the element which is greater
    in value than the element. For example:
    arr = [5, 10, 14, 6, 12, 20]
    Next greater element for the elements are as following:
    5 -> 10
    10 -> 14
    14 -> 20
    6 -> 12
    12 -> 20
    20 -> NULL
*/

#include<bits/stdc++.h>
using namespace std;

// Function to compute next greater element of elements of array
void nextGreaterElement(int arr[], int size)
{
    // Create a stack
    stack<int> st;

    // Insert first element into stack
    st.push(arr[0]);

    cout << "Next Greater Element" << endl;
    for (int i = 1; i < size; i++) 
    {

        /* if the array element is greater than the element present
        at the top of stack, then arr[i] is the next greater element
        of element present at the top of stack */
        while (!st.empty() && arr[i] > st.top()) 
        {
            cout << st.top() << " : " << arr[i] << endl;
            st.pop();
        }

        // Push the array element to the stack to find its next
        // greatest element
        st.push(arr[i]);
    }
    
    // if the element does not have next greater element present
    // in the array, print -1 
    while (!st.empty()) 
    {
        cout << st.top() << " : " << -1 << endl;
        st.pop();
    }
}
    
// Driver function
int main()
{            
    int arr[] = {10, 40, 48, 20, 50, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Call to nextGreaterElement function
    nextGreaterElement(arr, size);
}

/*
    Input:
    {10, 40, 48, 20, 50, 5}

    Output:
    Next Greater Element
    10 : 40
    40 : 48
    20 : 50
    48 : 50
    5 : -1
    50 : -1
*/
