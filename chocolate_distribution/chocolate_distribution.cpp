//Chocolate Distribution problem
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int min_diff(int a[], int num_packets, int num_children)
{
    if (num_children == 0 || num_packets == 0)
        return 0;
    if (num_children > num_packets)
        return -1;
    int i, j, diff = 0, required_diff, first = 0, last = 0;
    required_diff = INT_MAX;  //INT_MAX is a macro that specifies that an integer variable cannot store any value beyond this limit.
    sort(a, a + num_packets);
    for (i = 0; i + num_children - 1 < num_packets; i++)
    {
        diff = a[i + num_children-1] - a[i];
        if(diff < required_diff)
        {
            required_diff = diff;
            first = i;
            last = i + num_children -1;
        }
    }
    return required_diff;
}

int main()
{
    int num_packets, num_children, i, j, k;
    cin>>num_children;  //size of group in which chocolates  needs to be distributed
    cin>>num_packets;  //size of array
    int a[num_packets];
    for (i = 0; i < num_packets; i++)
        cin>>a[i];  //taking input for the quantity of chocolate contained in each packet
    if (min_diff(a, num_packets, num_children) >= 0)
         cout<<"The minimum difference of chocolates distibuted between children who got maximum and minimum is "<< min_diff(a, num_packets, num_children);
    else
        cout<<"As the number of students is less than number of packets hence no minimum difference is valid or is -1";
    return 0;
}

//input :
//5
//8
//3 4 1 9 56 7 9 12
//output:The minimum difference of chocolates distibuted between children who got maximum and minimum is 6
