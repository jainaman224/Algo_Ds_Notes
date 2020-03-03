#include<stdio.h>

void main()
{ 
 int A[100][100],B[100][100],C[100][100],m,n,i,j;
 printf("Enter order of matrices:");
 scanf("%d %d",&m,&n);
 //take input for both matrices.
 printf("ENTER elements of A:");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&A[i][j]);
  }
 }
 printf("ENTER elements of B:");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&B[i][j]);
  }
 }
 //add corresponding terms of both matrices and intialise to the third matrix.
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {  
   C[i][j]=A[i][j]+B[i][j];
  }
 }
 //print the resultant matrix.
 printf("Resultant Matrix is \n");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   printf("%d \t",C[i][j]);
  }
  printf("\n"); 
 }
}
//sample input:
/*Enter order of matrices:2 3
ENTER elements of A:12 34 13 56 7 3
ENTER elements of B:1 45 23 98 100 2
Resultant Matrix is 
13 	79 	36 	
154 	107 	5 	*/
