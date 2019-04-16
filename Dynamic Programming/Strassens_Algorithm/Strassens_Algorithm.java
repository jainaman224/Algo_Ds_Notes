//Strassen's Algorithm for matrix multiplication
/*
In linear algebra, the Strassen algorithm, named after Volker Strassen, is an algorithm for matrix multiplication. It is faster than the standard matrix multiplication algorithm and is useful in practice for large matrices, but would be slower than the fastest known algorithms for extremely large matrices.

*/
/*

    AHED (Learn it as ‘Ahead’)
    Diagonal
    Last CR
    First CR

    Also, consider X as (Row +) and Y as (Column -) matrix
------*Step 1*---------
P1 = A
P2= H
P3= E
P4= D
P5= ( A + D ) * ( E + H )
----------*Step 2*--------------
P1 = A
P2= H
P3= E
P4= D
P5= ( A + D ) * ( E + H )
P6= ( B – D ) * ( G + H)
P7= ( A – C ) * ( E + F)
----------*Step 3*--------------
P1 = A * ( F – H)
P2= H
P3= E
P4= D
P5= ( A + D ) * ( E + H )
P6= ( B – D ) * ( G + H)
P7= ( A – C ) * ( E + F)

----------*Step 4*--------------
P1= A * ( F – H )
P2= H * ( A + B )
P3= E * ( C + D )
P4= D
P5= ( A + D ) * ( E + H )
P6= ( B – D ) * ( G + H)
P7= ( A – C ) * ( E + F)


*/
//Main function is at line 161     

import java.util.Scanner;

public class Strassens_Algorithm

{

	public int[][] algorithm(int[][] FirstMatrix, int[][] SecondMatrix)
	{        
		int n = FirstMatrix.length;
                int[][] Result = new int[n][n];


	        if (n == 1)
                	Result[0][0] = FirstMatrix[0][0] * SecondMatrix[0][0];
            	else
            	{

                	int[][] FirstMatrix11 = new int[n/2][n/2];
                	int[][] FirstMatrix12 = new int[n/2][n/2];
                	int[][] FirstMatrix21 = new int[n/2][n/2];
                	int[][] FirstMatrix22 = new int[n/2][n/2];
                	int[][] SecondMatrix11 = new int[n/2][n/2];
                	int[][] SecondMatrix12 = new int[n/2][n/2];
                	int[][] SecondMatrix21 = new int[n/2][n/2];
                	int[][] SecondMatrix22 = new int[n/2][n/2];
                	/** Dividing matrix A into 4 halves **/
                	split(FirstMatrix, FirstMatrix11, 0 , 0);
                	split(FirstMatrix, FirstMatrix12, 0 , n/2);
                	split(FirstMatrix, FirstMatrix21, n/2, 0);
                	split(FirstMatrix, FirstMatrix22, n/2, n/2);

                	/** Dividing matrix B into 4 halves **/

                	split(SecondMatrix, SecondMatrix11, 0 , 0);
                	split(SecondMatrix, SecondMatrix12, 0 , n/2);
                	split(SecondMatrix, SecondMatrix21, n/2, 0);
                	split(SecondMatrix, SecondMatrix22, n/2, n/2);

     


     

                	int [][] a = algorithm(add(FirstMatrix11, FirstMatrix22), add(SecondMatrix11, SecondMatrix22));
                	int [][] b = algorithm(add(FirstMatrix21, FirstMatrix22), SecondMatrix11);
                	int [][] c = algorithm(FirstMatrix11, sub(SecondMatrix12, SecondMatrix22));
                	int [][] d = algorithm(FirstMatrix22, sub(SecondMatrix21, SecondMatrix11));
                	int [][] e = algorithm(add(FirstMatrix11, FirstMatrix12), SecondMatrix22);
                	int [][] f = algorithm(sub(FirstMatrix21, FirstMatrix11), add(SecondMatrix11, SecondMatrix12));
                	int [][] g = algorithm(sub(FirstMatrix12, FirstMatrix22), add(SecondMatrix21, SecondMatrix22));

     


                	int [][] product11 = add(sub(add(a, d), e), g);
                	int [][] product12 = add(c, e);
                	int [][] product21 = add(b, d);
                	int [][] product22 = add(sub(add(a, c), b), f);

     


                	join(product11, Result, 0 , 0);
                	join(product12, Result, 0 , n/2);
                	join(product21, Result, n/2, 0);
                	join(product22, Result, n/2, n/2);

            	}

  

            	return Result;

	}

        public int[][] sub(int[][] FirstMatrix, int[][] SecondMatrix)
        {

		int n = FirstMatrix.length;
            	int[][] DifferenceMatrix = new int[n][n];
            	for (int i = 0; i < n; i++)
                	for (int j = 0; j < n; j++)
                    		DifferenceMatrix[i][j] = FirstMatrix[i][j] - SecondMatrix[i][j];
            	return DifferenceMatrix;
        }

        public int[][] add(int[][] FirstMatrix, int[][] SecondMatrix)
        {
		int n = FirstMatrix.length;
            	int[][] SumMatrix = new int[n][n];
            	for (int i = 0; i < n; i++)
                	for (int j = 0; j < n; j++)
                    		SumMatrix[i][j] = FirstMatrix[i][j] + SecondMatrix[i][j];
            	return SumMatrix;
        }

        public void split(int[][] ParentMatrix, int[][] ChildMatrix, int isplit, int jsplit) 
        {
		for(int i1 = 0, i2 = isplit; i1 < ChildMatrix.length; i1++, i2++)
                	for(int j1 = 0, j2 = jsplit; j1 < ChildMatrix.length; j1++, j2++)
                    		ChildMatrix[i1][j1] = ParentMatrix[i2][j2];
        }

        public void join(int[][] ChildMatrix, int[][] ParentMatrix, int ijoin, int jjoin) 

        {
        	for(int i1 = 0, i2 = ijoin; i1 < ChildMatrix.length; i1++, i2++)
                	for(int j1 = 0, j2 = jjoin; j1 < ChildMatrix.length; j1++, j2++)
                    		ParentMatrix[i2][j2] = ChildMatrix[i1][j1];
        }    

        /** Main function **/

        public static void main (String[] args) 
	{
        	Scanner scan = new Scanner(System.in);
            	Strassens_Algorithm s = new Strassens_Algorithm();
            	System.out.println("Enter order of matrixes :");
            	int N = scan.nextInt();

            	System.out.println("Enter "+N*N+" elements of first matrix:\n");

            	int[][] A = new int[N][N];

            	for (int i = 0; i < N; i++)
                	for (int j = 0; j < N; j++)
                    		A[i][j] = scan.nextInt();
     
            	System.out.println("Enter "+N*N+" elements of second matrix:\n");
            	int[][] B = new int[N][N];

            	for (int i = 0; i < N; i++)
                	for (int j = 0; j < N; j++)
                    		B[i][j] = scan.nextInt();
            	int[][] product = s.algorithm(A, B);
                System.out.println("\nProduct of matrices A and  B : ");

            	for (int i = 0; i < N; i++)
		{
                	for (int j = 0; j < N; j++)
                    		System.out.print(product[i][j] +" ");
                		System.out.println();
            	}
        }

}

/*
/*
OUTPUT
--------------------------------------------------- 
Enter order of matrixes : 2

Enter the 4 elements of first matrix:
1 2
3 4
Enter the 4 elements of second matrix: 
5 6 
7 8	
After multiplication using Strassen's algorithm
 
19	22	
43	50
---------------------------------------------------
*/
