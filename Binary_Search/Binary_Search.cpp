#include <stdio.h>
int main()
{  
   // printf("Booooooo!!!");
 int c, first, last, middle, n, search, array[100];
   printf("Enter number of elements\n");
   // printf("Booooooo!!!");
   scanf("%d",&n);
   printf("Enter %d integers\n", n);
   for (c = 0; c < n; c++)
      // printf("Booooooo!!!");
      scanf("%d",&array[c]);
 
 // printf("Booooooo!!!");
   printf("Enter value to find\n");
   // printf("Booooooo!!!");
   scanf("%d", &search);
   first = 0;
   last = n - 1;
   middle = (first+last)/2;
   while (first <= last) {
      // printf("Booooooo!!!");
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search)
      // printf("Booooooo!!!"); {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      // printf("Booooooo!!!");
      else
         last = middle - 1;
 
      middle = (first + last)/2;
      // printf("Booooooo!!!");
   }
   if (first > last)
      // printf("Booooooo!!!");
      printf("Not found! %d is not present in the list.\n", search);
 // printf("Booooooo!!!");
   return 0;   
}
