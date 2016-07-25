                                                                     /*DESCRIPTION*/

/*Let us define the problem as trying determine the order of multiplication M1*M2*M3*...*Mn using parentheses to denote the order.

  So the basic way to look at this problem in a Dynamic Programming fashion is as follows:-

- We can separate this multiplication into two sets (M1*M2*...*Mj) * (M(j+1)*...*Mn). Thus, the solution at this level comes down to how to choose j to minimize the
  cost of multiplication.In this case, we would choose j so that M(j+1) is the matrix with the smallest number of rows)

 -But, to brute-force this, we need to know how to optimally parentesize each of the sub multiplication chains. Thus, we have a smaller problem at hand.
  This goes iteratively downwards till we have only two matrices within brackets, at which point we can calculate the flops required directly.

- We now have a big recursive solution at hand where many solutions need to be recalculated,

  eg. for A1*...*A5 given in book, we have these 5 possible solutions
(A1 (A2 (A3 A4))) ,
(A1 ((A2 A3) A4)) ,
((A1 A2) (A3 A4)) ,
((A1 (A2 A3)) A4) ,
(((A1 A2) A3) A4).

You can see that the cost of A3*A4 is required for the calculation of the overall cost in both the first and third solution. It makes sense to store the
cost of A3*A4 when we first calculate it so that it need not be recalculated. For larger matrix chains, we can store the overall minimal cost directly and
retrieve it from memory(n^2 table)(this is memorization). Thus, we don't need to go down the recursion the second time.
*/

/*The technique we have used is called Memorization*/


                                                          /*SOURCE CODE*/

#include <iostream>
#include <cstdlib>
#include <limits.h>

#define SZ 10

using namespace std;

int table[SZ][SZ];

int P[] = {10, 20, 30, 40, 30};

int MCM(int i, int j)
{
    if(i == j)
        return 0;

    int min = INT_MAX;

    for(int k = i; k < j; k++)
    {
	    if(table[i][k] == 0)
			table[i][k] = MCM(i, k);

		if(table[k+1][j] == 0)
			table[k+1][j] = MCM(k+1, j);

		int sum = table[i][k] + table[k+1][j] + P[i-1] * P[j] * P[k];
	    if(sum < min)
	       min = sum;
    }

	table[i][j] = min;
	return min;
}

int main()
{
    int size = sizeof(P)/sizeof(P[0]);

	cout << "Minimum number of mutiplications is " << MCM(1, size-1);

	return 0;
}


                                                                    /*OUTPUT DESCRIPTION*/
/*
              P = {10, 20, 30, 40, 30},
              dimensions of matrix [1] = 10X20,
              dimensions of matrix [2] = 20X30,
              dimensions of matrix [3] = 30X40,
              dimensions of matrix [4] = 40X30


         This is how table[][] matrix will look like

                0 6000 18000 30000
                0 0    24000 48000
                0 0    0     36000
                0 0    0     0

                                     ,where table[1][size-1]=30000 is the answer.
*/
