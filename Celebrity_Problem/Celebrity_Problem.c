/*
CELEBRITY PROBLEM

In a group of N people, there is 1 person, who is known to everyone, but
he knows noone.
We need to find such a person, if present.

There will be a matrix input, such that M[i][j] = 1, if ith person
knows jth person, else 0.
*/

#include<stdio.h>

int Celebrity(int Person[][100], int n) {
    int start = 0;
    int end = n - 1;
    while(1) {
        if (start == end) {
            break;
        }
        if (Person[start][end] == 1) {
            start++;
        }
        else {
            end--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == start) {
            continue;
        }
        if (Person[start][i] == 1 || Person[i][start] == 0) {
            return -1;
        }
    }
    return start;
}

int main() {
    int n;
    scanf("%d", &n);
    int Person[n][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Person[i][j]);
        }
    }
    int celeb = Celebrity(Person, n);
    if (celeb >= 0) {
        printf("Celebrity Present at index %d", celeb);
    }
    else {
        printf("Celebrity not present");
    }
}

/*
INPUT : n = 5
Person = 0 1 0 0 1
         0 0 0 0 0
         1 1 1 0 0
         1 1 0 0 1
         0 1 1 1 0
OUTPUT :
Celebrity Present at index 1
*/
