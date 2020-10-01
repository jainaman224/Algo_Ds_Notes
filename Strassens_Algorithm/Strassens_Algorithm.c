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

#include<stdio.h>
void main()
{
	//int a, b, c, d , e, f, g;
        int FirstMatrix[2][2], SecondMatrix[2][2], ProductMatrix[2][2], i, j;
        //First matrix elements input:
      	printf("Enter the 4 elements of first matrix: ");

      	for(i = 0;i < 2; i++)
	{
        	for(j = 0;j < 2; j++)
		{

                	scanf("%d", &FirstMatrix[i][j]);
		}
	}
     
	//Second matrix elements input:
      	printf("Enter the 4 elements of second matrix: ");

      	for(i = 0; i < 2; i++)
	{
          	for(j = 0;j < 2; j++)
		{
	               scanf("%d", &SecondMatrix[i][j]);
		}
	}
    

     
	//As per the algorithm
      	int a= (FirstMatrix[0][0] + FirstMatrix[1][1]) * (SecondMatrix[0][0] + SecondMatrix[1][1]);
	int b= (FirstMatrix[1][0] + FirstMatrix[1][1]) * SecondMatrix[0][0];
	int c= FirstMatrix[0][0] * (SecondMatrix[0][1] - SecondMatrix[1][1]);
	int d= FirstMatrix[1][1] * (SecondMatrix[1][0] - SecondMatrix[0][0]);
	int e= (FirstMatrix[0][0] + FirstMatrix[0][1]) * SecondMatrix[1][1];
	int f= (FirstMatrix[1][0] - FirstMatrix[0][0]) * (SecondMatrix[0][0]+SecondMatrix[0][1]);
	int g= (FirstMatrix[0][1] - FirstMatrix[1][1]) * (SecondMatrix[1][0]+SecondMatrix[1][1]);

     

      	ProductMatrix[0][0] = a + d- e + g;
	ProductMatrix[0][1] = c + e;
	ProductMatrix[1][0] = b + d;
      	ProductMatrix[1][1] = a - b + c + f;

     

        printf("\nAfter multiplication using Strassen's algorithm \n");

       	for(i = 0; i < 2 ; i++){

        	printf("\n");

          	for(j = 0;j < 2; j++){

               		printf("%d\t", ProductMatrix[i][j]);

       		}
	}

     	printf("\n");

}
/*
OUTPUT
--------------------------------------------------- 
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
