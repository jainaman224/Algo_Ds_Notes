/* 
Cycle Sort
Cycle sort is a comparison based sorting algorithm which forces array to be factored into 
the number of cycles where each of them can be rotated to produce a sorted array.
It is an in-place and unstable sorting algorithm. 
Best and Average case time complexity:O(n^2)


Algorithm
An element a is given, index of a can be calculated by counting the number of elements that 
are smaller than a.
1. If the element is found to be at its correct position, simply leave it as it is.
2. Otherwise, find the correct position of a by counting the total number of elements that are 
less than a. where it must be present in the sorted array. The other element b which is replaced is 
to be moved to its correct position. This process continues until we got an element at the 
original position of a. */

import java.io.*;
import java.util.*;

public class CycleSort
{
    static void sort (int a[], int n)
    {
        int writes = 0, start, element, pos, temp, i;
        // Find position where we put the element.
        for (start = 0; start <= n - 2; start++)
        {
            element = a[start];
            pos = start;
           /*Find position where we put the element. We basically 
           count all smaller elements on right side of element. */
           for (i = start + 1; i < n; i++)
           if (a[i] < element)
                pos++;
            // If element is already in correct position     
            if (pos == start)
                continue;
            // ignore all duplicate elements      
            while (element == a[pos])
                pos += 1;
            // put the element to it's right position
            if (pos != start) {
                temp = element;
                element = a[pos];
                a[pos] = temp;
                writes++;
            }
           // Rotate rest of the cycle  
            while (pos != start) 
            {
                pos = start;
                for (i = start + 1; i < n; i++)
                  if (a[i] < element)
                    pos += 1;
                // ignore all duplicate elements 
                while (element == a[pos])
                    pos += 1;
                // put the item to it's right position 
                if (element != a[pos]) {
                    temp = element;
                    element = a[pos];
                    a[pos] = temp;
                    writes++;
                }
            }
        }
    }
    
    public static void main (String[]args)
    {
        int a[] = { 12, 2, 1, 9, -4, 2, 4, 4 };
        int n = a.length, i;
        sort (a, n);
        System.out.println ("After sort, array : ");
        for (i = 0; i < n; i++)
        System.out.println (a[i]);
    }
}
