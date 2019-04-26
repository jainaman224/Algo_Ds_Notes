/*
    Painter's Partition Problem

    You are given n boards to paint and k painters are available with
    the restriction that 1 painter can paint 1 unit of board in 1 unit
    time. Also, 1 painter can paint only consecutive pieces of boards.

    We need to find the minimum amount of time required for painting
    all the boards.
*/
#include <bits/stdc++.h>
using namespace std;
#define lint long long int

/*
    This function returns the minimum no. of painters required to
    paint the board given that a painter can paint consecutive mid
    units of board at max.
*/
lint painters(lint board[], lint n, lint mid) {
    lint painter = 0;
    lint time = 0;
    for(lint i = 0; i < n; i++) {
        time += board[i];
        if(time > mid) {
            time = board[i];
            painter ++;
        }
    }
    return painter;
}

/*
    The minimum time required to paint the boards would be 
    the maximum length of all the boards available, while the
    maximum time would be when there is only one painter 
    available. In that case, he has to print all the boards,
    i.e. the sum total of lengths of all the boards.

    The idea is to apply binary search between these two 
    time periods, and for each iteration, find if the required
    no. of painters with max consecutive mid units painted is
    less than available number of painters.

    This way, we would get the least time required by the
    optimal number of painters to paint all the boards.
*/
lint partition(lint board[], lint k, lint sum, lint n, lint m) {
    lint low = m;
    lint high = sum;
    while (low < high) {
        lint mid = (low + high)/2;
        if(painters(board, n, mid) < k) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }
    return low;
}

int main(){
    lint n; // Enter the number of boards.
    cin >> n;
    lint board[n];  // Length of boards.
    for(lint i = 0; i < n; i++){
        cin >> board[i]; 
    }
    lint k;
    cin >> k;    // Enter the number of painters.
    lint sum = 0;
    lint m = 0;
    for(lint i = 0; i < n; i++) {
        sum += board[i];
        m = max(m, board[i]);
    }
    cout << " Minimum time to paint all the boards is: " << partition(board, k, sum, n, m);
}

/*
    Input : no. of boards = 5
            board = [2,5,6,3,4]
            no. of painters = 4
    Output : Minimum time to paint all the boards is : 7
    Verification : 1st painter will paint first two boards (2+5 = 7)
                   2nd painter will paint the third board (6)
                   3rd painter will paint the last two boards (3+4 = 7)
*/
