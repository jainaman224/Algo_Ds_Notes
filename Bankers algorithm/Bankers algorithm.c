#include <stdio.h> 
int main() 
{ 

	int n, m, i, j, k; 
	printf("Enter the No of Processes\n");
	scanf("%d",&n);

	printf("Enter the No of Resources\n");
	scanf("%d",&m);

	int alloc[n][m];
	int max[n][m];

	printf("Enter the Allocation Matrix\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}

	printf("Enter the Max Matrix\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}	
	
	int avail[m];
	printf("Enter the Avail Vector\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}	

	int f[n], ans[n], ind = 0; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][m]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	printf("The Need Matrix is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d\t",need[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (j = 0; j < m; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < m; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 
	printf("Following is the SAFE Sequence\n"); 
	for (i = 0; i < n - 1; i++) 
		printf(" P%d ->", ans[i]); 
	printf(" P%d", ans[n - 1]); 
	printf("\n");
	
	printf("\n The Available Matrix : \n");
	for(i=0;i<m;i++)
	{
		printf("%d \t",avail[i]);
	}

return (0); 

} 

// ---------------- Result ------------------

// Enter the No of Processes
// 5
// Enter the No of Resources
// 3
// Enter the Allocation Matrix
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2
// Enter the Max Matrix
// 7 5 3
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 2
// Enter the Avail Vector
// 3 3 2
// The Need Matrix is
// 7   4   3
// 1   2   2
// 6   0   0
// 0   1   1
// 4   3   0

// Following is the SAFE Sequence
//  P1 -> P3 -> P4 -> P0 -> P2

//  The Available Matrix :
// 10  5   7  