#include <stdio.h>

int factorial(int num)
{
   int fact;
   for(fact = 1; num > 1; num--)
      fact *= num;
   return fact;
}

int main() 
{
   int num, i, j;
   printf("Enter the numbers of rows ");
   scanf("%d",&num);
   
   for(i = 0; i < num; i++) 
   {
      for(j = 0; j < num-i; j++)
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
