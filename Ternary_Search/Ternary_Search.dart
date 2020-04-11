import 'dart:io';
import 'dart:math';

int Ternary_Search(array, left ,right, desired)
{
    if(right >= left)
    {
        int mid1 = left + ((right - left) / 3).floor();
        int mid2 = mid1 + ((right - left) / 3).floor();

        // If the desired element is present at the mid1
        if(array[mid1] == desired)
            return mid1;

        // If the desired element is present at the mid2
        if(array[mid2] == desired)
            return mid2;

        // If the desired element is present in left one-third
        if(array[mid1] > desired)
            return Ternary_Search(array, left, mid1 - 1, desired);

        // If the desired element is present in right one-third
        if(array[mid2] < desired)
            return Ternary_Search(array, mid2 + 1, right, desired);

        // If the desired element is present in middle one-third
        return Ternary_Search(array, mid1 + 1, mid2 - 1, desired);
   }

    // We reach here when element is not present in array
    return -1;
}

void main()
{
    String x, y, z;
    List L = [];

    //Take input from the user for numbers of elements in the array
    print("Enter the number of elements: ");
    z = stdin.readLineSync();
    int n = int.parse(z);

    //Take input of every element from the user
    print("Enter the elements: ");
    for(int i = 0; i < n; i++)
    {
        x = stdin.readLineSync();
        L.add(int.parse(x)); 
    }

    //Take input of the desired element to be searched
    print("Enter the desired element to be searched: ");
    y = stdin.readLineSync();
    int desired = int.parse(y);

    //Applying Ternary Search
    if(Ternary_Search(L, 0, n - 1, desired) == -1)
    {
        print("Not Found");
    }
    else
    {
        print("Found");
    }
}

/* 
Input
Number of elements = 7
array = [1,2,3,4,5,6,7]
Desired element = 6

Output
Found
*/


/* 
Input
Number of elements = 7
array = [1,2,3,4,5,6,7]
Desired element = 9

Output
Not Found
*/
