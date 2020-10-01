/*
MANHATTAN DISTANCE

In a 2D plane, the manhattan distance is equal to the distance needed
to be covered using only vertical and horizontal steps.

M(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|

Given an array of co-ordinates. find the sum of manhattan distances 
of all the coordinates with each other.
*/

#include<stdio.h>

int Manhattan(int x[], int y[], int i, int j) {
    return (abs(x[i] - x[j]) + abs(y[i] - y[j]));  
}

int ManhattanSum(int x[], int y[], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = ans + Manhattan(x, y, i, j);
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int x[n];
    int y[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }
    printf("%d", ManhattanSum(x, y, n));
}

/*
INPUT
x = [3, 3, 2, -2]
y = [6, -5, 0, 2]
OUTPUT
51
*/
