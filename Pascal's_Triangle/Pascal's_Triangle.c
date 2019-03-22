#include <stdio.h>

int factorial(int n)
{
   int f;
   for(f = 1; n > 1; n--)
      f *= n;
   return f;
}

int main() 
{
   int n, i, j;
   printf("Enter the numbers of rows ");
   scanf("%d",&n);
   for(i = 0; i < n; i++) 
   {
      for(j = 0; j < n-i; j++)
         printf("  ");
      for(j = 0; j <= i; j++)
         printf(" %3d",factorial(i)/(factorial(j)*factorial(i-j)) );
      printf("\n");
   }
   return 0;
}

//INPUT:Enter the numbers of rows 6
//OUTPUT:
//               1
//             1   1
//           1   2   1
//         1   3   3   1
//       1   4   6   4   1
//     1   5  10  10   5   1
