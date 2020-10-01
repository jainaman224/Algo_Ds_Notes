# N Queens Problem
The N Queens Problem is one of the most common examples of **backtracking**. The problem is to arrange N queens on an NxN chessboard such that no queen can strike down any other queen. A queen can attack horizontally, vertically, or diagonally.

<img src="https://www.dl.dropboxusercontent.com/s/ba1ld9w66wr0qap/final.png" width="300">

## Algorithm
The idea is to place queens one by one in different columns, starting from the leftmost column. When we place a queen in a column, we check for clashes with already placed queens. In the current column, if we find a row for which there is no clash, we mark this row and column as part of the solution. If we do not find such a row due to clashes then we backtrack and return false.
- Start in the leftmost column
- If all queens are placed return true
- Try all rows in the current column.  Do following for every tried row.
    - If the queen can be placed safely in this row then mark this [row, column] as part of the solution and recursively check if placing queen here leads to a solution.
    - If placing the queen in [row, column] leads to a solution then return true.
    - If placing queen doesn't lead to a solution then you mark this [row, column] (Backtrack) and go to step (a) to try other rows.
- If all rows have been tried and nothing worked, return false to trigger backtracking.

## Pseudocode
```
// Using backtracking, this procedure prints all possible placements of
// n- queens on the n*n chess board so that they are non-attacking.
Function N-Queen(k, n)
{
    For I = 1 to n do
    {
        If Place (k, i) then
        {
        X[k] = I;
        If (k = n) then write (x[1: n ]) ;
        Else N Queens (k+1, n);
        }
    }
}
```

## Example
The below picture shows an NxN chessboard and we have to place N queens on it. 
<img src="https://www.dl.dropboxusercontent.com/s/xwxvx07zzzxzm3r/n.png" width="200">

So, we will start by placing the first queen.
<img src="https://www.dl.dropboxusercontent.com/s/nqegxh9akpdrusl/1.png" width="200">

Now, the second step is to place the second queen in a safe position and then the third queen.
<img src="https://www.dl.dropboxusercontent.com/s/kfyaphyf0hfjel9/2.png" width="200">

<img src="https://www.dl.dropboxusercontent.com/s/tkepimv5na6drj7/3.png" width="200">

Now, you can see that there is no safe place where we can put the last queen. So, we will just change the position of the previous queen. And this is backtracking.

Also, there is no other position where we can place the third queen so we will go back one more step and change the position of the second queen.

<img src="https://www.dl.dropboxusercontent.com/s/ci2l3v88qs77r8k/4.png" width="200">

And now we will place the third queen again in a safe position until we find a solution.

<img src="https://www.dl.dropboxusercontent.com/s/yr8mkqy80eoboc6/5.png" width="200">

We will continue this process and finally, we will get the solution as shown below.

<img src="https://www.dl.dropboxusercontent.com/s/ba1ld9w66wr0qap/final.png" width="200">

## Time Complexity
For function T(n) = n*T(n-1) + O(n<sup>2</sup>) which translates to O(N!). So the average time complexity is **O(N!)**

## Implementation

*  [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Queens_Problem/Queens_Problem.c)

> :rocket: [Compile Online](https://repl.it/@vsharma20v/n-queens-problem-in-c) :rocket:

*  [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Queens_Problem/Queens_Problem.cpp)

> :rocket: [Compile Online](https://repl.it/@vsharma20v/MintcreamBelovedAggregators) :rocket:
 
*  [JavaScript Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Queens_Problem/Queens_Problem.js)

> :rocket: [Compile Online](https://repl.it/@vsharma20v/EducatedPapayawhipSourcecode) :rocket:
  
*  [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Queens_Problem/Queens_Problem.py)

> :rocket: [Compile Online](https://repl.it/@vsharma20v/LawngreenMajorSpreadsheet) :rocket:

## Reference Materials
- [GeeksforGeeks article](https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/)
- [GeeksforGeeks video](https://www.youtube.com/watch?v=0DeznFqrgAI)
