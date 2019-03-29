/* C Program to sort a matrix */



#include <stdio.h>
 
int main () 
{
    
	static int ma[10][10],mb[10][10];
 
	int i,j,k,a,m,n;
 
	printf ("Enter the order of the matrix \n");
 
	scanf ("%d %d", &m,&n);
 
	printf ("Enter co-efficients of the matrix \n");
 
	for (i=0;i<m;++i) {
 
		for (j=0;j<n;++j) {
 
			scanf ("%d",&ma[i][j]);
 
			mb[i][j] = ma[i][j];
 
		}
 
	}
 
	printf ("The given matrix is \n");
 
	for (i=0;i<m;++i) {
 
		for (j=0;j<n;++j) {
 
			printf (" %d",ma[i][j]);
 
		}
 
		printf ("\n");
 
	}
 
	printf ("After arranging rows in ascending order\n");
 
	for (i=0;i<m;++i) {
 
		for (j=0;j<n;++j) {
 
			for (k=(j+1);k<n;++k) {
 
				if (ma[i][j] > ma[i][k]) {
 
					a = ma[i][j];
 
					ma[i][j] = ma[i][k];
 
					ma[i][k] = a;
 
				}
 
			}
 
		}
 
	}
 
	/* End of outer for loop*/
 
	for (i=0;i<m;++i) {
 
		for (j=0;j<n;++j) {
 
			printf (" %d",ma[i][j]);
 
		}
 
		printf ("\n");
 
	}
 
	printf ("After arranging the columns in descending order \n");
 
	for (j=0;j<n;++j) {
 
		for (i=0;i<m;++i) {
 
			for (k=i+1;k<m;++k) {
 
				if (mb[i][j] < mb[k][j]) {
 
					a = mb[i][j];
 
					mb[i][j] = mb[k][j];
 
					mb[k][j] = a;
 
				}
 
			}
 
		}
 
	}
 
	/* End of outer for loop*/
 
	for (i=0;i<m;++i) {
 
		for (j=0;j<n;++j) {
 
			printf (" %d",mb[i][j]);
 
		}
 
		printf ("\n");
 
	}
 
}
/*
Input:
Enter the order of the matrix
2 3
Enter co-efficients of the matrix
1
6
4
8
9
7
Output:
The given matrix is
 1 6 4
 8 9 7
After arranging rows in ascending order
 1 4 6
 7 8 9
After arranging the columns in descending order
 8 9 7
 1 6 4
*/


