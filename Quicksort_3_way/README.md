3-Way Quicksort


What is Quicksort?
Quicksort is a method of sorting in which a pivot element is picked and the array is partioned according to this element.It is a divide and conquer algorithm. It divides the array in two parts, the left of pivot element has elements lesser than the pivot element and the right side has elements greater than the pivot element.


What is 3-Way Quicksort?
3-Way quicksort is nearly same as quicksort. The only difference is that the elements are divided into three parts:-
1. Less than pivot element
2. Greater than pivot element
3. Equal to pivot element
The idea of 3 way QuickSort is to process all occurrences of pivot and is based on Dutch National Flag algorithm.

Example:-
If the given array is {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4 ,5} Let's take the pivot element as 4. Then the array will be partioned into 3 parts i.e- less than 4 (1,2,2,1,2,1,2,2,2,2,1), equal to 4 (4,4,4,4,4,4,4,4) and greater than 4 (5).


Pseudocode

/* i-->starting index-1, j-->end index

p=i, q=j
while(true)
    {
        while(array[++i] < pivot) {} //i increases if element is less than pivot

        while(pivot < array[--j]) //j decreases if element is greater than pivot
        {
              if (j == left) break;
        }

        if(i >= j) break;
        swap(array[i], array[j]);

        if(array[i] == pivot) //We bring pivot element duplicates to the beginning of array
        {
            p++;
            swap(array[p], array[i]);
        }

        if(array[j] == pivot) //We bring pivot element duplicates to the end of array
        {
            q--;
            swap(array[j], array[q]);
        }
    }

    swap(array[i], array[right]);
    j = i - 1;
    i = i + 1;

    for(int k = left; k < p; k++, j--) 
        swap(array[k], array[j]);

    for(int k = right - 1; k > q; k--, i++) //Bringing pivot element and its duplicates to the correct position
        swap(array[i], array[k]);

    Quick_Sort_3way(array, left, j); //Sorting elements on the left of pivot
    Quick_Sort_3way(array, i, right); //Sorting elements on the right of pivot

Refer:- https://learnforeverlearn.com/pivot_3way_music/  for explanation


Properties of 3-Way Quicksort

It is not stable.
It uses O(log(n)) extra space because of the recursion.
Worst case run time is as same as classic quicksort, O(n2), but typically O(nlog(n)) time


Time Complexity:- O(n^2)
