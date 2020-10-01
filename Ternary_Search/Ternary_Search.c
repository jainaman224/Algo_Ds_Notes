# include <stdio.h> 

//Function for Ternary Search
int Ternary_Search(int array[], int left, int right, int find)
{
   if (right >= left)
   {
        int mid1 = left + (right - left) / 3;
        int mid2 = mid1 + (right - left) / 3;

        // If x is present at the mid1
        if (array[mid1] == find)
            return mid1;

        // If x is present at the mid2
        if (array[mid2] == find)
            return mid2;

        // If x is present in left one-third
        if (array[mid1] > find)
            return Ternary_Search(array, left, mid1 - 1, find);

        // If x is present in right one-third
        else if (array[mid2] < find)
            return Ternary_Search(array, mid2 + 1, right, find);
        else
        // If x is present in middle one-third
        return Ternary_Search(array, mid1 + 1, mid2 - 1, find);
   }
   // We reach here when element is not present in array
   return -1;
}

int main()
{
    int n;
    printf ("Enter the number of elements : ") ;
    scanf ("%d", &n);
    int array[n];
    printf ("Enter the elements : \n");
    for (int i = 0; i < n; i++)
        scanf ("%d", &array[i]);

    printf ("Enter the element that you want to search: ");
    int find ;
    scanf ("%d", &find);

    if(Ternary_Search(array, 0, n, find) != 1)
        printf( "Found \n" );
    else
        printf( "Not Found" );    

    return 0;
}

/*
Enter the number of elements : 5
Enter the elements :
2
9
7
5
4
Enter the element that you want to search: 5
Found
*/
