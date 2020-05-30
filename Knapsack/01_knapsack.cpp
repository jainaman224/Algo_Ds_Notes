#include <iostream>
#include <vector>
using namespace std;

// Function to return maximum profit 
int knapsack(vector<int> profit, vector<int> weight, int capacity, int n) {         

    if(capacity == 0 || n == 0 ) {
        return 0;
    }
    if(weight[n - 1] > capacity) {
        return knapsack(profit, weight, capacity, n - 1);
    }
    else {
        return max(profit[n - 1] + knapsack(profit, weight, capacity - weight[n - 1], n - 1), knapsack(profit, weight, capacity, n - 1));
    }
}

int max(int a, int b) {
    if(a > b) {
        return a;
    }
    else {
        return b;      
    }
}

int main() {
    int capacity, n;
    cout << "Enter the number of elements to be stored: ";
    cin >> n;
    vector<int> profit(n), weight(n);
    cout << "Enter the profit values of all elements: ";
    for(int i = 0; i < n; i++) {
        cin >> profit[i];
    }
    cout << "Enter the weights of all elements: ";
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    cout << "Enter the capacity: ";
    cin >> capacity;
    cout << "The maximum profit will be: " << knapsack(profit, weight, capacity, n);
    return 0;
}

/*
SAMPLE INPUT:
Enter the number of elements to be stored: 6
Enter the profit values of all elements: 10 20 30 44 56 72
Enter the weights of all elements: 5 10 15 25 20 15
Enter the capacity: 70

SAMPLE OUTPUT:
The maximum profit will be: 192
*/
