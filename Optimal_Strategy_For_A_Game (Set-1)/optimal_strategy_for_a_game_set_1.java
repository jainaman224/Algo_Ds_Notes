/*
OPTIMAL STRATEGY FOR A GAME SET - 1
Given Problem Statement : Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even.
We play a game against an opponent by alternating turns. In each turn,
a player selects either the first or last coin from the row,
removes it from the row permanently and receives the value of the coin.
Determine the maximum possible amount of money we can definitely win if we move first.
Note - Note: The opponent is as clever as the user.
*/

// Java program to find out maximum 
// value from a given sequence of coins  

import java.io.*; 
import java.util.*;

class OptimalGS{ 

	// Returns optimal value possible that a player 
	// can collect from an array of coins of size n. 
	// Note than n must be even 
	static int optimalStrategyOfGame(int arr[], int n) 
	{ 
		// Create a table to store solutions of subproblems 
		int table[][] = new int[n][n]; 
		int gap, i, j, x, y, z; 

		// Fill table using above recursive formula. 
		// Note that the tableis filled in diagonal 
		// fashion (similar to http://goo.gl/PQqoS), 
		// from diagonal elements to table[0][n-1] 
		// which is the result. 
		for ( gap = 0 ; gap < n ; ++gap ) { 
			for ( i = 0, j = gap ; j < n ; ++i, ++j ) { 

				// Here x is value of F(i+2, j), 
				// y is F(i+1, j-1) and z is 
				// F(i, j-2) in above recursive formula 
				x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
				y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
				z = (i <= (j - 2)) ? table[i][j - 2] : 0; 

				table[i][j] = Math.max(arr[i] + Math.min(x, y), 
									arr[j] + Math.min(y, z)); 
			} 
		} 

		return table[0][n - 1]; 
	} 

	// Driver program 
	public static void main(String[] args) 
	{ 
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the size of array : ");
		// n will store the size of array
		int n=sc.nextInt();
		int arr[]=new int[n];

		for( int i = 0 ; i < n ; i++ ){
			arr[i] = sc.nextInt();
		}
		System.out.println("" + optimalStrategyOfGame(arr, n)); 
	} 
} 

/*
Input for test case 1:
4     // n = 4
8     //input taken in array
15
3
7
Output for test case 1:
22
*/
/*
Input for test case 2:
4     // n = 4
2     //input taken in array
2
2
2
Output for test case 2:
4
*/
/*
Input for test case 3:
6     // n = 6
20    //input taken in array
30
2
2
2
10
Output for test case 3:
42
*/
