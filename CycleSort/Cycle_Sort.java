
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
       int n;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter no. of elements you want in array:");
        n = s.nextInt();
        int a[] = new int[n];
        System.out.println("Enter all the elements:");
        for(int i = 0; i < n; i++)
            a[i] = s.nextInt();
        sort (a, n);
        System.out.println ("After sort, array : ");
        for (int j = 0; j < n; j++)
            System.out.println (a[j]);
    }
}

/*Output:
Enter no. of elements you want in array:5                                                                                 
Enter all the elements:                                                                                                   
12                                                                                                                        
45                                                                                                                        
-7                                                                                                                        
0                                                                                                                         
10                                                                                                                        
After sort, array :                                                                                                       
-7                                                                                                                        
0                                                                                                                         
10                                                                                                                        
12                                                                                                                        
45 */
