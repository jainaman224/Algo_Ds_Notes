//selection sort 

import 'dart:io';

void selection_sort (List<int> arr, int n)
{
    int temp, min_index;
    
    for (int i = 0 ; i  < n - 1 ; i++)
    {
        min_index = i;
        
        for (int j = i + 1 ; j < n ; j++)
            if ( arr[j] < arr[min_index] )
                 min_index = j;
            
        if (i != min_index)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    } 
}

main()
{
    print ("Enter the size of array ");
    int size = int.parse (stdin.readLineSync());
    
    List <int> array = List();
    
    for (int i = 0; i < size; i++)
    {
        print ("Enter $i element ");
        var ele = int.parse (stdin.readLineSync());
        array.add (ele);
    }
   
    selection_sort (array, size);
    
    print (array);

}

/*
Enter the size of array 
5
Enter 0 element 
50
Enter 1 element
40
Enter 2 element 
30
Enter 3 element
20
Enter 4 element 
10
Sorted array is
[10, 20, 30, 40, 50]
*/
Selection_Sort/Selection_Sort.dart
