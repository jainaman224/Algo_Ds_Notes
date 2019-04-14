/*
Fractional Knapsack problem is a variation of Knapsack problem where we can choose items by breaking them in fractions.
The objective is to fill the knapsack with items to get maximum benefit without crossing the weight capacity of the knapsack.
*/
#include<bits/stdc++.h>
using namespace std;

// Function to compute maximum profit obtainable
double fractionalKnapsackProblem(vector<pair<double,pair<double,double> > > arr, int nItems, int Capacity)
{
    /* We sort the vector arr on the basis of ratio value/weight, so v becomes:
    {(2, (12, 6)), (3, (30,10)), (4, (20,5)),(5, (15,3)), (5, (5,1)), (6, (12,2)) } */
    sort(arr.begin(), arr.end());
    /* variable weight to keep track of current weight added to Knapsack
    variable value to keep track of current value obtained from Knapsack
    variable remain to keep track of additional weight that can still be added to Knapsack*/
    double weight = 0.0;
    double value = 0.0;
    double remain;
    // Items with greater value/weight are selected first
    for (int i = (nItems - 1); i >= 0; i--)
    {
        // if current weight plus weight of the item to be added doesn't exceed Knapsack capacity select it
        if ((weight + arr[i].second.second) <= Capacity) 
        {
            weight += (arr[i].second.second);
            value += (arr[i].second.first);
        }
         /* if current weight plus weight of the item to be added exceeds Knapsack capacity, break the item into fractional part, and select the portion out of it which doesn't exceed the Knapsack capacity*/
        else
        {
            remain = (Capacity - weight);
            value += ((arr[i].second.first) * (remain / arr[i].second.second));
            break;
        }
    }
    // (12+ 5+ 15+ 20 + 30*(12-11)/10)
    return value;
}

// Driver function
int main()
{
    int wt[] = {6, 10, 3, 5, 1, 2};
    int val[] = {12, 30, 15, 20, 5, 12};
    int nItems = sizeof(wt)/sizeof(wt[0]);
    vector<pair<double,pair<double,double> > > arr;
    /* storing values in a pair of pair so arr will hold: 
    {(2, (12, 6)), (3, (30,10)), (5, (15,3)), (4, (20,5)), (5, (5,1)), (6, (12,2))}*/
    for(int i = 0; i < nItems; i++)
        arr.push_back(make_pair((double)val[i]/wt[i], make_pair(val[i], wt[i])));
    // Knapsack Capacity
    int Capacity = 12;
    // Call to Knapsack function
    double value = fractionalKnapsackProblem(arr, nItems, Capacity);
    cout<<"The maximum profit that can be obtained is :"<<value<<endl;
    return 0;
}
/*
Output:
The maximum profit that can be obtained is :55
*/
