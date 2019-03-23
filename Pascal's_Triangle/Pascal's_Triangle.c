#include <stdio.h>

int factorial(int no)
{
   int fact;
   for(fact = 1; no > 1; no--)
      fact *= no;
   return fact;
}

int main() 
{
   int no, i, j;
   printf("Enter the numbers of rows ");
   scanf("%d",&no);
   
   for(i = 0; i < no; i++) 
   {
      for(j = 0; j < no-i; j++)
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
